/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:28:29 by adelille          #+#    #+#             */
/*   Updated: 2022/02/15 13:34:00 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

static int	test_ppes(void)
{
	return (false);
}

bool	test_stack(void)
{
	bool	ret;

	ret = false;
	ret |= tl("push, pop, empty, size", &test_ppes, NULL);
	//ret |= tl("relational operator", NULL, NULL);

	return (ret);
}
