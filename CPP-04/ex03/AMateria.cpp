/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:21:22 by armandanger       #+#    #+#             */
/*   Updated: 2024/05/17 21:12:54 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{

}
 
AMateria::AMateria(std::string const & type) : _type(type)
{

}

AMateria::AMateria(const AMateria &Cpy)
{
	*this = Cpy;
}

AMateria& AMateria::operator=(AMateria const &cpy)
{
	this->_type = cpy._type;
	return *this;
}

std::string const& AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
