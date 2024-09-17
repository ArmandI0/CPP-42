/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:41:23 by aranger           #+#    #+#             */
/*   Updated: 2024/05/13 18:07:29 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap : " << this->_Name << " Default constructor called" << std::endl;
	this->_Name = "No name";
	this->_AttackDmg = 30;
	this->_EnergyPoints = 100;
	this->_HitPoints = 100;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
	std::cout << "FragTrap : " << this->_Name << " Constructor called" << std::endl;
	this->_Name = Name;
	this->_AttackDmg = 30;
	this->_EnergyPoints = 100;
	this->_HitPoints = 100;
}

FragTrap::FragTrap(const FragTrap &Cpy) : ClapTrap(Cpy)
{
	std::cout << "FragTrap : " << this->_Name << " Copy constructor called" << std::endl;
	*this = Cpy;
}

FragTrap& FragTrap::operator=(const FragTrap &ToCopy)
{
	this->_Name = ToCopy._Name;
	this->_HitPoints = ToCopy._HitPoints;
	this->_AttackDmg = ToCopy._AttackDmg;
	this->_EnergyPoints = ToCopy._EnergyPoints;
	return *this;
}

FragTrap::~FragTrap() 
{
	std::cout << "FragTrap : " << this->_Name << " Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_HitPoints > 0)
		std::cout << "FragTrap : " << this->_Name << " Want a high five" << std::endl;	
	else
		std::cout << "FragTrap : " << this->_Name << " is died" << std::endl;

}
