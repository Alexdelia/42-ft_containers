/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:25:54 by adelille          #+#    #+#             */
/*   Updated: 2022/02/02 18:48:52 by adelille         ###   ########.fr       */
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
				explicit reverse_iterator (iterator_type it) : _ptr(it) {};
				reverse_iterator (const reverse_iterator<Iterator>& rev_it) : _ptr(rev_it._ptr) {};

				reverse_iterator	&operator=(const reverse_iterator& it)
				{
					_ptr = it._ptr;
					return (*this);
				}

				operator	reverse_iterator<random_access_iterator<value_type const> >() const
				{return (reverse_iterator<random_access_iterator<value_type const> >(_ptr));}
				operator	reverse_iterator<random_access_iterator<value_type> >()
				{return (reverse_iterator<random_access_iterator<value_type> >(_ptr));}

			private:
				iterator_type	_ptr;
		};
}

#endif
