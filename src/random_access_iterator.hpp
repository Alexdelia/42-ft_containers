/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:34:47 by adelille          #+#    #+#             */
/*   Updated: 2022/02/02 14:04:03 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <iterator>

// https://en.cppreference.com/w/cpp/iterator/random_access_iterator

namespace ft
{
	template <class T>
		class random_access_iterator
		{
			public:
				typedef T								value_type;
				typedef value_type						&reference;
				typedef value_type						*pointer;
				typedef std::ptrdiff_t					difference_type;
				typedef std::random_access_iterator_tag	iterator_category;

				random_access_iterator() : _ptr(NULL) {};
				random_access_iterator(pointer ptr) : _ptr(ptr) {};
				random_access_iterator(const random_access_iterator &src)
					: _ptr(src._ptr) {};
				virtual	~random_access_iterator() {};

				random_access_iterator	&operator=(const random_access_iterator &src)
				{
					_ptr = src._ptr;
					return (*this);
				}

				operator	random_access_iterator<value_type const>() const
				{return (random_access_iterator<value_type const>(_ptr));}

				// bool
				bool	operator==(const random_access_iterator &other) const
				{return (_ptr == other._ptr);}
				bool	operator!=(const random_access_iterator &other) const
				{return (_ptr != other._ptr);}
				bool	operator<(const random_access_iterator &other) const
				{return (_ptr < other._ptr);}
				bool	operator>(const random_access_iterator &other) const
				{return (_ptr > other._ptr);}
				bool	operator<=(const random_access_iterator &other) const
				{return (_ptr <= other._ptr);}
				bool	operator>=(const random_access_iterator &other) const
				{return (_ptr >= other._ptr);}

				// increment/decrement
				random_access_iterator	&operator++()
				{
					++_ptr;
					return (*this);
				}
				random_access_iterator	operator++(int)
				{
					random_access_iterator	tmp(*this);
					++_ptr;
					return (tmp);
				}
				random_access_iterator	&operator--()
				{
					--_ptr;
					return (*this);
				}
				random_access_iterator	operator--(int)
				{
					random_access_iterator	tmp(*this);
					--_ptr;
					return (tmp);
				}

				// assignment
				random_access_iterator	&operator+=(difference_type n)
				{
					_ptr += n;
					return (*this);
				}
				random_access_iterator	&operator-=(difference_type n)
				{
					_ptr -= n;
					return (*this);
				}

				// arithmetic
				random_access_iterator	operator+(difference_type val) const
				{return (random_access_iterator<T>(_ptr + val));}
				random_access_iterator	operator-(difference_type val) const
				{return (random_access_iterator<T>(_ptr - val));}
				difference_type	operator+(random_access_iterator const &rhs) const
				{return (_ptr + rhs._ptr);}
				difference_type	operator-(random_access_iterator const &rhs) const
				{return (_ptr - rhs._ptr);}

				// access
				reference	operator*() const
				{return (*_ptr);}
				pointer		operator->() const
				{return (_ptr);}
				reference	operator[](difference_type n) const
				{return (_ptr[n]);}


			private:
				pointer	_ptr;
		};
}

#endif
