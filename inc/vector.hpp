/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:14:18 by adelille          #+#    #+#             */
/*   Updated: 2022/01/31 11:32:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
//# include <typeinfo>

class vector
{
	public:
		vector(void);
		vector(const vector &src);
		virtual ~vector(void);
		
		vector	&operator=(const vector &rhs);

	private: //
};

std::ostream	&operator<<(std::ostream &o, vector const &src);

#endif
