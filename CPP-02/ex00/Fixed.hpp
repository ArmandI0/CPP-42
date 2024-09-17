/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:38:38 by armandanger       #+#    #+#             */
/*   Updated: 2024/05/03 15:44:31 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_hpp
#define Fixed_hpp
#include <iostream>

class Fixed
{
private:
	int	_Nb;
	static const int _bits = 8;
	
public:
	Fixed();
	Fixed(const Fixed &Copy);
	~Fixed();

	Fixed& operator=(const Fixed &ToCopy);

	int	getRawBits(void) const;
	void setRawBits(int const raw);
};




#endif