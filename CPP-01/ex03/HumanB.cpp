/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:18:23 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 21:17:10 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string a)
{
	name = a;
	_weapon = NULL;
}

HumanB::~HumanB()
{

}
void HumanB::setWeapon(Weapon &a)
{
	this->_weapon = &a;
}

void HumanB::attack()
{
	if (_weapon == NULL)
		std::cout << name << " attacks with their" << " hands" << std::endl;
	else
		std::cout << name << " attacks with their " << _weapon->getType() << std::endl;
}