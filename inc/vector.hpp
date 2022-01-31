/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:14:18 by adelille          #+#    #+#             */
/*   Updated: 2022/01/31 11:43:05 by adelille         ###   ########.fr       */
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

		// element access

		// iterators
		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		// capacity

		// modifiers

	private: //
};

//std::ostream	&operator<<(std::ostream &o, vector const &src);

template< class T, class Alloc >
bool	operator==(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
bool	operator!=(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
bool	operator<(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
bool	operator<=(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
bool	operator>(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
bool	operator>=(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);

// std::swap
template< class T, class Alloc >
void	swap( std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs );

#endif
