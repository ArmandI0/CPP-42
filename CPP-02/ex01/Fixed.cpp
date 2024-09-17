/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:39:44 by armandanger       #+#    #+#             */
/*   Updated: 2024/05/10 16:03:11 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_Nb = 0;
}
Fixed::Fixed(const int Nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->_Nb = (Nb << 8);
}
Fixed::Fixed(const float Nb)
{
	int tmp;
	int	aft;

	std::cout << "Float constructor called" << std::endl;
	tmp = int(Nb);
	aft = roundf((Nb - tmp) * (1 << this->_bits));
	this->_Nb = (tmp << this->_bits) | (int)aft;
}

Fixed::Fixed(const Fixed &Cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = Cpy;
}

Fixed& Fixed::operator=(const Fixed &ToCopy)
{
	std::cout << "Copy assignment operator called" << std::endl;

	this->_Nb = ToCopy._Nb;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;

}

int	Fixed::getRawBits(void) const
{
	return (this->_Nb);
}

void Fixed::setRawBits(int const raw)
{
	this->_Nb = (raw << 8);
}

float	Fixed::toFloat(void) const
{
	float tmp;

	tmp = (float)(this->_Nb) / (1 << this->_bits);
	return tmp;
}

int	Fixed::toInt(void) const
{
	return (this->_Nb >> 8);	
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
	os << fix.toFloat();
	return os;
}
