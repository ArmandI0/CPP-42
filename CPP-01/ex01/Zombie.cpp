/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:38:59 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 10:41:55 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string input)
{
	name = input;
};
Zombie::~Zombie()
{
	std::cout << name << " is dead" << std::endl;
};
void Zombie::set_name(std::string name_in)
{
	if (name_in.empty())
		name_in = "EMPTY";
	name = name_in;
}

void Zombie::announce(void)
{
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}