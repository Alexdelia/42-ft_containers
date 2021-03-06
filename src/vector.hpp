/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:14:18 by adelille          #+#    #+#             */
/*   Updated: 2022/02/06 13:23:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

// https://cplusplus.com/reference/vector/vector/

# include <memory>
# include <iostream>
//# include <typeinfo>

# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"
# include "equal.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
		class vector
		{
			public:
				typedef T												value_type;
				typedef value_type*										pointer_type;
				typedef value_type&										reference_type;
				typedef Alloc											allocator_type;
				typedef typename allocator_type::size_type				size_type;
				typedef typename allocator_type::reference				reference;
				typedef typename allocator_type::const_reference		const_reference;
				typedef typename allocator_type::pointer				pointer;
				typedef typename allocator_type::const_pointer			const_pointer;
				typedef typename allocator_type::difference_type		difference_type;

				typedef ft::random_access_iterator<value_type>			iterator;
				typedef ft::random_access_iterator<value_type const>	const_iterator;
				typedef ft::reverse_iterator<iterator>					reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			private:
				allocator_type	_alloc;
				pointer			_array;
				size_type		_size;
				size_type		_capacity;

			public:

				// default (1)
				explicit vector (const allocator_type& alloc = allocator_type())
					: _alloc(alloc), _array(NULL), _size(0), _capacity(0) {};
				// fill (2)
				explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type())
					: _alloc(alloc), _array(NULL), _size(0), _capacity(0)
				{
					reserve(n);
					_size = n;
					_capacity = n;
					for (size_type i = 0; i < n; i++)
						_alloc.construct(&_array[i], val);
				};
				// range (3)
				template <class InputIterator>
					vector (InputIterator first, InputIterator last,
							const allocator_type& alloc = allocator_type(),
							typename ft::enable_if<!ft::is_integral<InputIterator>::value,
							InputIterator>::type* = NULL)
					: _alloc(alloc), _array(NULL), _size(0), _capacity(0)
					{
						size_type	n = std::distance(first, last);
						reserve(n);
						_size = n;
						_capacity = n;
						for (size_type i = 0; i < _size; i++)
							_alloc.construct(&_array[i], *(first + i));
					};
				// copy (4)
				vector (const vector& x)
					: _alloc(x._alloc), _array(NULL), _size(x._size), _capacity(x._capacity)
				{
					if (x._array)
					{
						_array = _alloc.allocate(_capacity);
						for (size_type i = 0; i < _size; i++)
							_alloc.construct(&_array[i], x._array[i]);
					}
				}

				// destructor
				virtual ~vector(void)
				{
					clear();
					if (_array)
						_alloc.deallocate(_array, _capacity);
				}

				// assign
				vector	&operator=(const vector &x)
				{
					if (this != &x)
					{
						clear();
						if (_capacity < x._size)
							reserve(x._size);
						_size = x._size;
						if (_array)
							_alloc.deallocate(_array, _capacity);
						if (x._array)
						{
							_array = _alloc.allocate(_capacity);
							for (size_type i = 0; i < _size; i++)
								_alloc.construct(&_array[i], x._array[i]);
						}
						else
							_array = NULL;
					}
					return (*this);
				}

				// iterators
				iterator	begin()
				{return (iterator(_array));}
				const_iterator	begin() const
				{return (const_iterator(_array));}
				iterator	end()
				{return (iterator(_array + _size));}
				const_iterator	end() const
				{return (const_iterator(_array + _size));}
				reverse_iterator	rbegin()
				{return (reverse_iterator(_array + _size));}
				const_reverse_iterator	rbegin() const
				{return (const_reverse_iterator(_array + _size));}
				reverse_iterator	rend()
				{return (reverse_iterator(_array));}
				const_reverse_iterator	rend() const
				{return (const_reverse_iterator(_array));}

				// capacity
				size_type	size(void) const
				{return (_size);}
				size_type	max_size(void) const
				{return (_alloc.max_size());}
				void	resize(size_type n, value_type val = value_type())
				{
					if (n > _capacity)
						reserve(n);
					if (n > _size)
					{
						for (size_type i = _size; i < n; i++)
							_alloc.construct(&_array[i], val);
						_size = n;
					}
					else if (n < _size)
					{
						for (size_type i = n; i < _size; i++)
							_alloc.destroy(&_array[i]);
						_size = n;
					}
				}
				size_type	capacity(void) const
				{return (_capacity);}
				bool	empty(void) const
				{return (_size == 0);}
				void	reserve(size_type n)
				{
					if (n > max_size())
						throw std::length_error("n is greater than max_size");
					if (n > _capacity)
					{
						value_type	*tmp = _alloc.allocate(n);

						for (size_type i = 0; i < _size; i++)
						{
							_alloc.construct(&tmp[i], _array[i]);
							_alloc.destroy(&_array[i]);
						}
						if (_array)
							_alloc.deallocate(_array, _capacity);
						_capacity = n;
						_array = tmp;
					}
				}

				// element access
				reference	operator[](size_type n)
				{return (_array[n]);}
				const_reference	operator[](size_type n) const
				{return (_array[n]);}
				reference	at(size_type n)
				{
					if (n >= _size)
						throw std::out_of_range("out of range");
					return (_array[n]);
				}
				const_reference	at(size_type n) const
				{
					if (n >= _size)
						throw std::out_of_range("out of range");
					return (_array[n]);
				}
				reference	front(void)
				{return (_array[0]);}
				const_reference	front(void) const
				{return (_array[0]);}
				reference	back(void)
				{return (_array[_size - 1]);}
				const_reference	back(void) const
				{return (_array[_size - 1]);}

				// modifiers
				template <class InputIterator>
					void	assign(InputIterator first, InputIterator last, 
							typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
					{
						size_type	n = std::distance(first, last);

						if (n > _capacity)
							reserve(n);
						for (size_type i = 0; i < _size; i++)
							_alloc.destroy(&_array[i]);
						for (size_type i = 0; i < n; i++)
							_alloc.construct(&_array[i], *first++);
						_size = n;
					}
				void	assign(size_type n, const value_type &val)
				{
					if (n > _capacity)
						reserve(n);
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(&_array[i]);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(&_array[i], val);
					_size = n;
				}
				void	push_back(const value_type &val)
				{
					if (_size == _capacity)
					{
						if (_capacity == 0)
							reserve(1);
						else
							reserve(_capacity * 2);
					}
					_alloc.construct(&_array[_size], val);
					_size++;
				}
				void	pop_back(void)
				{
					_alloc.destroy(&_array[_size - 1]);
					_size--;
				}
				iterator	insert(iterator position, const value_type &val)
				{
					size_type	i = &*position - &*begin();

					if (_size == _capacity)
					{
						if (_capacity == 0)
							reserve(1);
						else
							reserve(_capacity * 2);
					}
					_shift_right(i, 1);
					_alloc.construct(&_array[i], val);
					_size++;
					return (iterator(&_array[i]));
				}
				void	insert(iterator position, size_type n, const value_type &val)
				{
					size_type	i = &*position - &*begin();

					if (_size + n > _capacity)
						reserve(_size + n);
					_shift_right(i, n);
					for (size_type j = 0; j < n; j++)
						_alloc.construct(&_array[i + j], val);
					_size += n;
				}
				template <class InputIterator>
					void	insert(iterator position, InputIterator first, InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
					{
						size_type	i = &*position - &*begin();
						size_type	n = std::distance(first, last);

						if (_size + n > _capacity)
							reserve(_size + n);
						_shift_right(i, n);
						for (size_type x = 0; x < n; x++)
							_alloc.construct(&_array[i + x], *(first + x));
						_size += n;
					}
				iterator	erase(iterator position)
				{
					size_type i = &*position - &*begin();

					_alloc.destroy(&_array[i]);
					_shift_left(i, 1);
					_size--;
					return (iterator(&_array[i]));			
				}
				iterator	erase(iterator first, iterator last)
				{
					size_type	x = &*first - &*begin();
					size_type	y = &*last - &*begin();

					for (size_type z = x; z < y; z++)
						_alloc.destroy(&_array[z]);
					_shift_left(x, y - x);
					_size -= y - x;
					return (iterator(&_array[x]));
				}
				void	swap(vector &x)
				{
					std::swap(_array, x._array);
					std::swap(_size, x._size);
					std::swap(_capacity, x._capacity);
					std::swap(_alloc, x._alloc);
				}
				void	clear(void)
				{
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(&_array[i]);
					_size = 0;
				}

				// allocator:
				allocator_type	get_allocator() const
				{return (_alloc);}

			private:

				void	_shift_right(size_type position, size_type n)
				{
					if (empty())
						return;
					for (size_type i = _size - 1; i >= position; i--)
					{
						_alloc.construct(&_array[i + n], _array[i]);
						_alloc.destroy(&_array[i]);
					}
				}
				void	_shift_left(size_type position, size_type n)
				{
					if (empty())
						return;
					for (size_type i = position; i < _size - n; i++)
					{
						_alloc.construct(&_array[i], _array[i + n]);
						_alloc.destroy(&_array[i + n]);
					}
				}
		};

	//std::ostream	&operator<<(std::ostream &o, vector const &src);

	// relational operators
	template <class T, class Alloc>
		bool	operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			if (lhs.size() != rhs.size())
				return false;
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}
	template <class T, class Alloc>
		bool	operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{return !(lhs == rhs);}
	template <class T, class Alloc>
		bool	operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}
	template <class T, class Alloc>
		bool	operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{return ((lhs == rhs) || (lhs < rhs));}
	template <class T, class Alloc>
		bool	operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{return !(lhs <= rhs);}
	template <class T, class Alloc>
		bool	operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{return ((lhs == rhs) || (lhs > rhs));}

	// swap
	template <class T, class Alloc>
		void swap	(vector<T,Alloc>& x, vector<T,Alloc>& y)
		{x.swap(y);}
}

#endif
