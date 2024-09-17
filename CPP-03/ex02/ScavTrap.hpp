/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:41:09 by aranger           #+#    #+#             */
/*   Updated: 2024/05/13 18:05:39 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_hpp
#define ScavTrap_hpp
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool GaterMode;
	public:
		ScavTrap();
		ScavTrap(std::string Name);
		ScavTrap(const ScavTrap &Copy);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap &ToCopy);

		void guardGate();
		void attack(const std::string& target);
};

#endif