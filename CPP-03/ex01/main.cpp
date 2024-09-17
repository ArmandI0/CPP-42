/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:19:20 by aranger           #+#    #+#             */
/*   Updated: 2024/05/12 17:25:37 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap bob("Emile");
	bob.attack("Aranger");
	bob.takeDamage(3);
	bob.beRepaired(2);

	ScavTrap st("aranger");
	ScavTrap el("SCAV2");
	st.takeDamage(30);
	st.takeDamage(23);
	st.takeDamage(50);
	st.takeDamage(23);
	el.attack("THOR");
	el.beRepaired(30);
	el.guardGate();
	el.guardGate();
}