/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:11:59 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 21:16:34 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Weapon_hpp
#define Weapon_hpp

#include <string>
#include <iostream>

class Weapon
{
	public:
		Weapon(std::string typ);
		~Weapon();
	
		const std::string &getType() const;
		void		setType(std::string w_type);
		
	private:
		std::string type;
	
};

#endif