/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:13:04 by adelille          #+#    #+#             */
/*   Updated: 2022/02/05 18:22:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

std::string	str = "Hello, World!";

static int	test_reverse_iterator(void)
{
	ft::reverse_iterator<std::string::iterator>	rbegin(str.end());
	ft::reverse_iterator<std::string::iterator>	rend(str.begin());
	ft::reverse_iterator<std::string::iterator>	copy;
	
	copy = rbegin;

	std::cerr << "   str: [" << str << "]" << std::endl
		<< "rbegin: [" << *rbegin << "]\t(copy: [" << *copy << "])" << std::endl
		<< "  rend: [" << *rend << "]" << std::endl;

	std::cerr << "|";
	while (rbegin != rend)
	{
		std::cerr << *rbegin << "|";
		rbegin++;
	}
	std::cerr << std::endl;
	
	rbegin--;
	copy--;
	std::cerr << "|";
	while (rbegin != copy)
	{
		std::cerr << *rbegin << "|";
		rbegin--;
	}
	std::cerr << std::endl;
	return (false);
}

static int	test_reverse_iterator_std(void)
{
	std::reverse_iterator<std::string::iterator>	rbegin(str.end());
	std::reverse_iterator<std::string::iterator>	rend(str.begin());
	std::reverse_iterator<std::string::iterator>	copy;
	
	copy = rbegin;

	std::cerr << "   str: [" << str << "]" << std::endl
		<< "rbegin: [" << *rbegin << "]\t(copy: [" << *copy << "])" << std::endl
		<< "  rend: [" << *rend << "]" << std::endl;

	std::cerr << "|";
	while (rbegin != rend)
	{
		std::cerr << *rbegin << "|";
		rbegin++;
	}
	std::cerr << std::endl;
	
	rbegin--;
	copy--;
	std::cerr << "|";
	while (rbegin != copy)
	{
		std::cerr << *rbegin << "|";
		rbegin--;
	}
	std::cerr << std::endl;
	return (false);
}

bool	test_iterator(void)
{
	bool	ret;

	ret = false;
	ret |= tl("reverse iterator", &test_reverse_iterator, &test_reverse_iterator_std);

	return (ret);
}
