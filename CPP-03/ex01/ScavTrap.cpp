/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:04:03 by aranger           #+#    #+#             */
/*   Updated: 2024/05/13 18:05:03 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap : " << this->_Name << " Default constructor called" << std::endl;
	this->GaterMode = false;
	this->_Name = "No name";
	this->_AttackDmg = 20;
	this->_EnergyPoints = 50;
	this->_HitPoints = 100;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	std::cout << "ScavTrap : " << this->_Name << " Constructor called" << std::endl;
	this->GaterMode = false;
	this->_Name = Name;
	this->_AttackDmg = 20;
	this->_EnergyPoints = 50;
	this->_HitPoints = 100;
}

ScavTrap::ScavTrap(const ScavTrap &Cpy) : ClapTrap(Cpy)
{
	std::cout << "ScavTrap : " << this->_Name << " Copy constructor called" << std::endl;
	*this = Cpy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &ToCopy)
{
	this->_Name = ToCopy._Name;
	this->_HitPoints = ToCopy._HitPoints;
	this->_AttackDmg = ToCopy._AttackDmg;
	this->_EnergyPoints = ToCopy._EnergyPoints;
	this->GaterMode = ToCopy.GaterMode;
	return *this;
}

ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap : " << this->_Name << " Destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->GaterMode == false)
	{
		std::cout << "ScavTrap : " << this->_Name << " guardgate actived" << std::endl;
		this->GaterMode = true;
	}
	else
		std::cout << "ScavTrap : " << this->_Name << " guardgate already active" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_HitPoints == 0)
	{
		std::cout << "ScavTrap : " << this->_Name << " is dead" << std::endl;
		return ;
	}
	if (this->_EnergyPoints > 0)
	{
		this->_EnergyPoints--;
		std::cout << "ScavTrap : " << this->_Name << " attacks " << target << ", causing " << this->_AttackDmg << " points of damage!" << std::endl;
	}
	else
		std::cout << "No energy points" << std::endl;
	
}
