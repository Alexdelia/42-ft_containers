/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:48:44 by adelille          #+#    #+#             */
/*   Updated: 2022/02/28 19:25:02 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>
# include <iomanip>

# include "pair.hpp"
# include "reverse_iterator.hpp"
# include "tree_iterator.hpp"

# define RED	true
# define BLACK	false

// https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/
// https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/
// https://www.programiz.com/dsa/red-black-tree

namespace ft
{
	template <class T>
		struct _rb_node
		{
			typedef T	value_type;
			_rb_node	*parent;
			_rb_node	*left;
			_rb_node	*right;
			bool		color;
			T			data;
			_rb_node(T const &data) : data(data) {}
		};

	template <class T, class Compare, class Allocator = std::allocator<_rb_node<T> > >
		class _rb_tree
		{
			public:
				typedef T										value_type;
				typedef size_t									size_type;
				typedef Compare									compare;
				typedef Allocator								allocator;
				typedef _rb_node<value_type>					node;
				typedef node									*node_ptr;
				typedef std::ptrdiff_t							difference_type;
				typedef ft::tree_iterator<node>					iterator;
				typedef ft::tree_iterator<node>					const_iterator;
				typedef ft::reverse_iterator<iterator>			reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			private:
				node_ptr	root;
				node_ptr	NIL;
				compare		_compare;
				allocator	_alloc;
				size_type	_size;

			public:
				_rb_tree(allocator alloc = allocator())
					: _compare(compare()), _size(0)
				{
					_alloc = alloc;

					NIL = _alloc.allocate(1);
					_alloc.construct(NIL, value_type());
					NIL->parent = NIL;
					NIL->left = NIL;
					NIL->right = NIL;
					NIL->color = BLACK;
					root = NIL;
				}

				_rb_tree(_rb_tree const &other)
				{
					_alloc = other._alloc;
					_compare = other._compare;
					_size = other._size;
					NIL = _alloc.allocate(1);
					NIL->parent = NIL;
					NIL->left = NIL;
					NIL->right = NIL;
					NIL->color = BLACK;

					root = NIL;
					other.print();
					_recursive_copy(*this, other.root, other.NIL);
				}

				~_rb_tree()
				{
					clear();
					_alloc.destroy(NIL);
					_alloc.deallocate(NIL, 1);
				}

				_rb_tree	&operator=(_rb_tree const &other)
				{
					clear();
					_recursive_copy(*this, other.root, other.NIL);
					return *this;
				}

				iterator	find(value_type const &value)
				{
					node_ptr	found = _find_node(value);

					if (!found)
						return (end());
					else
						return (iterator(found, root, NIL));
				}

				const_iterator	find(value_type const &value) const
				{
					node_ptr	found = _find_node(value);

					if (!found)
						return (end());
					else
						return (iterator(found, root, NIL));
				}

				ft::pair<iterator, bool>	insert(value_type const &value)
				{
					node_ptr	n = _new_node(value);
					ft::pair<node_ptr, bool>	r = _insert_recursive(root, n);

					if (r.second)
					{
						_size++;
						if (n->parent == NIL)
							n->color = BLACK;
						else
							_insert_fixup(n);
						root = n;
						while (root->parent != NIL)
							root = root->parent;
						return (ft::make_pair(iterator(n, root, NIL), true));
					}
					else
					{
						_alloc.destroy(n);
						_alloc.deallocate(n, 1);
						return (ft::make_pair(iterator(r.first, root, NIL), false));
					}
				}

				iterator	insert(iterator hint, const value_type &value)
				{
					node_ptr	next = _next(hint.node);

					if (_compare(*hint, value) && _compare(value, next->data))
					{
						node_ptr	n = _new_node(value);
						ft::pair<node_ptr, bool>	r = _insert_recursive(hint.node, n);

						_size++;
						return (iterator(r.first, root, NIL));
					}
					else
						return (insert(value).first);
				}

				size_type	erase(value_type const &value)
				{
					node_ptr	n = _find_node(value);

					if (n)
					{
						_delete_node(n);
						return (1);
					}
					else
						return (0);
				}

				void	erase(iterator pos)
				{
					if (pos.node != NIL)
						_delete_node(pos.node);
				}

				void	clear()
				{
					_recursive_clear(root);
					root = NIL;
					_size = 0;
				}

				size_type	size() const
				{return (_size);}
				size_type	max_size() const
				{return (_alloc.max_size());}

				void	swap(_rb_tree &other)
				{
					std::swap(_alloc, other._alloc);
					std::swap(_compare, other._compare);
					std::swap(_size, other._size);
					std::swap(NIL, other.NIL);
					std::swap(root, other.root);
				}

				iterator	lower_bound(const value_type &value)
				{
					for (iterator it = begin(); it != end(); ++it)
					{
						if (_compare(value, it.node->data)
								|| _compare(it.node->data, value) == 0)
							return (it);
					}
					return (end());
				}

				const_iterator	lower_bound(const value_type &value) const
				{
					for (iterator it = begin(); it != end(); ++it)
					{
						if (_compare(value, it.node->data)
								|| _compare(it.node->data, value) == 0)
							return (it);
					}
					return (end());
				}

				iterator	upper_bound(const value_type &value)
				{
					for (iterator it = begin(); it != end(); ++it)
					{
						if (_compare(value, it.node->data))
							return (it);
					}
					return (end());
				}

				const_iterator	upper_bound(const value_type &value) const
				{
					for (iterator it = begin(); it != end(); ++it)
					{
						if (_compare(value, it.node->data))
							return (it);
					}
					return (end());
				}

				void	print(node *p = NULL, int indent = 0) const
				{
					if (p == NULL)
						p = root;
					if (p != NIL)
					{
						if (p->right != NIL)
						{
							print(p->right, indent + 4);
						}
						if (indent)
						{
							std::cout << std::setw(indent) << ' ';
						}
						if (p->right != NIL)
							std::cout << " /" << std::endl
								<< std::setw(indent) << ' ';
						if (p->color == RED)
							std::cout << "\033[0;31m";
						std::cout << p->data << std::endl << "\033[0m";
						if (p->left != NIL)
						{
							std::cout << std::setw(indent) << ' ' << " \\" << std::endl;
							print(p->left, indent + 4);
						}
					}
				}

				iterator	begin()
				{return (iterator(_minimum(root), root, NIL));}
				const_iterator	begin() const
				{return (const_iterator(_minimum(root), root, NIL));}
				iterator	end()
				{return (iterator(NIL, root, NIL));}
				const_iterator	end() const
				{return (const_iterator(NIL, root, NIL));}
				reverse_iterator	rbegin()
				{
					iterator	it = end();
					return (reverse_iterator(it));
				}
				const_reverse_iterator	rbegin() const
				{
					const_iterator	it = end();
					return (const_reverse_iterator(it));
				}
				reverse_iterator	rend()
				{
					iterator	it = begin();
					return (reverse_iterator(it));
				}
				const_reverse_iterator	rend() const
				{
					const_iterator	it = begin();
					return (const_reverse_iterator(it));
				}

			private:
				//

		};
}

#endif
