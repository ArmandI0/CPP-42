/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:48:32 by aranger           #+#    #+#             */
/*   Updated: 2024/04/28 15:29:32 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>



class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie();
		void announce(void);

	private:
		std::string	name;
};

Zombie* newZombie(std::string name);
void 	randomChump(std::string name);

#endif