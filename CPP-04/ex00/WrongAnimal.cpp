/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:56:44 by aranger           #+#    #+#             */
/*   Updated: 2024/05/12 19:57:59 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal : Copy constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &Copy)
{
	std::cout << "WrongAnimal : Copy constructor called" << std::endl;
	*this = Copy;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal : Destructor called" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &ToCopy)
{
	this->_type = ToCopy._type;
	return *this;
}

std::string WrongAnimal::gettype() const
{
	return (this->_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal sound" << std::endl;
}