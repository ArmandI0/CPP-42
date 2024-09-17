/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:38:38 by armandanger       #+#    #+#             */
/*   Updated: 2024/05/12 15:13:04 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_hpp
#define Fixed_hpp
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	_Nb;
	static const int _bits = 8;
	
public:
	Fixed();
	Fixed(const int Nb);
	Fixed(const float Nb);
	Fixed(const Fixed &Copy);
	~Fixed();

	Fixed& operator=(const Fixed &ToCopy);
	bool operator>(const Fixed &Fix) const;
	bool operator<(const Fixed &Fix) const;
	bool operator>=(const Fixed &Fix) const;
	bool operator<=(const Fixed &Fix) const;
	bool operator==(const Fixed &Fix) const;
	bool operator!=(const Fixed &Fix) const;

	Fixed operator+(const Fixed &Fix) const;
	Fixed operator-(const Fixed &Fix) const;
	Fixed operator*(const Fixed &Fix) const;
	Fixed operator/(const Fixed &Fix) const;

	/* PREFIXE */
	Fixed operator++();		
	Fixed operator--();
	/* SUFFIXE */
	Fixed operator++(int);
	Fixed operator--(int);


	static Fixed& min(Fixed &a, Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);

	int		getRawBits(void)	const;
	void	setRawBits(int const raw);
	float	toFloat(void)	const;
	int		toInt(void)		const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fix);

#endif