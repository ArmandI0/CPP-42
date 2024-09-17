/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armandanger <armandanger@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:06:26 by aranger           #+#    #+#             */
/*   Updated: 2024/05/19 17:35:48 by armandanger      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->gettype() << " " << std::endl;
	std::cout << i->gettype() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	
	delete meta;
 	delete j;
 	delete i;
	
	const WrongAnimal* mcat = new WrongAnimal();
	const WrongAnimal* cat = new WrongCat();
	std::cout << cat->gettype() << " " << std::endl;
	cat->makeSound(); 
	mcat->makeSound();
	
	delete mcat;
 	delete cat;
	return 0;
}