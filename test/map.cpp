/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:26:10 by adelille          #+#    #+#             */
/*   Updated: 2022/03/05 22:16:14 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

	template <typename T1, typename T2>
static std::string mtos(ft::map<T1, T2> &m)
{
	std::ostringstream	ss;

	for (typename ft::map<T1, T2>::iterator i = m.begin(); i != m.end(); ++i)
		ss << "|" << i->first << "\t: " << i->second << "|" << std::endl;
	return (ss.str());
}

	template <typename T1, typename T2>
static std::string mtos(std::map<T1, T2> &m)
{
	std::ostringstream	ss;

	for (typename std::map<T1, T2>::iterator i = m.begin(); i != m.end(); ++i)
		ss << "|" << i->first << "\t: " << i->second << "|" << std::endl;
	return (ss.str());
}

static int	test_basic(void)
{
	ft::map<std::string, int>	m1;
	ft::map<std::string, int>	m2(m1);
	ft::map<std::string, int>	m3(m2.begin(), m2.end());
	
	if (m1.size() != 0 || m1.empty() != true)
		return (true);
	
	if (m2.size() != 0 || m2.empty() != true)
		return (true);
	
	if (m3.size() != 0 || m3.empty() != true)
		return (true);
	
	m2.insert(ft::make_pair(static_cast<std::string>("str1"), 42));
	m2.insert(ft::make_pair(static_cast<std::string>("str2"), -21));
	
	std::cerr << std::endl << mtos(m2) << std::endl;
	if (m2.size() != 2 || m2.empty() != false)
		return (true);

	m2.clear();
	if (m2.size() != 0 || m2.empty() != true)
		return (true);

	m3.insert(ft::make_pair(static_cast<std::string>("another str"), 84));
	m3.insert(ft::make_pair(static_cast<std::string>("something"), 0));
	m3.insert(ft::make_pair(static_cast<std::string>("something else"), -1));
	
	std::cerr << mtos(m3) << std::endl;
	if (m3.size() != 3 || m3.empty() != false)
		return (true);
	
	ft::map<std::string, int>	m4(m3.begin(), m3.end());
	ft::map<std::string, int>	m5(m4);

	std::cerr << mtos(m4) << std::endl;
	if (m4.size() != 3 || m4.empty() != false)
		return (true);

	std::cerr << mtos(m5) << std::endl;
	if (m5.size() != 3 || m5.empty() != false)
		return (true);
	
	m5.clear();
	if (m5.size() != 0 || m5.empty() != true)
		return (true);

	return (false);
}

static int	test_basic_std(void)
{
	std::map<std::string, int>	m1;
	std::map<std::string, int>	m2(m1);
	std::map<std::string, int>	m3(m2.begin(), m2.end());
	
	if (m1.size() != 0 || m1.empty() != true)
		return (true);
	
	if (m2.size() != 0 || m2.empty() != true)
		return (true);
	
	if (m3.size() != 0 || m3.empty() != true)
		return (true);
	
	m2.insert(std::make_pair(static_cast<std::string>("str1"), 42));
	m2.insert(std::make_pair(static_cast<std::string>("str2"), -21));
	
	std::cerr << std::endl << mtos(m2) << std::endl;
	if (m2.size() != 2 || m2.empty() != false)
		return (true);

	m2.clear();
	if (m2.size() != 0 || m2.empty() != true)
		return (true);

	m3.insert(std::make_pair(static_cast<std::string>("another str"), 84));
	m3.insert(std::make_pair(static_cast<std::string>("something"), 0));
	m3.insert(std::make_pair(static_cast<std::string>("something else"), -1));
	
	std::cerr << mtos(m3) << std::endl;
	if (m3.size() != 3 || m3.empty() != false)
		return (true);
	
	std::map<std::string, int>	m4(m3.begin(), m3.end());
	std::map<std::string, int>	m5(m4);

	std::cerr << mtos(m4) << std::endl;
	if (m4.size() != 3 || m4.empty() != false)
		return (true);

	std::cerr << mtos(m5) << std::endl;
	if (m5.size() != 3 || m5.empty() != false)
		return (true);
	
	m5.clear();
	if (m5.size() != 0 || m5.empty() != true)
		return (true);

	return (false);
}

bool	test_map(void)
{
	bool	ret;

	ret = false;
	ret |= tl("basic", &test_basic, &test_basic_std);

	return (ret);
}
