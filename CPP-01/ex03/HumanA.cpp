/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:44:32 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 20:42:09 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), _weapon(weapon)
{
	
}

HumanA::~HumanA()
{

}

void HumanA::attack()
{
	std::cout << name << "attacks with their" << _weapon.getType() << std::endl;
}
