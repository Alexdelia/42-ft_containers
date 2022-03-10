/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:11:59 by adelille          #+#    #+#             */
/*   Updated: 2022/03/10 12:45:43 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#ifdef STD11
bool	tl(const std::string &name, int (*f)(void), int (*f_std)(void))
{
	int								ret;
	int								ret_std;
	std::chrono::duration<double>	diff;
	std::chrono::duration<double>	diff_std;
	struct winsize					w;
	int								indent;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	indent = w.ws_col - 9 - name.size();
	std::cout << C_BOLD << C_MAGENTA << C_DIM << "  [" + name + "]"
		<< std::string((indent < 1 ? 1 : indent), ' ') << C_RESET;
	std::cerr << std::endl;
	{
		auto	start = std::chrono::high_resolution_clock::now();
		ret = f();
		diff = std::chrono::high_resolution_clock::now() - start;
		std::cerr << C_BOLD << C_CYAN << "  [time:     " << diff.count()
			<< "s]" << C_RESET << std::endl;
	}
	if (f_std)
	{
		auto	start = std::chrono::high_resolution_clock::now();
		ret_std = f_std();
		diff_std = std::chrono::high_resolution_clock::now() - start;
		std::cerr << C_BOLD << C_BLUE << "  [std time: " << diff_std.count()
			<< "s]" << C_RESET << std::endl << "  ";
		if (ret != ret_std)
		{
			std::cout << C_BOLD << C_RED << "[✗]" << C_RESET << std::endl;
			std::cerr << std::endl;
			return (true);
		}
		else if (diff.count() > diff_std.count() * 20 /* + 0.1*/)
		{
			std::cout << C_BOLD << C_YELLOW << "[⌛]" << C_RESET << std::endl;
			std::cerr << std::endl;
			return (true);
		}
		else
		{
			std::cout << C_BOLD << C_GREEN << "[✔]" << C_RESET << std::endl;
			std::cerr << std::endl;
			return (false);
		}
	}
	return ((ret ? true : false));
}
#endif

#ifndef STD11
bool	tl(const std::string &name, int (*f)(void), int (*f_std)(void))
{
	int				ret;
	int				ret_std;
	struct winsize	w;
	int				indent;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	indent = w.ws_col - 9 - name.size();
	std::cout << C_BOLD << C_MAGENTA << C_DIM << "  [" + name + "]"
		<< std::string((indent < 1 ? 1 : indent), ' ') << C_RESET;
	std::cerr << std::endl;
	ret = f();
	if (f_std)
	{
		ret_std = f_std();
		if (ret != ret_std)
		{
			std::cout << C_BOLD << C_RED << "[✗]" << C_RESET << std::endl;
			std::cerr << std::endl;
			return (true);
		}
		else
		{
			std::cout << C_BOLD << C_GREEN << "[✔]" << C_RESET << std::endl;
			std::cerr << std::endl;
			return (false);
		}
	}
	return ((ret ? true : false));
}
#endif

bool	ts(const std::string &name, bool (*f)(void))
{
	bool	ret;

	std::cout << std::endl << C_BOLD << C_MAGENTA
		<< "\t[" << name << "]" << C_RESET << std::endl;
	std::cerr << std::endl;
	ret = f();
	std::cout << C_BOLD << "\t"
		<< (ret ? C_RED : C_GREEN) << (ret ? "[KO]" : "[OK]")
		<< C_RESET << std::endl;
	return (ret);
}
