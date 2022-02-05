/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:11:59 by adelille          #+#    #+#             */
/*   Updated: 2022/02/05 16:47:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void	test_start(const std::string &name)
{
	std::cout << C_BOLD << C_MAGENTA << "\t[" << name << "]" << C_RESET << std::endl;
	clock_gettime(CLOCK_MONOTONIC, &start);
}

double	test_end(bool p)
{
	struct timespec	end;
	double			time;

	clock_gettime(CLOCK_MONOTONIC, &end);
	time = ((end.tv_sec - start.tv_sec * 1e9)
			+ (end.tv_nsec - start.tv_nsec)) * 1e-9;
	if (p)
		std::cout << C_BOLD << C_CYAN << "\t[time: " << std::fixed << time
			<< "]" << C_RESET << std::endl;
	else	
		std::cout << C_BOLD << C_BLUE << "\t[std time: " << std::fixed << time
			<< "]" << C_RESET << std::endl;
	return (time);
}

bool	tl(const std::string &name, bool (*f)(void), bool (*f_std)(void))
{
	bool	ret;
	double	time;

	test_start(name);
	ret = f();
	time = test_end(true);
	if (f_std)
	{
		ret = true;
		clock_gettime(CLOCK_MONOTONIC, &start);
		if (ret != f_std())
			std::cout << C_BOLD << C_RED << "[✗]" << C_RESET << std::endl;
		else if (time * 20 > test_end(false))
			std::cout << C_BOLD << C_YELLOW << "[⌛]" << C_RESET << std::endl;
		else
		{
			std::cout << C_BOLD << C_GREEN << "[✔]" << C_RESET << std::endl;
			ret = false;
		}
	}
	return (ret);
}

bool	ts(const std::string &name, bool (*f)(void))
{
	bool	ret;

	std::cout << std::endl << C_BOLD << C_MAGENTA << C_UNDERLINE
		<< "\t[" << name << "]" << C_RESET << std::endl;
	ret = f();
	if (ret)
		std::cout << C_BOLD << C_RED << "[KO]" << C_RESET << std::endl;
	else	
		std::cout << C_BOLD << C_GREEN << "[OK]" << C_RESET << std::endl;
	return (ret);
}
