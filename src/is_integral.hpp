/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:09:18 by adelille          #+#    #+#             */
/*   Updated: 2022/02/03 17:16:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

// https://www.cplusplus.com/reference/type_traits/is_integral/

# ifdef __APPLE__
#  include <stdint.h>
# else
#  include <uchar.h>
# endif

namespace ft
{
	template <typename T>
		struct is_integral
		{const static bool value = false;};

	template <>
		struct is_integral<char>
		{const static bool value = true;};

	template <>	
		struct is_integral<char16_t>
		{const static bool value = true;};

	template <>
		struct is_integral<char32_t>
		{const static bool value = true;};

	template <>
		struct is_integral<wchar_t>
		{const static bool value = true;};

	template <>
		struct is_integral<short>
		{const static bool value = true;};

	template <>
		struct is_integral<int>
		{const static bool value = true;};

	template <>
		struct is_integral<long>
		{const static bool value = true;};

	template <>
		struct is_integral<long long>
		{const static bool value = true;};
}

#endif
