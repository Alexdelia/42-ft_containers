/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:02:00 by adelille          #+#    #+#             */
/*   Updated: 2022/02/16 10:27:03 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>

# include "lexicographical_compare.hpp"
# include "equal.hpp"
//# include "pair.hpp"

// https://www.cplusplus.com/reference/stack/stack/

namespace ft
{
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator< ft::pair< Key, T> > >
		class stack
		{
			public:
				// typedef

			protected:
				//

			public:
				//

		};
}

#endif
