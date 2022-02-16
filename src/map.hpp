/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:02:00 by adelille          #+#    #+#             */
/*   Updated: 2022/02/16 10:54:07 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>

# include "lexicographical_compare.hpp"
# include "equal.hpp"
# include "pair.hpp"

// https://www.cplusplus.com/reference/map/map/

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>,
			 class Allocator = std::allocator< ft::pair< Key, T> > >
				 class map
				 {
					 public:
						 typedef Key								key_type;
						 typedef T									mapped_type;
						 typedef ft::pair<key_type, mapped_type>	value_type;
						 typedef std::size_t						size_type;
						 typedef std::ptrdiff_t						difference_type;
						 typedef Compare							key_compare;
						 typedef Allocator							allocator_type;
						 typedef value_type							&reference;
						 typedef const value_type					&const_reference;
						 typedef value_type							*pointer;
						 typedef const value_type					*const_pointer;

					 protected:
						 allocator_type		_alloc;

					 public:
						 explicit map(const key_compare &comp = key_compare(),
								 const allocator_type &alloc = allocator_type())
						 {

						 }

				 };
}

#endif
