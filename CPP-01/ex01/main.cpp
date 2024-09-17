/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:33:29 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 11:20:26 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *new_zombie;
	new_zombie = zombieHorde(10, "timo");
	for (int i = 0; i < 10; i++)
		new_zombie[i].announce();
	delete[] new_zombie;
}