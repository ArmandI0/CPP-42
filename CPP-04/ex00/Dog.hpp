/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:06:46 by aranger           #+#    #+#             */
/*   Updated: 2024/05/12 20:30:46 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_hpp
#define Dog_hpp
#include "Animal.hpp"

class Dog : public Animal
{
	private:
		
	public:
		Dog();
		Dog(const Dog &Copy);
		~Dog();

		Dog& operator=(const Dog &ToCopy);
		void makeSound() const;
};

#endif

