/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:05:03 by adelille          #+#    #+#             */
/*   Updated: 2022/02/06 12:18:46 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# include "color.hpp"

# include <iostream>
//# include <numeric>
# include <chrono> // cpp+11 to get time
# include <unistd.h>
# include <sys/ioctl.h>

# include <vector>

# include "../src/random_access_iterator.hpp"
# include "../src/reverse_iterator.hpp"
# include "../src/iterator_traits.hpp"
# include "../src/vector.hpp"

bool	ts(const std::string &name, bool (*f)(void));
bool	tl(const std::string &name, int (*f)(void), int (*f_std)(void));

bool	test_iterator(void);
bool	test_enable_if_is_integral(void);
bool	test_vector(void);

#endif
