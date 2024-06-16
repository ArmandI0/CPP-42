/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:05:20 by aranger           #+#    #+#             */
/*   Updated: 2024/06/16 14:24:12 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef easyfind_hpp
#define easyfind_hpp
# include <vector>
# include <algorithm>
# include <iostream>
# include <iterator>

template <typename T>
typename T::iterator	easyfind(T & a, int b);

#endif