/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if_is_integral.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:20:48 by adelille          #+#    #+#             */
/*   Updated: 2022/02/06 11:36:15 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

class A {};

template <class T>
typename ft::enable_if<ft::is_integral<T>::value,
		 bool>::type is_odd (T i) {return bool(i % 2);}

bool	test_enable_if_is_integral(void)
{
	if (ft::is_integral<A>::value)
		return (true);
	if (ft::is_integral<float>::value)
		return (true);
	if (!ft::is_integral<int>::value)
		return (true);
	if (ft::is_integral<const int>::value)
		return (true);
	if (ft::is_integral<bool>::value)
		return (true);
	if (is_odd(2) && !is_odd(3))
		return (true);

	return (false);
}
