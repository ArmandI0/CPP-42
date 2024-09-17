/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:09:58 by aranger           #+#    #+#             */
/*   Updated: 2024/05/17 13:25:56 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_hpp
#define Cat_hpp
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_Brain;
	public:
		Cat();
		Cat(const Cat &Copy);
		~Cat();

		Cat& operator=(const Cat &ToCopy);
		void makeSound() const;
		void addIdea(std::string Idea);
		void printBrain(void);
};

#endif