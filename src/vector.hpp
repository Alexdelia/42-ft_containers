/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:14:18 by adelille          #+#    #+#             */
/*   Updated: 2022/02/03 17:23:26 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

// https://cplusplus.com/reference/vector/vector/

# include <iostream>
//# include <typeinfo>

# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"

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
					reverse(n);
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
				iterator				begin();
				const_iterator			begin() const;
				iterator				end();
				const_iterator			end() const;
				reverse_iterator		rbegin();
				const_reverse_iterator	rbegin() const;
				reverse_iterator		rend();
				const_reverse_iterator	rend() const;

				// capacity
				size_type	size(void) const
				{return (_size);}
				size_type	max_size(void) const
				{return (_alloc.max_size());}
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
				void	clear(void)
				{
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(&_array[i]);
					_size = 0;
				}

			private: //
		};

	//std::ostream	&operator<<(std::ostream &o, vector const &src);

	template< class T, class Alloc >
		bool	operator==(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
	bool	operator!=(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
	bool	operator<(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
	bool	operator<=(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
	bool	operator>(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
	bool	operator>=(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);

	// std::swap
	template< class T, class Alloc >
		void	swap( std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs );

}

#endif
