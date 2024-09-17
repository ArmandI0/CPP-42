/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:33:29 by aranger           #+#    #+#             */
/*   Updated: 2024/04/28 17:58:56 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *new_zombie;

	new_zombie = newZombie("");
	new_zombie->announce();
	delete new_zombie;

	randomChump("aranger");
	randomChump("");
}