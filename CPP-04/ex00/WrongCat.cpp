/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:58:26 by aranger           #+#    #+#             */
/*   Updated: 2024/05/12 19:58:49 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat : Default constructor called" << std::endl;	
	this->_type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat &Copy) : WrongAnimal()
{
	std::cout << "WrongCat : Copy constructor called" << std::endl;
	*this = Copy;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat : Destructor called" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat &ToCopy)
{
	this->_type = ToCopy._type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "PIOU PIOU, it's not a cat sound" << std::endl;
}