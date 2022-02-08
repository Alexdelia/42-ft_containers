/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:20:48 by adelille          #+#    #+#             */
/*   Updated: 2022/02/08 11:34:01 by adelille         ###   ########.fr       */
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

static int	test_size(void)
{
	ft::vector<int>	v1;
	ft::vector<int>	v2(42, 21);
	int				i[] = {42, 1, -84};
	ft::vector<int>	v3(i, i + sizeof(i) / sizeof(int));

	if (v1.size() != 0 || v2.size() != 42 || v3.size() != 3)
		return (true);
	return (v1.size() + v2.size() + v3.size());
}

static int	test_size_std(void)
{
	std::vector<int>	v1;
	std::vector<int>	v2(42, 21);
	int					i[] = {42, 1, -84};
	std::vector<int>	v3(i, i + sizeof(i) / sizeof(int));

	if (v1.size() != 0 || v2.size() != 42 || v3.size() != 3)
		return (true);
	return (v1.size() + v2.size() + v3.size());
}

static int	test_max_size(void)
{
	ft::vector<int>	v1;
	ft::vector<int>	v2(42, 21);
	int				i[] = {42, 1, -84};
	ft::vector<int>	v3(i, i + sizeof(i) / sizeof(int));

	std::cerr << v1.max_size() << std::endl;
	std::cerr << v2.max_size() << std::endl;
	std::cerr << v3.max_size() << std::endl;
	return (v1.max_size() + v2.max_size() + v3.max_size());
}

static int	test_max_size_std(void)
{
	std::vector<int>	v1;
	std::vector<int>	v2(42, 21);
	int					i[] = {42, 1, -84};
	std::vector<int>	v3(i, i + sizeof(i) / sizeof(int));

	std::cerr << v1.max_size() << std::endl;
	std::cerr << v2.max_size() << std::endl;
	std::cerr << v3.max_size() << std::endl;
	return (v1.max_size() + v2.max_size() + v3.max_size());
}

static int	test_resize(void)
{
	ft::vector<int>	v1;
	ft::vector<int>	v2(42, 21);
	int				i[] = {42, 1, -84};
	ft::vector<int>	v3(i, i + sizeof(i) / sizeof(int));

	try
	{
		v1.resize(-1);
		return (true);
	}
	catch (std::length_error)
	{
		std::cerr << C_GREEN << "resize(-1) exception working" << C_RESET <<std::endl;
	}
	v2.resize(10);
	v3.resize(5);
	std::cerr << v1.size() << "|" << v1.capacity() << std::endl << vtos(v1) << std::endl;
	std::cerr << v2.size() << "|" << v2.capacity() << std::endl << vtos(v2) << std::endl;
	std::cerr << v3.size() << " |" << v3.capacity() << std::endl << vtos(v3) << std::endl;
	return (v1.size() + v2.size() + v3.size());
}

static int	test_resize_std(void)
{
	std::vector<int>	v1;
	std::vector<int>	v2(42, 21);
	int					i[] = {42, 1, -84};
	std::vector<int>	v3(i, i + sizeof(i) / sizeof(int));

	try
	{
		v1.resize(-1);
		return (true);
	}
	catch (std::length_error)
	{
		std::cerr << C_GREEN << "resize(-1) exception working" << C_RESET <<std::endl;
	}
	v2.resize(10);
	v3.resize(5);
	std::cerr << v1.size() << "|" << v1.capacity() << std::endl << vtos(v1) << std::endl;
	std::cerr << v2.size() << "|" << v2.capacity() << std::endl << vtos(v2) << std::endl;
	std::cerr << v3.size() << " |" << v3.capacity() << std::endl << vtos(v3) << std::endl;
	return (v1.size() + v2.size() + v3.size());
}

static int	test_capacity(void)
{
	ft::vector<int>	v1;
	ft::vector<int>	v2(42, 21);
	int				i[] = {42, 1, -84};
	ft::vector<int>	v3(i, i + sizeof(i) / sizeof(int));

	return (v1.capacity() + v2.capacity() + v3.capacity());
}

static int	test_capacity_std(void)
{
	std::vector<int>	v1;
	std::vector<int>	v2(42, 21);
	int					i[] = {42, 1, -84};
	std::vector<int>	v3(i, i + sizeof(i) / sizeof(int));

	return (v1.capacity() + v2.capacity() + v3.capacity());
}

static int	test_empty(void)
{
	ft::vector<int>	v1;
	ft::vector<int>	v2(0, 21);
	int				i[] = {42, 1, -84};
	ft::vector<int>	v3(i, i + sizeof(i) / sizeof(int));

	if (!v1.empty())
		return (true);
	if (!v2.empty())
		return (true);
	if (v3.empty())
		return (true);

	return (false);
}

static int	test_empty_std(void)
{
	std::vector<int>	v1;
	std::vector<int>	v2(0, 21);
	int					i[] = {42, 1, -84};
	std::vector<int>	v3(i, i + sizeof(i) / sizeof(int));

	if (!v1.empty())
		return (true);
	if (!v2.empty())
		return (true);
	if (v3.empty())
		return (true);

	return (false);
}

static int	test_reserve(void)
{
	ft::vector<int>	v1;
	ft::vector<int>	v2(42, 21);
	int				i[] = {42, 1, -84};
	ft::vector<int>	v3(i, i + sizeof(i) / sizeof(int));

	v1.reserve(21);
	v2.reserve(21);
	v3.reserve(21);
	if (v1.capacity() != 21 && v2.capacity() != 42 && v3.capacity() != 21)
		return (true);

	v1.reserve(42);
	v2.reserve(42);
	v3.reserve(42);
	if (v1.capacity() != 42 && v2.capacity() != 42 && v3.capacity() != 42)
		return (true);
	
	v1.reserve(1);
	v2.reserve(1);
	v3.reserve(1);
	if (v1.capacity() != 42 && v2.capacity() != 42 && v3.capacity() != 42)
		return (true);

	return (false);
}

static int	test_reserve_std(void)
{
	std::vector<int>	v1;
	std::vector<int>	v2(42, 21);
	int					i[] = {42, 1, -84};
	std::vector<int>	v3(i, i + sizeof(i) / sizeof(int));

	v1.reserve(21);
	v2.reserve(21);
	v3.reserve(21);
	if (v1.capacity() != 21 && v2.capacity() != 42 && v3.capacity() != 21)
		return (true);

	v1.reserve(42);
	v2.reserve(42);
	v3.reserve(42);
	if (v1.capacity() != 42 && v2.capacity() != 42 && v3.capacity() != 42)
		return (true);
	
	v1.reserve(1);
	v2.reserve(1);
	v3.reserve(1);
	if (v1.capacity() != 42 && v2.capacity() != 42 && v3.capacity() != 42)
		return (true);

	return (false);
}

static int	test_access_operator()
{
	ft::vector<int>	v1(5, 42);
	int				i[] = {42, 1, -84};
	ft::vector<int>	v2(i, i + sizeof(i) / sizeof(int));

	if (v2[0] != 42 && v2[1] != 1 && v2[2] != -84)
		return (true);
	v1[0] = 21;
	if (v1[0] != 21)
		return (true);
	
	std::cerr << v1.size() << "|" << v1.capacity() << std::endl;
	v1[100] = 42;
	std::cerr << vtos(v1) << std::endl;
	std::cerr << v1.size() << "|" << v1.capacity() << std::endl;
	std::cerr << "|"
		<< v1[0] << "|"
		<< v1[1] << "|"
		<< v1[2] << "|"
		<< v1[3] << "|"
		<< v1[4] << "|"
		<< v1[5] << "|"
		<< v1[100] << "|" << std::endl << std::endl;

	std::cerr << v2.size() << "|" << v2.capacity() << std::endl;
	v2[100] = 42;
	std::cerr << vtos(v2) << std::endl;
	std::cerr << v2.size() << "|" << v2.capacity() << std::endl;
	std::cerr << "|"
		<< v2[0] << "|"
		<< v2[1] << "|"
		<< v2[2] << "|"
		<< v2[3] << "|"
		<< v2[4] << "|"
		<< v2[5] << "|"
		<< v2[100] << "|" << std::endl;
	
	return (false);
}

static int	test_access_operator_std()
{
	std::vector<int>	v1(5, 42);
	int					i[] = {42, 1, -84};
	std::vector<int>	v2(i, i + sizeof(i) / sizeof(int));

	if (v2[0] != 42 && v2[1] != 1 && v2[2] != -84)
		return (true);
	v1[0] = 21;
	if (v1[0] != 21)
		return (true);
	
	std::cerr << v1.size() << "|" << v1.capacity() << std::endl;
	v1[100] = 42;
	std::cerr << vtos(v1) << std::endl;
	std::cerr << v1.size() << "|" << v1.capacity() << std::endl;
	std::cerr << "|"
		<< v1[0] << "|"
		<< v1[1] << "|"
		<< v1[2] << "|"
		<< v1[3] << "|"
		<< v1[4] << "|"
		<< v1[5] << "|"
		<< v1[100] << "|" << std::endl << std::endl;
	
	std::cerr << v2.size() << "|" << v2.capacity() << std::endl;
	v2[100] = 42;
	std::cerr << vtos(v2) << std::endl;
	std::cerr << v2.size() << "|" << v2.capacity() << std::endl;
	std::cerr << "|"
		<< v2[0] << "|"
		<< v2[1] << "|"
		<< v2[2] << "|"
		<< v2[3] << "|"
		<< v2[4] << "|"
		<< v2[5] << "|"
		<< v2[100] << "|" << std::endl;
	
	return (false);
}

static int	test_at()
{
	ft::vector<int>	v1(5, 42);
	int				i[] = {42, 1, -84};
	ft::vector<int>	v2(i, i + sizeof(i) / sizeof(int));
	ft::vector<int>	v3;

	if (v2.at(0) != 42 && v2.at(1) != 1 && v2.at(2) != -84)
		return (true);
	v1.at(0) = 21;
	if (v1.at(0) != 21)
		return (true);

	try
	{
		v3.at(0);
		std::cerr << C_RED << "KO" << C_RESET << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cerr << C_GREEN << "OK" << C_RESET << std::endl;
	}
	
	std::cerr << v1.size() << "|" << v1.capacity() << std::endl;
	try
	{
		v3.at(100) = 42;
		std::cerr << C_RED << "KO" << C_RESET << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cerr << C_GREEN << "OK" << C_RESET << std::endl;
	}
	std::cerr << vtos(v1) << std::endl;
	std::cerr << v1.size() << "|" << v1.capacity() << std::endl;
	std::cerr << "|"
		<< v1.at(0) << "|"
		<< v1.at(1) << "|"
		<< v1.at(2) << "|"
		<< v1.at(3) << "|" << std::endl;
	std::cerr << v1.size() << "|" << v1.capacity() << std::endl;
	try
	{
		v3.at(100);
		std::cerr << C_RED << "KO" << C_RESET << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cerr << C_GREEN << "OK" << C_RESET << std::endl;
	}

	return (false);
}

static int	test_at_std()
{
	std::vector<int>	v1(5, 42);
	int					i[] = {42, 1, -84};
	std::vector<int>	v2(i, i + sizeof(i) / sizeof(int));
	std::vector<int>	v3;

	if (v2.at(0) != 42 && v2.at(1) != 1 && v2.at(2) != -84)
		return (true);
	v1.at(0) = 21;
	if (v1.at(0) != 21)
		return (true);

	try
	{
		v3.at(0);
		std::cerr << C_RED << "KO" << C_RESET << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cerr << C_GREEN << "OK" << C_RESET << std::endl;
	}
	
	std::cerr << v1.size() << "|" << v1.capacity() << std::endl;
	try
	{
		v3.at(100) = 42;
		std::cerr << C_RED << "KO" << C_RESET << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cerr << C_GREEN << "OK" << C_RESET << std::endl;
	}
	std::cerr << vtos(v1) << std::endl;
	std::cerr << v1.size() << "|" << v1.capacity() << std::endl;
	std::cerr << "|"
		<< v1.at(0) << "|"
		<< v1.at(1) << "|"
		<< v1.at(2) << "|"
		<< v1.at(3) << "|" << std::endl;
	std::cerr << v1.size() << "|" << v1.capacity() << std::endl;
	try
	{
		v3.at(100);
		std::cerr << C_RED << "KO" << C_RESET << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cerr << C_GREEN << "OK" << C_RESET << std::endl;
	}

	return (false);
}

bool	test_vector(void)
{
	bool	ret;

	ret = false;
	ret |= tl("constructor", &test_constructor, &test_constructor_std);
	ret |= tl("reverse iterator", &test_v_iterator, &test_v_iterator_std);
	ret |= tl("size", &test_size, &test_size_std);
	ret |= tl("max size", &test_max_size, &test_max_size_std);
	ret |= tl("resize", &test_resize, &test_resize_std);
	ret |= tl("capacity", &test_capacity, &test_capacity_std);
	ret |= tl("empty", &test_empty, &test_empty_std);
	ret |= tl("reserve", &test_reserve, &test_reserve_std);
	ret |= tl("access operator", &test_access_operator, &test_access_operator_std);
	ret |= tl("at", &test_at, &test_at_std);
//	ret |= tl("element access", &test_element access, &test_element access_std);
//	ret |= tl("modifier", &test_modifier, &test_modifier_std);

	return (ret);
}
