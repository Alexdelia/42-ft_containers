/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:05:03 by adelille          #+#    #+#             */
/*   Updated: 2022/02/05 16:40:07 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# include "color.hpp"

# include <iostream>

# include <vector>

# include "../src/vector.hpp"

struct timespec	start;

bool	tl(const std::string &name, bool (*f)(void), bool (*f_std)(void));
void	test_start(const std::string &name);
double	test_end(void);

#endif
