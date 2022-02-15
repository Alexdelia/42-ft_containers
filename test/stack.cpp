/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:28:29 by adelille          #+#    #+#             */
/*   Updated: 2022/02/15 16:40:59 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

static int	test_ppest(void)
{
	ft::stack<int>	s;

	if (s.empty() != true || s.size() != 0)
		return (true);

	FOR(100)
		s.push(i);
	if (s.empty() != false || s.size() != 100)
		return (true);

	FOR(42)
		s.pop();
	if (s.empty() != false || s.size() != 58 || s.top() != 57)
		return (true);

	return (false);
}

static int	test_ppest_std(void)
{
	std::stack<int>	s;

	if (s.empty() != true || s.size() != 0)
		return (true);

	FOR(100)
		s.push(i);
	if (s.empty() != false || s.size() != 100)
		return (true);

	FOR(42)
		s.pop();
	if (s.empty() != false || s.size() != 58 || s.top() != 57)
		return (true);

	return (false);
}

static int	test_oc(void)
{
	ft::stack<int, std::vector<int> >	s1;
	std::vector<int>					v(5, 42);
	ft::stack<int, std::vector<int> >	s2(v);

	if (s1.empty() != true || s1.size() != 0)
		return (true);

	FOR(100)
		s1.push(i);
	if (s1.empty() != false || s1.size() != 100)
		return (true);

	FOR(42)
		s1.pop();
	if (s1.empty() != false || s1.size() != 58 || s1.top() != 57)
		return (true);

	if (s2.empty() != false || s2.size() != 5 || s2.top() != 42)
		return (true);

	return (false);
}

static int	test_oc_std(void)
{
	std::stack<int, std::vector<int> >	s1;
	std::vector<int>					v(5, 42);
	std::stack<int, std::vector<int> >	s2(v);

	if (s1.empty() != true || s1.size() != 0)
		return (true);

	FOR(100)
		s1.push(i);
	if (s1.empty() != false || s1.size() != 100)
		return (true);

	FOR(42)
		s1.pop();
	if (s1.empty() != false || s1.size() != 58 || s1.top() != 57)
		return (true);

	if (s2.empty() != false || s2.size() != 5 || s2.top() != 42)
		return (true);

	return (false);
}

static int	test_ro(void)
{
	ft::stack<int>	s1;
	ft::stack<int>	s2;
	ft::stack<int>	s3;
	ft::stack<int>	s4;

	FOR(10)
		s1.push(i);
	FOR(10)
		s2.push(i);
	FOR(10)
		s3.push(3);
	FOR(10)
		s4.push(4);

	if (!(s1 == s2) || !(s1 >= s2) || !(s1 <= s2) || (s1 != s2))
		return (true);
	if (!(s1 != s3) || (s1 > s3) || (s1 >= s3))
		return (true);
	if (!(s1 < s4) || !(s1 <= s4))
		return (true);

	return (false);
}

static int	test_ro_std(void)
{
	std::stack<int>	s1;
	std::stack<int>	s2;
	std::stack<int>	s3;
	std::stack<int>	s4;

	FOR(10)
		s1.push(i);
	FOR(10)
		s2.push(i);
	FOR(10)
		s3.push(3);
	FOR(10)
		s4.push(4);

	if (!(s1 == s2) || !(s1 >= s2) || !(s1 <= s2) || (s1 != s2))
		return (true);
	if (!(s1 != s3) || (s1 > s3) || (s1 >= s3))
		return (true);
	if (!(s1 < s4) || !(s1 <= s4))
		return (true);

	return (false);
}

bool	test_stack(void)
{
	bool	ret;

	ret = false;
	ret |= tl("push, pop, empty, size, top", &test_ppest, test_ppest_std);
	ret |= tl("other container", &test_oc, &test_oc_std);
	ret |= tl("relational operator", &test_ro, &test_ro_std);

	return (ret);
}
