/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:38:26 by adelille          #+#    #+#             */
/*   Updated: 2022/02/16 10:46:50 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

static int	test_n_pair(void)
{
	ft::pair<std::string, int>	p1(static_cast<std::string>("key1"), 42);
	ft::pair<std::string, int>	p2(static_cast<std::string>("key2"), -21);
	ft::pair<std::string, int>	p3 = ft::make_pair(static_cast<std::string>("key3"), 84);

	if (p1.first != "key1" || p1.second != 42)
		return (true);
	if (p2.first != "key2" || p2.second != -21)
		return (true);
	if (p3.first != "key3" || p3.second != 84)
		return (true);

	return (false);
}

static int	test_n_pair_std(void)
{
	std::pair<std::string, int>	p1(static_cast<std::string>("key1"), 42);
	std::pair<std::string, int>	p2(static_cast<std::string>("key2"), -21);
	std::pair<std::string, int>	p3 = std::make_pair(static_cast<std::string>("key3"), 84);

	if (p1.first != "key1" || p1.second != 42)
		return (true);
	if (p2.first != "key2" || p2.second != -21)
		return (true);
	if (p3.first != "key3" || p3.second != 84)
		return (true);

	return (false);
}

bool	test_pair(void)
{
	return (tl("pair + make_pair", &test_n_pair, &test_n_pair_std));
}
