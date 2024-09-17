/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:41:09 by aranger           #+#    #+#             */
/*   Updated: 2024/05/13 18:06:33 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_hpp
#define FragTrap_hpp
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap(std::string Name);
		FragTrap(const FragTrap &Copy);
		~FragTrap();

		FragTrap& operator=(const FragTrap &ToCopy);

		void highFivesGuys(void);
};

#endif