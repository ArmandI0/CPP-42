/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:16:37 by armandanger       #+#    #+#             */
/*   Updated: 2024/05/16 20:25:11 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	
}

Ice::Ice(Ice const &cpy)
{
	*this = cpy;
}

Ice::~Ice()
{
	
}

Ice& Ice::operator=(Ice const &cpy)
{
	this->_type = cpy._type;
	return *this;
}

AMateria* Ice::clone() const
{
	Ice *a = new Ice();
	return a;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
