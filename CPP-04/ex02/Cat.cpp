/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:39:21 by aranger           #+#    #+#             */
/*   Updated: 2024/05/20 14:18:27 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat : Default constructor called" << std::endl;	
	this->_type = "Cat";
	this->_Brain = new Brain;
}
Cat::Cat(const Cat &Copy) : _Brain(new Brain(*Copy._Brain))
{
	std::cout << "Cat : Copy constructor called" << std::endl;
	this->_type = Copy._type;
}
Cat::~Cat()
{
	std::cout << "Cat : Destructor called" << std::endl;
	delete this->_Brain;
}
Cat& Cat::operator=(const Cat &ToCopy)
{
	if (this->_Brain != ToCopy._Brain)
	{
		delete this->_Brain;
		this->_Brain = new Brain(*ToCopy._Brain);
	}
	this->_type = ToCopy._type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "MIAAAAOAOUUUOUOU WOUAF WOUAF" << std::endl;
}

void Cat::addIdea(std::string Idea)
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_Brain->getIdea(i).empty() == true)
		{
			this->_Brain->setIdea(i, Idea);
			break;
		}
	}
}
void Cat::printBrain(void)
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_Brain->getIdea(i).empty() == false)
			std::cout << "Brain Idx " << i << " = " << this->_Brain->getIdea(i) << std::endl;
	}
}