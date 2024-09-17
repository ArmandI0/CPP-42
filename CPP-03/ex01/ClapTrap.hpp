/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:20:20 by aranger           #+#    #+#             */
/*   Updated: 2024/05/13 18:05:49 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_hpp
#define ClapTrap_hpp
#include <iostream>
#include <string>

class ClapTrap
{
	protected:
	
		std::string		_Name;
		int				_HitPoints;
		unsigned int	_EnergyPoints;
		unsigned int	_AttackDmg;

	public:
	
		ClapTrap();
		ClapTrap(std::string Name);
		ClapTrap(const ClapTrap &Copy);
		~ClapTrap();

		ClapTrap& operator=(const ClapTrap &ToCopy);

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif