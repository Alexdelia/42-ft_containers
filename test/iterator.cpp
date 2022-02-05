/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:13:04 by adelille          #+#    #+#             */
/*   Updated: 2022/02/05 16:58:23 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

static bool	test_iterator_basic(void)
{
	std::cout << "me" << std::endl; //
	return (false);
}

static bool	test_iterator_basic_std(void)
{
	std::cout << "std" << std::endl; //
	return (false);
}

bool	test_iterator(void)
{
	bool	ret;

	ret = false;
	ret |= tl("basic", &test_iterator_basic, &test_iterator_basic_std);

	return (ret);
}
