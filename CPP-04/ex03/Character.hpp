/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:03:20 by aranger           #+#    #+#             */
/*   Updated: 2024/05/17 16:05:03 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AMateria.hpp"
#include "Floor.hpp"
#include <iostream>

class Floor;

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(Character const &cpy);
		Character & operator=(Character const &cpy);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		AMateria* Inventory[4];
		Floor* OnTheFloor[100];
		std::string	_Name;
};

#endif
