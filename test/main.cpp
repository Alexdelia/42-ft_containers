/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:52:18 by adelille          #+#    #+#             */
/*   Updated: 2022/03/10 12:35:39 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int	main(void)
{
	int	ret;

	ret = 0;
	ret |= ts("iterator", &test_iterator);
	//ret |= ts("eable if/is integral", &test_enable_if_is_integral);
	ret |= ts("vector", &test_vector);
	ret |= ts("stack", &test_stack);
	ret |= ts("pair", &test_pair);
	ret |= ts("rbtree", &test_rbtree);
	ret |= ts("map", &test_map);

	return (ret);
}
