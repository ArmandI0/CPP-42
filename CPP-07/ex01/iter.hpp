/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:47:13 by aranger           #+#    #+#             */
/*   Updated: 2024/06/08 18:24:18 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef iter_hpp
# define iter_hpp
# include <iostream>

template <typename T, typename F> 
void	iter(T *array, size_t lenght, F f)
{
	for (int i = 0; i < 4; i++)
	{
		f(T[i]);
	}
}

#endif