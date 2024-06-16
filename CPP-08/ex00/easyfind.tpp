/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:56:51 by aranger           #+#    #+#             */
/*   Updated: 2024/06/16 14:23:55 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T & a, int b)
{
	typename T::iterator it;
	it = std::find(a.begin(), a.end(), b);
	if (it == a.end())
		throw std::invalid_argument("Error");
	return (it);
}

