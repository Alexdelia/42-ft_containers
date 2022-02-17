/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:48:44 by adelille          #+#    #+#             */
/*   Updated: 2022/02/17 11:02:22 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>
//# include <iomanip>

# include "pair.hpp"
# include "reverse_iterator.hpp"

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

		};
}

#endif
