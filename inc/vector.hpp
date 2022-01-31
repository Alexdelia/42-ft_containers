/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:14:18 by adelille          #+#    #+#             */
/*   Updated: 2022/01/31 11:51:39 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
//# include <typeinfo>

class vector
{
	public:

		// default (1)
		explicit vector (const allocator_type& alloc = allocator_type());
		// fill (2)
		explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type());
		// range (3)
		template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type());
		// copy (4)
		vector (const vector& x);

		// destructor
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
