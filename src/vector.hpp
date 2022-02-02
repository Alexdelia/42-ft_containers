/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:14:18 by adelille          #+#    #+#             */
/*   Updated: 2022/02/02 13:36:28 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
//# include <typeinfo>
// iterator

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
		class vector
		{
			public:
				// typedef: https://cplusplus.com/reference/vector/vector/
				typedef T									value_type;
				typedef Alloc								allocator_type;
				typedef typename allocator_type::size_type	size_type;

				typedef /**/<value_type>              iterator;
				typedef /**/<value_type const>        const_iterator;
				typedef ft::reverse_iterator<iterator>           reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>     const_reverse_iterator;

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

}

#endif
