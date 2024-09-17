/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:45:23 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 21:17:19 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_hpp
# define HumanB_hpp
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string a);
		~HumanB();
		void attack();
		void setWeapon(Weapon &a);
		
	private:
		Weapon	*_weapon;
		std::string	name;
};

#endif