/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:11:59 by adelille          #+#    #+#             */
/*   Updated: 2022/02/05 18:21:34 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

bool	tl(const std::string &name, int (*f)(void), int (*f_std)(void))
{
	int								ret;
	int								ret_std;
	std::chrono::duration<double>	diff;
	std::chrono::duration<double>	diff_std;

	std::cout << C_BOLD << C_MAGENTA << "\t[" << name << "]" << C_RESET << std::endl;
	{
		auto	start = std::chrono::high_resolution_clock::now();
		ret = f();
		diff = std::chrono::high_resolution_clock::now() - start;
		std::cout << C_BOLD << C_CYAN << "  [time:     " << diff.count()
			<< "s]" << C_RESET << std::endl;
	}
	if (f_std)
	{
		auto	start = std::chrono::high_resolution_clock::now();
		ret_std = f_std();
		diff_std = std::chrono::high_resolution_clock::now() - start;
		std::cout << C_BOLD << C_BLUE << "  [std time: " << diff_std.count()
			<< "s]" << C_RESET << std::endl;
		if (ret != ret_std)
		{
			std::cout << C_BOLD << C_RED << "[✗]" << C_RESET << std::endl << std::endl;
			return (true);
		}
		else if (diff.count() > diff_std.count() * 20 /* + 0.1*/)
		{
			std::cout << C_BOLD << C_YELLOW << "[⌛]" << C_RESET << std::endl << std::endl;
			return (true);
		}
		else
		{
			std::cout << C_BOLD << C_GREEN << "[✔]" << C_RESET << std::endl << std::endl;
			return (false);
		}
	}
	return ((ret ? true : false));
}

bool	ts(const std::string &name, bool (*f)(void))
{
	bool	ret;

	std::cout << std::endl << C_BOLD << C_MAGENTA << C_UNDERLINE
		<< "\t[" << name << "]" << C_RESET << std::endl << std::endl;
	ret = f();
	std::cout << C_BOLD <<
		(ret ? C_RED : C_GREEN) << (ret ? "[KO]" : "[OK]")
		<< C_RESET << std::endl;
	return (ret);
}
