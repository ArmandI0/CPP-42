/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:17:06 by aranger           #+#    #+#             */
/*   Updated: 2024/05/12 20:31:31 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal : Default constructor called" << std::endl;
}
Animal::Animal(const Animal &Copy)
{
	std::cout << "Animal : Copy constructor called" << std::endl;
	*this = Copy;
}
Animal::~Animal()
{
	std::cout << "Animal : Destructor called" << std::endl;
}
Animal& Animal::operator=(const Animal &ToCopy)
{
	this->_type = ToCopy._type;
	return *this;
}

std::string Animal::gettype() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "......" << std::endl;
}