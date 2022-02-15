/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:02:00 by adelille          #+#    #+#             */
/*   Updated: 2022/02/15 13:27:36 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

// https://www.cplusplus.com/reference/stack/stack/

namespace ft
{
	template <class T, class Container = ft::vector<T> >
		class stack
		{
			public:
				typedef T									value_type;
				typedef Container							container_type;
				typedef typename container_type::size_type	size_type;

			protected:
				container_type	c;

			public:
				explicit stack(const container_type &ctnr = container_type()) : c(ctnr) {}
				stack(const stack &other) : c(other.c) {}
				~stack(void) {}

				stack	&operator=(const stack &other)
				{
					if (this != &other)
						c = other.c;
					return (*this);
				}

				bool	empty(void) const
				{return (c.empty());}
				size_type	size(void) const
				{return (c.size());}
				value_type	&top(void)
				{return (c.back());}
				const value_type	&tope(void) const
				{return (c.back());}

				void	push(const value_type &val)
				{c.push_back(val);}
				void	pop(void)
				{c.pop_back();}

				template <class U, class V>
					friend bool	operator==(const stack<U, V> &, const stack<U, V> &);
				template <class U, class V>
					friend bool	operator!=(const stack<U, V> &, const stack<U, V> &);
				template <class U, class V>
					friend bool	operator<(const stack<U, V> &, const stack<U, V> &);
				template <class U, class V>
					friend bool	operator>(const stack<U, V> &, const stack<U, V> &);
				template <class U, class V>
					friend bool	operator<=(const stack<U, V> &, const stack<U, V> &);
				template <class U, class V>
					friend bool	operator>=(const stack<U, V> &, const stack<U, V> &);
		};
	template <class T, class Container>
		bool	operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{return (lhs.c == rhs.c);}
	template <class T, class Container>
		bool	operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{return (lhs.c != rhs.c);}
	template <class T, class Container>
		bool	operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{return (lhs.c < rhs.c);}
	template <class T, class Container>
		bool	operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{return (lhs.c <= rhs.c);}
	template <class T, class Container>
		bool	operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{return (lhs.c > rhs.c);}
	template <class T, class Container>
		bool	operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{return (lhs.c >= rhs.c);}
}

#endif
