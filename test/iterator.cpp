/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:13:04 by adelille          #+#    #+#             */
/*   Updated: 2022/02/05 19:32:34 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

std::string	str = "Hello, World!";

static int	test_reverse_iterator(void)
{
	ft::reverse_iterator<std::string::iterator>	rbegin(str.end());
	ft::reverse_iterator<std::string::iterator>	rend(str.begin());
	ft::reverse_iterator<std::string::iterator>	copy;
	int											ret;
	
	copy = rbegin;

	std::cerr << "   str: [" << str << "]" << std::endl
		<< "rbegin: [" << *rbegin << "]\t(copy: [" << *copy << "])" << std::endl
		<< "  rend: [" << *rend << "]" << std::endl;

	ret = 0;
	std::cerr << "|";
	while (rbegin != rend)
	{
		std::cerr << *rbegin << "|";
		rbegin++;
		ret++;
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
	return (ret);
}

static int	test_reverse_iterator_std(void)
{
	std::reverse_iterator<std::string::iterator>	rbegin(str.end());
	std::reverse_iterator<std::string::iterator>	rend(str.begin());
	std::reverse_iterator<std::string::iterator>	copy;
	int												ret;
	
	copy = rbegin;

	std::cerr << "   str: [" << str << "]" << std::endl
		<< "rbegin: [" << *rbegin << "]\t(copy: [" << *copy << "])" << std::endl
		<< "  rend: [" << *rend << "]" << std::endl;

	ret = 0;
	std::cerr << "|";
	while (rbegin != rend)
	{
		std::cerr << *rbegin << "|";
		rbegin++;
		ret++;
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
	return (ret);
}

static int	test_equal_iterator(void)
{
	int					i[] = {42, 1, -84};
	std::vector<int>	v(i, i + 3);
	if (!ft::equal(v.begin(), v.end(), i))
		return (true);

	v[2] = 11;

	if (ft::equal(v.begin(), v.end(), i))
		return (true);
	return (false);
}

static int	test_equal_iterator_std(void)
{
	int					i[] = {42, 1, -84};
	std::vector<int>	v(i, i + 3);
	if (!std::equal(v.begin(), v.end(), i))
		return (true);

	v[2] = 11;

	if (std::equal(v.begin(), v.end(), i))
		return (true);
	return (false);
}

static bool	t_equal(int x, int y)
{return (x == y);}

static int	test_equal_iterator_fp(void)
{
	int					i[] = {42, 1, -84};
	std::vector<int>	v(i, i + 3);
	if (!ft::equal(v.begin(), v.end(), i, t_equal))
		return (true);

	v[2] = 11;

	if (ft::equal(v.begin(), v.end(), i, t_equal))
		return (true);
	return (false);
}

static int	test_equal_iterator_fp_std(void)
{
	int					i[] = {42, 1, -84};
	std::vector<int>	v(i, i + 3);
	if (!std::equal(v.begin(), v.end(), i, t_equal))
		return (true);

	v[2] = 11;

	if (std::equal(v.begin(), v.end(), i, t_equal))
		return (true);
	return (false);
}

char	s1[] = "Hello, World!";
char	s2[] = "Hello, Thing!"; 

static int	test_lexicographical_compare_iterator(void)
{
	if (ft::lexicographical_compare(s1, s1 + 13, s2, s2 + 13))
		return (true);
	if (!ft::lexicographical_compare(s2, s2 + 13, s1, s1 + 13))
		return (true);
	if (ft::lexicographical_compare(s1, s1 + 13, s1, s1 + 13))
		return (true);
	return (false);
}

static int	test_lexicographical_compare_iterator_std(void)
{
	if (std::lexicographical_compare(s1, s1 + 13, s2, s2 + 13))
		return (true);
	if (!std::lexicographical_compare(s2, s2 + 13, s1, s1 + 13))
		return (true);
	if (std::lexicographical_compare(s1, s1 + 13, s1, s1 + 13))
		return (true);
	return (false);
}

static bool	t_comp(char c1, char c2)
{return (c1 < c2);}

static int	test_lexicographical_compare_iterator_fp(void)
{
	if (ft::lexicographical_compare(s1, s1 + 13, s2, s2 + 13, t_comp))
		return (true);
	if (!ft::lexicographical_compare(s2, s2 + 13, s1, s1 + 13, t_comp))
		return (true);
	if (ft::lexicographical_compare(s1, s1 + 13, s1, s1 + 13, t_comp))
		return (true);
	return (false);
}

static int	test_lexicographical_compare_iterator_fp_std(void)
{
	if (std::lexicographical_compare(s1, s1 + 13, s2, s2 + 13, t_comp))
		return (true);
	if (!std::lexicographical_compare(s2, s2 + 13, s1, s1 + 13, t_comp))
		return (true);
	if (std::lexicographical_compare(s1, s1 + 13, s1, s1 + 13, t_comp))
		return (true);
	return (false);
}

bool	test_iterator(void)
{
	bool	ret;

	ret = false;
	ret |= tl("reverse iterator", &test_reverse_iterator, &test_reverse_iterator_std);
	ret |= tl("equal iterator", &test_equal_iterator, &test_equal_iterator_std);
	ret |= tl("equal iterator (with function in parameter)",
			&test_equal_iterator_fp, &test_equal_iterator_fp_std);
	ret |= tl("lexicographical compare iterator",
			&test_lexicographical_compare_iterator,
			&test_lexicographical_compare_iterator_std);
	ret |= tl("lexicographical compare iterator (with function in parameter)",
			&test_lexicographical_compare_iterator_fp,
			&test_lexicographical_compare_iterator_fp_std);

	return (ret);
}
