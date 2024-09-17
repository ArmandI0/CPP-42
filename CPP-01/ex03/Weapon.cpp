/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:10:44 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 21:17:59 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string typ) : type(typ) {}

Weapon::~Weapon()
{
	
}

const std::string &Weapon::getType() const
{
	return (type);
}		
		
void Weapon::setType(std::string w_type)
{
	type = w_type;
}
