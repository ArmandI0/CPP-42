/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:39:44 by armandanger       #+#    #+#             */
/*   Updated: 2024/05/10 15:34:52 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_Nb = 0;
}

Fixed::Fixed(const Fixed &Cpy) :_Nb(Cpy._Nb)
{
	
}

Fixed& Fixed::operator=(const Fixed &ToCopy)
{
	std::cout << "Destructor called" << std::endl;
	this->_Nb = ToCopy._Nb;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Copy constructor called" << std::endl;

}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_Nb);
}

void Fixed::setRawBits(int const raw)
{
	this->_Nb = (raw << 8);
}