/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:19:20 by aranger           #+#    #+#             */
/*   Updated: 2024/05/12 19:00:05 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap fg1("aranger");
	FragTrap fg2("SCAV2");
	fg1.attack("le chat");
	fg2.attack("le chat");
	fg1.highFivesGuys();
	fg2 = fg1;
}