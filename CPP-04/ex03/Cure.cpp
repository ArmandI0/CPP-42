/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:25:43 by aranger           #+#    #+#             */
/*   Updated: 2024/05/16 21:33:58 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(Cure const &cpy)
{
	*this = cpy;
}

Cure& Cure::operator=(Cure const &cpy)
{
	this->_type = cpy._type;
	return *this;
}

Cure::~Cure()
{

}

AMateria* Cure::clone() const
{
	Cure *a = new Cure();
	return a;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals "<< target.getName() << "'s wounds *" << std::endl;
}
