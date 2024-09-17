/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:06:26 by aranger           #+#    #+#             */
/*   Updated: 2024/05/20 14:23:16 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Cat a;
	Dog b;
	Cat c;

	a.makeSound();
	b.makeSound();
	c.makeSound();
	
	a.addIdea("blabla");
	a.addIdea("toto");
	a.printBrain();
	c = a;
	c.printBrain();
	Cat *d; 
	d = new Cat(c);
	d->printBrain();
	delete d;
}
