/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:45:03 by aranger           #+#    #+#             */
/*   Updated: 2024/05/12 20:30:09 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog : Default constructor called" << std::endl;	
	this->_type = "Dog";
}

Dog::Dog(const Dog &Copy) : Animal ()
{
	std::cout << "Dog : Copy constructor called" << std::endl;
	*this = Copy;
}
Dog::~Dog()
{
	std::cout << "Dog : Destructor called" << std::endl;
}
Dog& Dog::operator=(const Dog &ToCopy)
{
	this->_type = ToCopy._type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "WOUUUUAFFFFFFFFEEEEEEEE" << std::endl;
}