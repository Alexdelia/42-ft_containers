/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:52:18 by adelille          #+#    #+#             */
/*   Updated: 2022/02/05 17:05:25 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int	main(void)
{
	int	ret;

	ret = 0;
	ret |= ts("iterator", &test_iterator);
//	ret |= ts("vector", &test_vector);

	return (ret);
}
