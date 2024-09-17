/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:03:46 by aranger           #+#    #+#             */
/*   Updated: 2024/05/17 16:17:20 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->Inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->OnTheFloor[i] = NULL;
}

Character::Character(std::string Name) : _Name(Name)
{
	for (int i = 0; i < 4; i++)
		this->Inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->OnTheFloor[i] = NULL;
}

Character::Character(Character const &cpy)
{
	*this = cpy;
}

Character & Character::operator=(Character const &cpy)
{
	this->_Name = cpy.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->Inventory[i] != NULL)
			delete this->Inventory[i];
		this->Inventory[i] = cpy.Inventory[i]->clone();
	}
	for (int i = 0; i < 100; i++)
	{
		if (this->OnTheFloor[i] != NULL)
			delete this->OnTheFloor[i];
		this->OnTheFloor[i] = cpy.OnTheFloor[i]->clone();
	}
	return *this;
}

Character::~Character()
{

	for (int i = 0; i < 4; i++)
	{
		if (this->Inventory[i] != NULL)
			delete this->Inventory[i];
	}
	for (int i = 0; i < 100; i++)
	{
		if (this->OnTheFloor[i] != NULL)
			delete this->OnTheFloor[i];
	}
}

std::string const & Character::getName() const
{
	return this->_Name;
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->Inventory[i] == NULL)
		{
			this->Inventory[i] = m;
			break;
		}
	}
}
void Character::unequip(int idx)
{
	static int index = 0;

	if (idx < 0 || idx > 3)
		return;
	if (this->Inventory[idx] != NULL)
	{
		if (this->OnTheFloor[index] != NULL)
			delete this->OnTheFloor[index];
		this->OnTheFloor[index] = new Floor(this->Inventory[idx]);
		this->Inventory[idx] = NULL;
		index++;
	}
	if (index == 100)
		index = 0;
}
void Character::use(int idx, ICharacter& target)
{
	if ((idx < 0 || idx > 3) && this->Inventory[idx] != NULL)
		return ;
	this->Inventory[idx]->use(target);
}
