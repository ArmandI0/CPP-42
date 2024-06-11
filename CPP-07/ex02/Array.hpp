/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:56:10 by aranger           #+#    #+#             */
/*   Updated: 2024/06/11 16:42:06 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Array_hpp
#define Array_hpp
#include <iostream>

template <typename T>
class Array
{
	private:
		T *_array;
		size_t _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &toCopy);
		~Array();
		
		Array<T>& operator=(const Array<T> &toCopy);
		T& operator[](size_t i);
		size_t	size() const;
};

#endif
