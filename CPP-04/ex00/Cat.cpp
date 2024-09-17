/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:39:21 by aranger           #+#    #+#             */
/*   Updated: 2024/05/12 20:29:11 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat : Default constructor called" << std::endl;	
	this->_type = "Cat";
}
Cat::Cat(const Cat &Copy) : Animal()
{
	std::cout << "Cat : Copy constructor called" << std::endl;
	*this = Copy;
}
Cat::~Cat()
{
	std::cout << "Cat : Destructor called" << std::endl;
}
Cat& Cat::operator=(const Cat &ToCopy)
{
	this->_type = ToCopy._type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "MIAAAAOAOUUUOUOU WOUAF WOUAF" << std::endl;
}