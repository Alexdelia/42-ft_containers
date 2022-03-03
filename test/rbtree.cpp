/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:21:14 by adelille          #+#    #+#             */
/*   Updated: 2022/03/03 18:41:36 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

bool	test_rbtree(void)
{
	ft::_rb_tree<int, std::less<int> >	t1;

	FOR(10)
	{
		t1.insert(i);
		if (t1.size() != i + 1)
			return (true);
	}

	if (*t1.find(5) != 5)
		return (true);
	if (t1.find(42) != t1.end())
		return (true);
	if (t1.size() != 10)
		return (true);
	
	ft::_rb_tree<int, std::less<int> >	t2(t1);

	if (t2.size() != 20)
		return (true);
	
	FOR(10)
	{
		t1.erase(i);
		if (t1.size() != 9 - i)
			return (true);
	}
	
	if (t1.size() != 0)
		return (true);

	t2 = t1;
	
	if (t2.size() != 0)
		return (true);

	return (false);
}
