/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:47:13 by aranger           #+#    #+#             */
/*   Updated: 2024/06/11 17:48:38 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef iter_hpp
# define iter_hpp
# include <iostream>

template <typename T, typename F> 
void	iter(T *array, size_t lenght, F f)
{
	if (array == NULL)
		return;
	for (size_t i = 0; i < lenght; i++)
	{
		f(array[i]);
	}
}

#endif