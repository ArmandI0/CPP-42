/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:06:46 by aranger           #+#    #+#             */
/*   Updated: 2024/05/17 13:41:17 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_hpp
#define Dog_hpp
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_Brain;		
	public:
		Dog();
		Dog(const Dog &Copy);
		~Dog();

		Dog& operator=(const Dog &ToCopy);
		void makeSound() const;
		void addIdea(std::string Idea);
		void printBrain(void);
};

#endif

