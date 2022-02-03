/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:05:49 by adelille          #+#    #+#             */
/*   Updated: 2022/02/03 17:11:14 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

// https://www.cplusplus.com/reference/type_traits/enable_if/

namespace ft
{
	template<bool B, class T = void>
		struct enable_if {};

	template<class T>
		struct enable_if<true, T>
		{typedef T	type;};
}

#endif
