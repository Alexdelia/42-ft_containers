/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:26:10 by adelille          #+#    #+#             */
/*   Updated: 2022/03/09 16:12:50 by adelille         ###   ########.fr       */
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

static int	test_insert(void)
{
	ft::map<std::string, int>								m1;
	ft::map<std::string, int>								m2;
	ft::map<std::string, int>								m3;
	ft::pair<ft::map<std::string, int>::iterator, bool>	p;
	ft::map<std::string, int>::iterator						i;

	p = m1.insert(ft::make_pair(static_cast<std::string>("str1"), 42));
	std::cerr << mtos(m1) << std::endl;
	if (p.first->first != "str1" || p.first->second != 42 || p.second != 1)
		return (true);

	p = m1.insert(ft::make_pair(static_cast<std::string>("str2"), -21));
	std::cerr << mtos(m1) << std::endl;
	if (p.first->first != "str2" || p.first->second != -21 || p.second != 1)
		return (true);

	i = m1.insert(m1.begin(), ft::make_pair(static_cast<std::string>("a start"), 84));
	std::cerr << mtos(m1) << std::endl;
	if (i->first != "a start" || i->second != 84)
		return (true);

	i = m1.insert(m1.begin(), ft::make_pair(static_cast<std::string>("z end"), 0));
	std::cerr << mtos(m1) << std::endl;
	if (i->first != "z end" || i->second != 0)
		return (true);

	m2.insert(m1.begin(), m1.end());
	std::cerr << mtos(m2) << std::endl;
	if (m2.size() != 4 || m2.empty() != false)
		return (true);

	// redo
	m2.insert(m1.begin(), m1.end());
	std::cerr << mtos(m2) << std::endl;
	if (m2.size() != 4 || m2.empty() != false)
		return (true);

	FOR(TEST_SIZE)
	{
		std::ostringstream	ss;
		ss << "str" << i;
		m3.insert(ft::make_pair(ss.str(), (int)i));
	}
	if (m3.size() != TEST_SIZE || m3.empty() != false)
		return (true);

	return (false);
}

static int	test_insert_std(void)
{
	std::map<std::string, int>								m1;
	std::map<std::string, int>								m2;
	std::map<std::string, int>								m3;
	std::pair<std::map<std::string, int>::iterator, bool>	p;
	std::map<std::string, int>::iterator					i;

	p = m1.insert(std::make_pair(static_cast<std::string>("str1"), 42));
	std::cerr << mtos(m1) << std::endl;
	if (p.first->first != "str1" || p.first->second != 42 || p.second != 1)
		return (true);

	p = m1.insert(std::make_pair(static_cast<std::string>("str2"), -21));
	std::cerr << mtos(m1) << std::endl;
	if (p.first->first != "str2" || p.first->second != -21 || p.second != 1)
		return (true);

	i = m1.insert(m1.begin(), std::make_pair(static_cast<std::string>("a start"), 84));
	std::cerr << mtos(m1) << std::endl;
	if (i->first != "a start" || i->second != 84)
		return (true);

	i = m1.insert(m1.begin(), std::make_pair(static_cast<std::string>("z end"), 0));
	std::cerr << mtos(m1) << std::endl;
	if (i->first != "z end" || i->second != 0)
		return (true);

	m2.insert(m1.begin(), m1.end());
	std::cerr << mtos(m2) << std::endl;
	if (m2.size() != 4 || m2.empty() != false)
		return (true);

	// redo
	m2.insert(m1.begin(), m1.end());
	std::cerr << mtos(m2) << std::endl;
	if (m2.size() != 4 || m2.empty() != false)
		return (true);

	FOR(TEST_SIZE)
	{
		std::ostringstream	ss;
		ss << "str" << i;
		m3.insert(std::make_pair(ss.str(), (int)i));
	}
	if (m3.size() != TEST_SIZE || m3.empty() != false)
		return (true);

	return (false);
}

static int	test_assign(void)
{
	ft::map<std::string, int>	m1;
	ft::map<std::string, int>	m2;

	m1 = m2;
	std::cerr << mtos(m1) << std::endl;
	if (m1.size() != 0 || m1.empty() != true)
		return (false);

	m1.insert(ft::make_pair(static_cast<std::string>("str1"), 42));
	m1.insert(ft::make_pair(static_cast<std::string>("str2"), -21));
	m2 = m1;
	std::cerr << mtos(m2) << std::endl;
	if (m1.size() != 2 || m1.empty() != false)
		return (false);

	return (false);
}

static int	test_assign_std(void)
{
	std::map<std::string, int> m1;
	std::map<std::string, int> m2;

	m1 = m2;
	std::cerr << mtos(m1) << std::endl;
	if (m1.size() != 0 || m1.empty() != true)
		return (false);

	m1.insert(std::make_pair(static_cast<std::string>("str1"), 42));
	m1.insert(std::make_pair(static_cast<std::string>("str2"), -21));
	m2 = m1;
	std::cerr << mtos(m2) << std::endl;
	if (m1.size() != 2 || m1.empty() != false)
		return (false);

	return (false);
}

static int	test_m_iterator(void)
{
	ft::map<std::string, int>						m1;
	ft::map<std::string, int>::iterator				i1;
	ft::map<std::string, int>::iterator				i2;
	ft::map<std::string, int>::reverse_iterator		ri;

	i1 = m1.begin();
	i2 = m1.end();
	if (i1 != i2)
		return (true);

	m1.insert(ft::make_pair(static_cast<std::string>("str1"), 42));
	m1.insert(ft::make_pair(static_cast<std::string>("str2"), -21));
	m1.insert(ft::make_pair(static_cast<std::string>("weird"), 84));
	m1.insert(ft::make_pair(static_cast<std::string>("strange"), 0));
	m1.insert(ft::make_pair(static_cast<std::string>("first"), 69));

	i1 = m1.begin();
	if (i1->first != "first" || i1->second != 69)
		return (true);

	i2 = m1.end();
	for (i1 = m1.begin(); i1 != i2; ++i1)
		std::cerr << "|" << i1->first << "\t: " << i1->second << "|" << std::endl;

	std::cerr << std::endl;
	for (ri = m1.rbegin(); ri != m1.rend(); ++ri)
		std::cerr << "|" << ri->first << "\t: " << ri->second << "|" << std::endl;

	return (false);
}

static int	test_m_iterator_std(void)
{
	std::map<std::string, int>						m1;
	std::map<std::string, int>::iterator			i1;
	std::map<std::string, int>::iterator			i2;
	std::map<std::string, int>::reverse_iterator	ri;

	i1 = m1.begin();
	i2 = m1.end();
	if (i1 != i2)
		return (true);

	m1.insert(std::make_pair(static_cast<std::string>("str1"), 42));
	m1.insert(std::make_pair(static_cast<std::string>("str2"), -21));
	m1.insert(std::make_pair(static_cast<std::string>("weird"), 84));
	m1.insert(std::make_pair(static_cast<std::string>("strange"), 0));
	m1.insert(std::make_pair(static_cast<std::string>("first"), 69));

	i1 = m1.begin();
	if (i1->first != "first" || i1->second != 69)
		return (true);

	i2 = m1.end();
	for (i1 = m1.begin(); i1 != i2; ++i1)
		std::cerr << "|" << i1->first << "\t: " << i1->second << "|" << std::endl;

	std::cerr << std::endl;
	for (ri = m1.rbegin(); ri != m1.rend(); ++ri)
		std::cerr << "|" << ri->first << "\t: " << ri->second << "|" << std::endl;

	return (false);
}

static int	test_size(void)
{
	ft::map<std::string, int>	m;

	if (m.size() != 0 || m.empty() != true || m.max_size() != 0)
		return (true);

	m.insert(ft::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(ft::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(ft::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(ft::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(ft::make_pair(static_cast<std::string>("first"), 69));

	if (m.size() != 5 || m.empty() != false || m.max_size() != 5)
		return (true);

	return (false);
}

static int	test_size_std(void)
{
	std::map<std::string, int>	m;

	if (m.size() != 0 || m.empty() != true || m.max_size() != 0)
		return (true);

	m.insert(std::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(std::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(std::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(std::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(std::make_pair(static_cast<std::string>("first"), 69));

	if (m.size() != 5 || m.empty() != false || m.max_size() != 5)
		return (true);

	return (false);
}

static int	test_access(void)
{
	ft::map<std::string, int>	m;

	m.insert(ft::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(ft::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(ft::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(ft::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(ft::make_pair(static_cast<std::string>("first"), 69));

	if (m["str1"] != 42
			|| m["str2"] != -21
			|| m["weird"] != 84
			|| m["strange"] != 0
			|| m["first"] != 69)
		return (true);

	m["str1"] = 1;
	m["str2"] = 2;
	m["weird"] = 64;
	m["strange"] = 128;
	m["first"] = 256;
	if (m["str1"] != 1
			|| m["str2"] != 2
			|| m["weird"] != 64
			|| m["strange"] != 128
			|| m["first"] != 256)
		return (true);

	// out of bound
	std::cerr << m["no"] << std::endl;
	m["still no"] = 512;
	std::cerr << m["still no"] << std::endl << std::endl;

	std::cerr << mtos(m) << std::endl;

	return (false);
}

static int	test_access_std(void)
{
	std::map<std::string, int>	m;

	m.insert(std::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(std::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(std::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(std::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(std::make_pair(static_cast<std::string>("first"), 69));

	if (m["str1"] != 42
			|| m["str2"] != -21
			|| m["weird"] != 84
			|| m["strange"] != 0
			|| m["first"] != 69)
		return (true);

	m["str1"] = 1;
	m["str2"] = 2;
	m["weird"] = 64;
	m["strange"] = 128;
	m["first"] = 256;
	if (m["str1"] != 1
			|| m["str2"] != 2
			|| m["weird"] != 64
			|| m["strange"] != 128
			|| m["first"] != 256)
		return (true);

	// out of bound
	std::cerr << m["no"] << std::endl;
	m["still no"] = 512;
	std::cerr << m["still no"] << std::endl << std::endl;

	std::cerr << mtos(m) << std::endl;

	return (false);
}

static int	test_at(void)
{
	ft::map<std::string, int>	m;

	try
	{
		m.at("str1");
		std::cerr << C_RED << "KO" << std::endl;
		return (true);
	}
	catch (std::exception &)
	{
		std::cerr << C_GREEN << "OK" << std::endl;
	}

	m.insert(ft::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(ft::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(ft::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(ft::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(ft::make_pair(static_cast<std::string>("first"), 69));

	if (m.at("str1") != 42
			|| m.at("str2") != -21
			|| m.at("weird") != 84
			|| m.at("strange") != 0
			|| m.at("first") != 69)
		return (true);

	m.at("str1") = 1;
	m.at("str2") = 2;
	m.at("weird") = 64;
	m.at("strange") = 128;
	m.at("first") = 256;
	if (m.at("str1") != 1
			|| m.at("str2") != 2
			|| m.at("weird") != 64
			|| m.at("strange") != 128
			|| m.at("first") != 256)
		return (true);

	return (false);
}

static int	test_at_std(void)
{
	std::map<std::string, int>	m;

	try
	{
		m.at("str1");
		std::cerr << C_RED << "KO" << std::endl;
		return (true);
	}
	catch (std::exception &)
	{
		std::cerr << C_GREEN << "OK" << std::endl;
	}

	m.insert(std::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(std::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(std::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(std::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(std::make_pair(static_cast<std::string>("first"), 69));

	if (m.at("str1") != 42
			|| m.at("str2") != -21
			|| m.at("weird") != 84
			|| m.at("strange") != 0
			|| m.at("first") != 69)
		return (true);

	m.at("str1") = 1;
	m.at("str2") = 2;
	m.at("weird") = 64;
	m.at("strange") = 128;
	m.at("first") = 256;
	if (m.at("str1") != 1
			|| m.at("str2") != 2
			|| m.at("weird") != 64
			|| m.at("strange") != 128
			|| m.at("first") != 256)
		return (true);

	return (false);
}

static int	test_clear(void)
{
	ft::map<std::string, int>	m;

	m.clear();
	std::cerr << mtos(m);
	if (m.size() != 0 || m.empty() != true)
		return (true);

	m.insert(ft::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(ft::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(ft::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(ft::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(ft::make_pair(static_cast<std::string>("first"), 69));

	m.clear();
	std::cerr << mtos(m);
	if (m.size() != 0 || m.empty() != true)
		return (true);

	return (false);
}

static int	test_clear_std(void)
{
	std::map<std::string, int>	m;

	m.clear();
	std::cerr << mtos(m);
	if (m.size() != 0 || m.empty() != true)
		return (true);

	m.insert(std::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(std::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(std::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(std::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(std::make_pair(static_cast<std::string>("first"), 69));

	m.clear();
	std::cerr << mtos(m);
	if (m.size() != 0 || m.empty() != true)
		return (true);

	return (false);
}

static int	test_erase(void)
{
	ft::map<std::string, int>	m;

	m.insert(ft::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(ft::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(ft::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(ft::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(ft::make_pair(static_cast<std::string>("first"), 69));

	if (m.erase("no") != false)
		return (true);
	if (m.size() != 5)
		return (true);

	if (m.erase("str1") != true
			|| m.erase("str2") != true
			|| m.erase("weird") != true)
		return (true);
	if (m.size() != 2)
		return (true);

	m.clear();
	if (m.size() != 0 || m.empty() != true)
		return (true);
	m.insert(ft::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(ft::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(ft::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(ft::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(ft::make_pair(static_cast<std::string>("first"), 69));

	ft::map<std::string, int>::iterator i = m.begin();
	m.erase(i);
	std::cerr << mtos(m) << std::endl;
	i = m.begin();
	++i;
	m.erase(i);
	std::cerr << mtos(m) << std::endl;

	m.erase(m.begin(), m.end());
	if (m.size() != 0 || m.empty() != true)
		return (true);

	FOR(TEST_SIZE)
	{
		std::ostringstream	ss;
		ss << "str" << i;
		m.insert(ft::make_pair(ss.str(), (int)i));
	}
	if (m.size() != TEST_SIZE)
		return (true);

	FOR(TEST_SIZE)
	{
		std::ostringstream	ss;
		ss << "str" << i;
		m.erase(ss.str());
	}
	if (m.size() != 0 || m.empty() != true)
		return (true);

	return (false);
}

static int	test_erase_std(void)
{
	std::map<std::string, int>	m;

	m.insert(std::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(std::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(std::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(std::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(std::make_pair(static_cast<std::string>("first"), 69));

	if (m.erase("no") != false)
		return (true);
	if (m.size() != 5)
		return (true);

	if (m.erase("str1") != true
			|| m.erase("str2") != true
			|| m.erase("weird") != true)
		return (true);
	if (m.size() != 2)
		return (true);

	m.clear();
	if (m.size() != 0 || m.empty() != true)
		return (true);
	m.insert(std::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(std::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(std::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(std::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(std::make_pair(static_cast<std::string>("first"), 69));

	std::map<std::string, int>::iterator i = m.begin();
	m.erase(i);
	std::cerr << mtos(m) << std::endl;
	i = m.begin();
	i++;
	m.erase(i);
	std::cerr << mtos(m) << std::endl;

	m.erase(m.begin(), m.end());
	if (m.size() != 0 || m.empty() != true)
		return (true);

	FOR(TEST_SIZE)
	{
		std::ostringstream	ss;
		ss << "str" << i;
		m.insert(std::make_pair(ss.str(), (int)i));
	}
	if (m.size() != TEST_SIZE)
		return (true);

	FOR(TEST_SIZE)
	{
		std::ostringstream	ss;
		ss << "str" << i;
		m.erase(ss.str());
	}
	if (m.size() != 0 || m.empty() != true)
		return (true);

	return (false);
}

static int	test_swap(void)
{
	ft::map<std::string, int>	m1;
	ft::map<std::string, int>	m2;

	FOR(42)
	{
		std::ostringstream	ss;
		ss << "str" << i;
		m1.insert(ft::make_pair(ss.str(), (int)i));
	}
	if (m1.size() != 42)
		return (true);

	FOR(69)
	{
		std::ostringstream	ss;
		ss << "str" << i;
		m2.insert(ft::make_pair(ss.str(), (int)i));
	}
	if (m2.size() != 69)
		return (true);

	m1.swap(m2);
	if (m1.size() != 69)
		return (true);
	if (m2.size() != 42)
		return (true);

	return (false);
}

static int	test_swap_std(void)
{
	std::map<std::string, int>	m1;
	std::map<std::string, int>	m2;

	FOR(42)
	{
		std::ostringstream	ss;
		ss << "str" << i;
		m1.insert(std::make_pair(ss.str(), (int)i));
	}
	if (m1.size() != 42)
		return (true);

	FOR(69)
	{
		std::ostringstream	ss;
		ss << "str" << i;
		m2.insert(std::make_pair(ss.str(), (int)i));
	}
	if (m2.size() != 69)
		return (true);

	m1.swap(m2);
	if (m1.size() != 69)
		return (true);
	if (m2.size() != 42)
		return (true);

	return (false);
}

static int	test_count(void)
{
	ft::map<std::string, int>	m;

	m.insert(ft::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(ft::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(ft::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(ft::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(ft::make_pair(static_cast<std::string>("first"), 69));

	if (m.count("str1") != true
			|| m.count("str2") != true
			|| m.count("weird") != true
			|| m.count("strange") != true
			|| m.count("first") != true)
		return (true);
	if (m.count("no") != false)
		return (true);

	return (false);
}

static int	test_count_std(void)
{
	std::map<std::string, int>	m;

	m.insert(std::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(std::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(std::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(std::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(std::make_pair(static_cast<std::string>("first"), 69));

	if (m.count("str1") != true
			|| m.count("str2") != true
			|| m.count("weird") != true
			|| m.count("strange") != true
			|| m.count("first") != true)
		return (true);
	if (m.count("no") != false)
		return (true);

	return (false);
}

static int	test_find(void)
{
	ft::map<std::string, int>	m;

	m.insert(ft::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(ft::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(ft::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(ft::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(ft::make_pair(static_cast<std::string>("first"), 69));

	if (m.find("str1")->second != 42
			|| m.find("str2")->second != -21
			|| m.find("weird")->second != 84
			|| m.find("strange")->second != 0
			|| m.find("first")->second != 69)
		return (true);
	if (m.find("no") != m.end())
		return (true);

	return (false);
}

static int	test_find_std(void)
{
	std::map<std::string, int>	m;

	m.insert(std::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(std::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(std::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(std::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(std::make_pair(static_cast<std::string>("first"), 69));

	if (m.find("str1")->second != 42
			|| m.find("str2")->second != -21
			|| m.find("weird")->second != 84
			|| m.find("strange")->second != 0
			|| m.find("first")->second != 69)
		return (true);
	if (m.find("no") != m.end())
		return (true);

	return (false);
}

static int	test_kv_comp(void)
{
	ft::map<std::string, int>					m;
	ft::map<std::string, int>::key_compare		key_comp = m.key_comp();
	ft::map<std::string, int>::value_compare	value_comp = m.value_comp();

	if (key_comp("str1", "str1") != false)
		return (true);
	if (key_comp("str1", "str2") != true)
		return (true);

	ft::pair<std::string, int>	p1(std::string("str1"), 1);
	ft::pair<std::string, int>	p2(std::string("str2"), 2);

	if (value_comp(p1, p2) != true)
		return (true);

	return (false);
}

static int	test_kv_comp_std(void)
{
	std::map<std::string, int>					m;
	std::map<std::string, int>::key_compare		key_comp = m.key_comp();
	std::map<std::string, int>::value_compare	value_comp = m.value_comp();

	if (key_comp("str1", "str1") != false)
		return (true);
	if (key_comp("str1", "str2") != true)
		return (true);

	std::pair<std::string, int>	p1(std::string("str1"), 1);
	std::pair<std::string, int>	p2(std::string("str2"), 2);

	if (value_comp(p1, p2) != true)
		return (true);

	return (false);
}

static int	test_get_alloc(void)
{
	ft::map<std::string, int>					m;
	ft::map<std::string, int>::allocator_type	alloc = m.get_allocator();

	return (alloc.max_size());
}

static int	test_get_alloc_std(void)
{
	std::map<std::string, int>					m;
	std::map<std::string, int>::allocator_type	alloc = m.get_allocator();

	return (alloc.max_size());
}

static int	test_lb(void)
{
	ft::map<std::string, int>	m;

	m.insert(ft::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(ft::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(ft::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(ft::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(ft::make_pair(static_cast<std::string>("first"), 69));

	if (m.lower_bound("str1")->second != 42
			|| m.lower_bound("str2")->second != -21
			|| m.lower_bound("weird")->second != 84
			|| m.lower_bound("strange")->second != 0
			|| m.lower_bound("first")->second != 69)
		return (true);
	if (m.lower_bound("no")->second != 42)
		return (true);

	return (false);
}

static int	test_lb_std(void)
{
	std::map<std::string, int>	m;

	m.insert(std::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(std::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(std::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(std::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(std::make_pair(static_cast<std::string>("first"), 69));

	if (m.lower_bound("str1")->second != 42
			|| m.lower_bound("str2")->second != -21
			|| m.lower_bound("weird")->second != 84
			|| m.lower_bound("strange")->second != 0
			|| m.lower_bound("first")->second != 69)
		return (true);
	if (m.lower_bound("no")->second != 42)
		return (true);

	return (false);
}

static int	test_ub(void)
{
	ft::map<std::string, int>	m;

	m.insert(ft::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(ft::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(ft::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(ft::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(ft::make_pair(static_cast<std::string>("first"), 69));

	if (m.upper_bound("str1")->second != -21
			|| m.upper_bound("str2")->second != 0
			/*|| m.upper_bound("weird")->second != (random because last)*/
			|| m.upper_bound("strange")->second != 84
			|| m.upper_bound("first")->second != 42)
		return (true);
	if (m.upper_bound("no")->second != 42)
		return (true);

	return (false);
}

static int	test_ub_std(void)
{
	std::map<std::string, int>	m;

	m.insert(std::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(std::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(std::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(std::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(std::make_pair(static_cast<std::string>("first"), 69));

	if (m.upper_bound("str1")->second != -21
			|| m.upper_bound("str2")->second != 0
			/*|| m.upper_bound("weird")->second != (random because last)*/
			|| m.upper_bound("strange")->second != 84
			|| m.upper_bound("first")->second != 42)
		return (true);
	if (m.upper_bound("no")->second != 42)
		return (true);

	return (false);
}

static int	test_equal_range(void)
{
	ft::map<std::string, int>	m;

	m.insert(ft::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(ft::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(ft::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(ft::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(ft::make_pair(static_cast<std::string>("first"), 69));

	if (m.equal_range("str1").first->first != "str1"
			|| m.equal_range("str1").second->first != "str2"
			|| m.equal_range("str2").first->first != "str2"
			|| m.equal_range("str2").second->first != "strange"
			|| m.equal_range("weird").first->first != "weird"
			//<< "weird|" << m.equal_range("weird").second->first << std::endl
			|| m.equal_range("strange").first->first != "strange"
			|| m.equal_range("strange").second->first != "weird"
			|| m.equal_range("first").first->first != "first"
			|| m.equal_range("first").second->first != "str1"
			|| m.equal_range("no").first->first != "str1"
			|| m.equal_range("no").second->first != "str1")
		return (true);

	return (false);
}

static int	test_equal_range_std(void)
{
	std::map<std::string, int>	m;

	m.insert(std::make_pair(static_cast<std::string>("str1"), 42));
	m.insert(std::make_pair(static_cast<std::string>("str2"), -21));
	m.insert(std::make_pair(static_cast<std::string>("weird"), 84));
	m.insert(std::make_pair(static_cast<std::string>("strange"), 0));
	m.insert(std::make_pair(static_cast<std::string>("first"), 69));

	if (m.equal_range("str1").first->first != "str1"
			|| m.equal_range("str1").second->first != "str2"
			|| m.equal_range("str2").first->first != "str2"
			|| m.equal_range("str2").second->first != "strange"
			|| m.equal_range("weird").first->first != "weird"
			//<< "weird|" << m.equal_range("weird").second->first << std::endl
			|| m.equal_range("strange").first->first != "strange"
			|| m.equal_range("strange").second->first != "weird"
			|| m.equal_range("first").first->first != "first"
			|| m.equal_range("first").second->first != "str1"
			|| m.equal_range("no").first->first != "str1"
			|| m.equal_range("no").second->first != "str1")
		return (true);

	return (false);
}

static int	test_relational(void)
{
	ft::map<std::string, int>	m1;
	ft::map<std::string, int>	m2;

	FOR(42)
	{
		std::ostringstream	ss;
		ss << "str" << i;
		m1.insert(ft::make_pair(ss.str(), (int)i));
	}
	if (m1.size() != 42)
		return (true);

	FOR(42)
	{
		std::ostringstream	ss;
		ss << "no" << i;
		m2.insert(ft::make_pair(ss.str(), (int)i));
	}
	if (m2.size() != 42)
		return (true);

	if (m1 != m1 || m1 == m2)
		return (true);
	if (m1 < m2 || m1 < m1)
		return (true);
	if (m1 <= m2)
		return (true);
	if (m2 > m1 || m1 > m1)
		return (true);
	if (m2 >= m1)
		return (true);

	return (false);
}

static int	test_relational_std(void)
{
	std::map<std::string, int>	m1;
	std::map<std::string, int>	m2;

	FOR(42)
	{
		std::ostringstream	ss;
		ss << "str" << i;
		m1.insert(std::make_pair(ss.str(), (int)i));
	}
	if (m1.size() != 42)
		return (true);

	FOR(42)
	{
		std::ostringstream	ss;
		ss << "no" << i;
		m2.insert(std::make_pair(ss.str(), (int)i));
	}
	if (m2.size() != 42)
		return (true);

	if (m1 != m1 || m1 == m2)
		return (true);
	if (m1 < m2 || m1 < m1)
		return (true);
	if (m1 <= m2)
		return (true);
	if (m2 > m1 || m1 > m1)
		return (true);
	if (m2 >= m1)
		return (true);

	return (false);
}

static int	test_swap_nm(void)
{
	ft::map<std::string, int>	m1;
	ft::map<std::string, int>	m2;

	FOR(5)
	{
		std::ostringstream	ss;
		ss << "str" << i;
		m1.insert(ft::make_pair(ss.str(), (int)i));
	}
	if (m1.size() != 5)
		return (true);

	FOR(3)
	{
		std::ostringstream	ss;
		ss << "no" << i;
		m2.insert(ft::make_pair(ss.str(), (int)i));
	}
	if (m2.size() != 3)
		return (true);

	m1.swap(m2);

	if (m1.size() != 3 || m2.size() != 5)
		return (true);

	std::cerr << mtos(m1) << std::endl << mtos(m2) << std::endl;

	return (false);
}

static int	test_swap_nm_std(void)
{
	std::map<std::string, int>	m1;
	std::map<std::string, int>	m2;

	FOR(5)
	{
		std::ostringstream	ss;
		ss << "str" << i;
		m1.insert(std::make_pair(ss.str(), (int)i));
	}
	if (m1.size() != 5)
		return (true);

	FOR(3)
	{
		std::ostringstream	ss;
		ss << "no" << i;
		m2.insert(std::make_pair(ss.str(), (int)i));
	}
	if (m2.size() != 3)
		return (true);

	m1.swap(m2);

	if (m1.size() != 3 || m2.size() != 5)
		return (true);

	std::cerr << mtos(m1) << std::endl << mtos(m2) << std::endl;

	return (false);
}

bool	test_map(void)
{
	bool	ret;

	ret = false;
	ret |= tl("basic", &test_basic, &test_basic_std);
	ret |= tl("insert", &test_insert, &test_insert_std);
	ret |= tl("assign", &test_assign, &test_assign_std);
	ret |= tl("iterator", &test_m_iterator, &test_m_iterator_std);
	ret |= tl("size related", &test_size, &test_size_std);
	ret |= tl("access", &test_access, &test_access_std);
	ret |= tl("at", &test_at, &test_at_std);
	ret |= tl("clear", &test_clear, &test_clear_std);
	ret |= tl("erase", &test_erase, &test_erase_std);
	ret |= tl("swap", &test_swap, &test_swap_std);
	ret |= tl("count", &test_count, &test_count_std);
	ret |= tl("find", &test_find, &test_find_std);
	ret |= tl("key and value compare", &test_kv_comp, &test_kv_comp_std);
	ret |= tl("get allocator", &test_get_alloc, &test_get_alloc_std);
	ret |= tl("lower bound", &test_lb, &test_lb_std);
	ret |= tl("upper bound", &test_ub, &test_ub_std);
	ret |= tl("equal range", &test_equal_range, &test_equal_range_std);
	ret |= tl("relational operator", &test_relational, &test_relational_std);
	ret |= tl("swap non member", &test_swap_nm, &test_swap_nm_std);

	return (ret);
}
