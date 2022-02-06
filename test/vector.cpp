/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:20:48 by adelille          #+#    #+#             */
/*   Updated: 2022/02/06 13:56:24 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

	template <typename T>
static std::string	vtos(ft::vector<T> &v)
{
	std::ostringstream	ss;

	ss << "|";
	for (typename ft::vector<T>::iterator i = v.begin(); i != v.end(); ++i)
		ss << *i << "|";
	return (ss.str());
}

	template <typename T>
static std::string	vtos(std::vector<T> &v)
{
	std::ostringstream	ss;

	ss << "|";
	for (typename std::vector<T>::iterator i = v.begin(); i != v.end(); ++i)
		ss << *i << "|";
	return (ss.str());
}

static int	test_constructor(void)
{
	ft::vector<int>	v1;									// default
	ft::vector<int>	v2(3);								// size
	ft::vector<int>	v3(3, 42);							// size + value
	ft::vector<int>	v4(v3);								// copy
	ft::vector<int>	v5(v3.begin(), v3.end());			// iterator
	int				i[] = {42, 1, -84};
	ft::vector<int>	v6(i, i + sizeof(i) / sizeof(int));	// iterator from array
	ft::vector<int>	v7 = v6;							// assign

	std::cerr << "default:             " << vtos(v1) << std::endl;
	std::cerr << "size:                " << vtos(v2) << std::endl;
	std::cerr << "size + value:        " << vtos(v3) << std::endl;
	std::cerr << "copy:                " << vtos(v4) << std::endl;
	std::cerr << "iterator:            " << vtos(v5) << std::endl;
	std::cerr << "iterator from array: " << vtos(v6) << std::endl;
	std::cerr << "assign:              " << vtos(v7) << std::endl;

	return (false);
}

static int	test_constructor_std(void)
{
	std::vector<int>	v1;									// default
	std::vector<int>	v2(3);								// size
	std::vector<int>	v3(3, 42);							// size + value
	std::vector<int>	v4(v3);								// copy
	std::vector<int>	v5(v3.begin(), v3.end());			// iterator
	int					i[] = {42, 1, -84};
	std::vector<int>	v6(i, i + sizeof(i) / sizeof(int));	// iterator from array
	std::vector<int>	v7 = v6;							// assign

	std::cerr << "default:             " << vtos(v1) << std::endl;
	std::cerr << "size:                " << vtos(v2) << std::endl;
	std::cerr << "size + value:        " << vtos(v3) << std::endl;
	std::cerr << "copy:                " << vtos(v4) << std::endl;
	std::cerr << "iterator:            " << vtos(v5) << std::endl;
	std::cerr << "iterator from array: " << vtos(v6) << std::endl;
	std::cerr << "assign:              " << vtos(v7) << std::endl;

	return (false);
}

static int	test_v_iterator(void)
{
	ft::vector<int>	v1;
	int				i[] = {42, 1, -84};
	ft::vector<int>	v2(i, i + sizeof(i) / sizeof(int));

	std::cerr << "|";
	for (ft::reverse_iterator<ft::vector<int>::iterator > i = v1.rbegin();
			i != v1.rend(); ++i)
		std::cerr << *i << "|";
	std::cerr << std::endl << "size: " << v1.size() << std::endl;
	if (v1.size() != 0)
		return (true);
	
	std::cerr << "|";
	for (ft::reverse_iterator<ft::vector<int>::iterator > i = v2.rbegin();
			i != v2.rend(); ++i)
		std::cerr << *i << "|";
	std::cerr << std::endl << "size: " << v2.size() << std::endl;
	if (v1.size() != 3)
		return (true);

	return (false);
}

static int	test_v_iterator_std(void)
{
	std::vector<int>	v1;
	int					i[] = {42, 1, -84};
	std::vector<int>	v2(i, i + sizeof(i) / sizeof(int));

	std::cerr << "|";
	for (std::reverse_iterator<std::vector<int>::iterator > i = v1.rbegin();
			i != v1.rend(); ++i)
		std::cerr << *i << "|";
	std::cerr << std::endl << "size: " << v1.size() << std::endl;
	if (v1.size() != 0)
		return (true);
	
	std::cerr << "|";
	for (std::reverse_iterator<std::vector<int>::iterator > i = v2.rbegin();
			i != v2.rend(); ++i)
		std::cerr << *i << "|";
	std::cerr << std::endl << "size: " << v2.size() << std::endl;
	if (v1.size() != 3)
		return (true);

	return (false);
}

bool	test_vector(void)
{
	bool	ret;

	ret = false;
	ret |= tl("constructor", &test_constructor, &test_constructor_std);
	ret |= tl("reverse iterator", &test_v_iterator, &test_v_iterator_std);
//	ret |= tl("capacity", &test_capacity, &test_capacity_std);
//	ret |= tl("element access", &test_element access, &test_element access_std);
//	ret |= tl("modifier", &test_modifier, &test_modifier_std);

	return (ret);
}
