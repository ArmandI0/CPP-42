/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:45:03 by aranger           #+#    #+#             */
/*   Updated: 2024/05/20 14:18:43 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog : Default constructor called" << std::endl;	
	this->_type = "Dog";
	this->_Brain = new Brain;
}

Dog::Dog(const Dog &Copy) : _Brain(new Brain(*Copy._Brain))
{
	std::cout << "Dog : Copy constructor called" << std::endl;
	this->_type = Copy._type;
}

Dog::~Dog()
{
	std::cout << "Dog : Destructor called" << std::endl;
	delete this->_Brain;
}

Dog& Dog::operator=(const Dog &ToCopy)
{
	if (this->_Brain != ToCopy._Brain)
	{
		delete this->_Brain;
		this->_Brain = new Brain(*ToCopy._Brain);
	}
	this->_type = ToCopy._type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "WOUUUUAFFFFFFFFEEEEEEEE" << std::endl;
}