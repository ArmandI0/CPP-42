/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:29:24 by aranger           #+#    #+#             */
/*   Updated: 2024/05/17 16:15:44 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor()
{
	this->ObjFloor = NULL;
	std::cout << "Floor Constructor called." << std::endl;
}

Floor::Floor(AMateria* ptr)
{
	this->ObjFloor = ptr;
}

Floor::Floor(Floor const &cpy)
{
	std::cout << "Floor Copy constructor called." << std::endl;
	*this = cpy;
}

Floor & Floor::operator=(Floor const &cpy)
{
	if (this->ObjFloor != NULL)
		delete ObjFloor;
	this->ObjFloor = cpy.ObjFloor->clone();
	return *this;
}

Floor::~Floor()
{
	if (this->ObjFloor != NULL)
		delete ObjFloor;
	std::cout << "Floor Destructor called." << std::endl;
}
Floor* Floor::clone() const
{
	Floor *a = new Floor();
	return a;
}
