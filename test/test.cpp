/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:11:59 by adelille          #+#    #+#             */
/*   Updated: 2022/02/05 17:33:29 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

bool	tl(const std::string &name, bool (*f)(void), bool (*f_std)(void))
{
	bool							ret;
	bool							ret_std;
	std::chrono::duration<double>	diff;
	std::chrono::duration<double>	diff_std;

	std::cout << C_BOLD << C_MAGENTA << "\t[" << name << "]" << C_RESET << std::endl;
	{
		auto	start = std::chrono::high_resolution_clock::now();
		ret = f();
		diff = std::chrono::high_resolution_clock::now() - start;
		std::cout << C_BOLD << C_CYAN << "      [time: " << diff.count()
			<< "s]" << C_RESET << std::endl;
	}
	if (f_std)
	{
		auto	start = std::chrono::high_resolution_clock::now();
		ret_std = f_std();
		diff_std = std::chrono::high_resolution_clock::now() - start;
		std::cout << C_BOLD << C_BLUE << "  [std time: " << diff.count()
			<< "s]" << C_RESET << std::endl;
		if (ret != ret_std)
		{
			std::cout << C_BOLD << C_RED << "[✗]" << C_RESET << std::endl;
			return (true);
		}
		else if (diff.count() > diff_std.count() * 20)
		{
			std::cout << C_BOLD << C_YELLOW << "[⌛]" << C_RESET << std::endl;
			return (true);
		}
		else
		{
			std::cout << C_BOLD << C_GREEN << "[✔]" << C_RESET << std::endl;
			return (false);
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
