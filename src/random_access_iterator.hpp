/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:34:47 by adelille          #+#    #+#             */
/*   Updated: 2022/02/02 13:43:21 by adelille         ###   ########.fr       */
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

			private:
				pointer	_ptr;
		};
}

#endif
