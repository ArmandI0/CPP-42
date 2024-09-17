/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:38:38 by armandanger       #+#    #+#             */
/*   Updated: 2024/05/10 11:11:37 by aranger          ###   ########.fr       */
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
	
	int		getRawBits(void)	const;
	void	setRawBits(int const raw);
	float	toFloat(void)	const;
	int		toInt(void)		const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fix);

#endif