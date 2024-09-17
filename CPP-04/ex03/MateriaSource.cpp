/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:20:46 by aranger           #+#    #+#             */
/*   Updated: 2024/05/17 12:49:50 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->LearnM[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &cpy)
{
	*this = cpy;
}

MateriaSource & MateriaSource::operator=(MateriaSource const &cpy)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->LearnM[i] != NULL)
			delete this->LearnM[i];
		this->LearnM[i] = cpy.LearnM[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->LearnM[i] != NULL)
			delete this->LearnM[i];
	}
}

void MateriaSource::learnMateria(AMateria* Add)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->LearnM[i] == NULL)
		{
			this->LearnM[i] = Add;
			std::cout << "Add " << Add->getType() << " at i = " << i << std::endl;
			break;
		}
		else if (i == 3)
			delete Add;
	}		
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (type.compare(this->LearnM[i]->getType()) == 0)
		{
			return this->LearnM[i]->clone();
		}
	}
	return 0;
}
