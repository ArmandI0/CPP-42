/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:34:13 by aranger           #+#    #+#             */
/*   Updated: 2024/06/11 17:39:10 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0)
{
    this->_array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	this->_array = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T> &toCopy)
{
    this->_array = new T[toCopy.size()];
    this->_size = toCopy.size();
    for (size_t i = 0; i < toCopy.size(); i++)
    {
        this->_array[i] = toCopy._array[i];
    }
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->_array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &toCopy)
{
    delete [] this->_array;
    this->_array = new T[toCopy.size()];
    for (int i = 0; i < toCopy.size(); i++)
    {
        this->_array[i] = toCopy._array[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator [] (size_t i)
{
	if (i >= this->_size)
		throw std::out_of_range("ERROR : Index out of range");
	else
		return _array[i];
}

template <typename T>
size_t	Array<T>::size() const
{
    return this->_size;
}
