/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:11:12 by aranger           #+#    #+#             */
/*   Updated: 2024/05/17 13:22:19 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor called." << std::endl;
}

Brain::Brain(Brain const &cpy)
{
	std::cout << "Brain Copy constructor called." << std::endl;
	*this = cpy;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called." << std::endl;

}

Brain& Brain::operator=(Brain const &cpy)
{
	for(int i = 0; i < 100; i++)
		this->_Ideas[i] = cpy._Ideas[i];
	return *this;
}

void Brain::setIdea(int Index, std::string Idea)
{
	this->_Ideas[Index] = Idea;
}

std::string Brain::getIdea(int Index) const
{
	return this->_Ideas[Index];
}
