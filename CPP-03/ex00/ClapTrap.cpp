/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:19:58 by aranger           #+#    #+#             */
/*   Updated: 2024/05/13 18:08:44 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("NoName") , _HitPoints(10) , _EnergyPoints(10) , _AttackDmg(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : _Name(Name) , _HitPoints(10) , _EnergyPoints(10) , _AttackDmg(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &Cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = Cpy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ToCopy)
{
	this->_Name = ToCopy._Name;
	this->_HitPoints = ToCopy._HitPoints;
	this->_AttackDmg = ToCopy._AttackDmg;
	this->_EnergyPoints = ToCopy._EnergyPoints;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_HitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_Name << " is dead" << std::endl;
		return ;
	}
	if (this->_EnergyPoints > 0)
	{
		this->_EnergyPoints--;
		std::cout << "ClapTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDmg << " points of damage!" << std::endl;
	}
	else
		std::cout << "No energy points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_HitPoints <= 0)
	{
		std::cout << "ClapTrap : " << this->_Name << " is died" << std::endl;
		return ;
	}
	if ((this->_HitPoints - amount) <= 0)
	{
		std::cout << "ClapTrap : " << this->_Name << " is died" << std::endl;
		this->_HitPoints = 0;
	}
	else
	{
		std::cout << "ClapTrap : " << this->_Name << " take " << amount << " of damage" << std::endl;
		this->_HitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_HitPoints <= 0)
	{
		std::cout << "ClapTrap : " << this->_Name << " is died" << std::endl;
		return ;
	}
	if (this->_EnergyPoints > 0)
	{
		this->_EnergyPoints--;
		this->_HitPoints += amount;
		std::cout << "ClapTrap " << this->_Name << " be repaired of " << amount << " points" <<std::endl;
	}
	else
		std::cout << "No energy points" << std::endl;
}

