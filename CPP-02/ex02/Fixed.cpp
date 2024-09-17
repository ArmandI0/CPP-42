/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:39:44 by armandanger       #+#    #+#             */
/*   Updated: 2024/05/12 15:15:16 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_Nb = 0;
}
Fixed::Fixed(const int Nb)
{
	this->_Nb = (Nb << this->_bits);
}
Fixed::Fixed(const float Nb)
{
	int tmp;
	int	aft;

	tmp = int(Nb);
	aft = roundf((Nb - tmp) * (1 << this->_bits));
	this->_Nb = (tmp << this->_bits) | (int)aft;
}

Fixed::Fixed(const Fixed &Cpy)
{
	*this = Cpy;
}

Fixed& Fixed::operator=(const Fixed &ToCopy)
{
	this->_Nb = ToCopy._Nb;
	return *this;
}

Fixed::~Fixed()
{
	
}

int	Fixed::getRawBits(void) const
{
	return (this->_Nb);
}

void Fixed::setRawBits(int const raw)
{
	this->_Nb = (raw << this->_bits);
}

float	Fixed::toFloat(void) const
{
	float tmp;

	tmp = (float)(this->_Nb) / (1 << this->_bits);
	return tmp;
}

int	Fixed::toInt(void) const
{
	return (this->_Nb >> this->_bits);	
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
	os << fix.toFloat();
	return os;
}

/* OVERLOAD COMPARISONS OPERATOR */

bool Fixed::operator>(const Fixed &Fix) const
{
	if (this->toFloat() > Fix.toFloat())
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &Fix) const
{
	if (this->toFloat() < Fix.toFloat())
		return true;
	return false;
}
bool Fixed::operator>=(const Fixed &Fix) const
{
	if (this->toFloat() >= Fix.toFloat())
		return true;
	return false;	
}
bool Fixed::operator<=(const Fixed &Fix) const
{
	if (this->toFloat() <= Fix.toFloat())
		return true;
	return false;	
}
bool Fixed::operator==(const Fixed &Fix) const
{
	if (this->toFloat() == Fix.toFloat())
		return true;
	return false;	
}
bool Fixed::operator!=(const Fixed &Fix) const
{
	if (this->toFloat() != Fix.toFloat())
		return true;
	return false;	
}

/* OVERLOAD OPERATORS*/

Fixed Fixed::operator+(const Fixed &Fix) const
{
	return Fixed(this->toFloat() + Fix.toFloat());
}
Fixed Fixed::operator-(const Fixed &Fix) const
{
	return Fixed(this->toFloat() - Fix.toFloat());
}
Fixed Fixed::operator*(const Fixed &Fix) const
{
	return Fixed(this->toFloat() * Fix.toFloat());
}

Fixed Fixed::operator/(const Fixed &Fix) const
{
	return Fixed(this->toFloat() / Fix.toFloat());
}

/* INCREMENTS OPERATOR */

Fixed Fixed::operator++()
{
	++this->_Nb;
    return (*this);
}		

Fixed Fixed::operator--()
{
	--this->_Nb;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed cpy(*this);
	this->_Nb++;
	return(cpy);
}

Fixed Fixed::operator--(int)
{
	Fixed cpy(*this);
	this->_Nb--;
	return(cpy);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return a;
	else
		return b;
}
Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return a;
	else
		return b;	
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return a;
	else
		return b;
}