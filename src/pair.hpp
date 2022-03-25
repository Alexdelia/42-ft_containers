/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:28:20 by adelille          #+#    #+#             */
/*   Updated: 2022/03/25 17:57:28 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

// https://www.cplusplus.com/reference/utility/pair/pair/

namespace ft
{
	template <typename T, typename U>
		class pair
		{
			public:
				typedef T	first_type;
				typedef U	second_type;

				first_type	first;
				second_type	second;

				pair() : first(first_type()), second(second_type()) {};
				pair(const first_type &x, const second_type &y) : first(x), second(y) {};
				pair(const pair &p) : first(p.first), second(p.second) {};
				~pair() {};

				pair	&operator=(const pair &p)
				{
					first = p.first;
					second = p.second;
					return (*this);
				}
		};

	template <class T1, class T2>
		pair<T1, T2>	make_pair(T1 const &t1, T2 const &t2)
		{ return (ft::pair<T1, T2>(t1, t2)); };

	template <class T1, class T2>
		bool	operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
		{return (lhs.first == rhs.first && lhs.second == rhs.second);}
	template <class T1, class T2>
		bool	operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
		{return (lhs.first != rhs.first || lhs.second != rhs.second);}
	template <class T1, class T2>
		bool	operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));}
	template <class T1, class T2>
		bool	operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
		{return (lhs.first <= rhs.first || lhs.second <= rhs.second);}
	template <class T1, class T2>
		bool	operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
		{return (lhs.first > rhs.first || lhs.second > rhs.second);}
	template <class T1, class T2>
		bool	operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
		{return (lhs.first >= rhs.first || lhs.second >= rhs.second);}
}

#endif
