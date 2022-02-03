/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:25:54 by adelille          #+#    #+#             */
/*   Updated: 2022/02/03 11:30:55 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "random_access_iterator.hpp"

namespace ft
{
	template <class Iterator>
		class reverse_iterator
		{
			public:
				typedef Iterator												iterator_type;
				typedef typename iterator_traits<Iterator>::value_type			value_type;
				typedef typename iterator_traits<Iterator>::difference_type		difference_type;
				typedef typename iterator_traits<Iterator>::pointer				pointer;
				typedef typename iterator_traits<Iterator>::reference			reference;
				typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;

				reverse_iterator() : _ptr(Iterator()) {};
				explicit reverse_iterator(iterator_type it) : _ptr(it) {};
				reverse_iterator(const reverse_iterator<Iterator>& rev_it) : _ptr(rev_it._ptr) {};
				~reverse_iterator() {};

				reverse_iterator	&operator=(const reverse_iterator &src)
				{
					_ptr = src._ptr;
					return (*this);
				}

				operator	reverse_iterator<random_access_iterator<value_type const> >() const
				{return (reverse_iterator<random_access_iterator<value_type const> >(_ptr));}
				operator	reverse_iterator<random_access_iterator<value_type> >()
				{return (reverse_iterator<random_access_iterator<value_type> >(_ptr));}

				iterator_type	base() const
				{return (_ptr);}

			private:
				iterator_type	_ptr;

			public:
				// bool
				bool	operator==(const reverse_iterator& other) const
				{return _ptr == other._ptr;}
				bool	operator!=(const reverse_iterator& other) const
				{return _ptr != other._ptr;}
				bool	operator<(const reverse_iterator& other) const
				{return _ptr > other._ptr;}
				bool	operator<=(const reverse_iterator& other) const
				{return _ptr >= other._ptr;}
				bool	operator>(const reverse_iterator& other) const
				{return _ptr < other._ptr;}
				bool	operator>=(const reverse_iterator& other) const
				{return _ptr <= other._ptr;}

				// increment/decrement
				reverse_iterator	&operator++()
				{
					--_ptr;
					return (*this);
				}
				reverse_iterator	operator++(int)
				{
					reverse_iterator	tmp = *this;
					--_ptr;
					return (tmp);
				}
				reverse_iterator	&operator--()
				{
					++_ptr;
					return (*this);
				}
				reverse_iterator	operator--(int)
				{
					reverse_iterator	tmp = *this;
					++_ptr;
					return (tmp);
				}

				// assignement
				reverse_iterator	&operator+=(difference_type n)
				{
					_ptr -= n;
					return (*this);
				}
				reverse_iterator	&operator-=(difference_type n)
				{
					_ptr += n;
					return (*this);
				}

				// arithmetic
				reverse_iterator	operator+(difference_type n) const
				{
					reverse_iterator	tmp = *this;
					tmp += n;
					return (tmp);
				}
				reverse_iterator	operator-(difference_type n) const
				{
					reverse_iterator	tmp = *this;
					tmp -= n;
					return (tmp);
				}
				difference_type	operator+(const reverse_iterator &rhs) const
				{
					return (_ptr + rhs._ptr);
				}
				difference_type	operator-(const reverse_iterator &rhs) const
				{
					return (_ptr - rhs._ptr);
				}

				// access
				reference operator[](difference_type n) const
				{
					return (*(_ptr - n - 1));
				}
				reference operator*() const
				{
					Iterator	tmp = _ptr;

					return (*(--tmp));
				}
				pointer operator->() const
				{
					return &(operator*());
				}
		};

	template <class Iterator>
		bool	operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return (lhs.base() == rhs.base());
		}

	template <class Iterator>
		bool	operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return (lhs.base() != rhs.base());
		}

	template <class Iterator>
		bool	operator< (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return (lhs.base() > rhs.base());
		}

	template <class Iterator>
		bool	operator> (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return (lhs.base() < rhs.base());
		}

	template <class Iterator>
		bool	operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return (lhs.base() >= rhs.base());
		}

	template <class Iterator>
		bool	operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return (lhs.base() <= rhs.base());
		}

	template <class Iterator>
		reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
		{return (rev_it + n);}

	template <class Iterator>
		reverse_iterator<Iterator> operator- (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
		{return (rev_it - n);}
}

#endif
