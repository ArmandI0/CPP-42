/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:01:50 by aranger           #+#    #+#             */
/*   Updated: 2024/06/08 17:22:46 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef functions_hpp
#define functions_hpp

template <typename T> 
void swap(T & a, T & b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T& min(T const & a, T const & b)
{
	if (a <= b)
		return a;
	else
		return b;
}

template <typename T>
const T& max(T const & a, T const & b)
{
	if (a >= b)
		return a;
	else
		return b;
}

#endif