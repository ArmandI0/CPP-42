/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:45:50 by aranger           #+#    #+#             */
/*   Updated: 2024/06/08 16:24:13 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <cstdlib>
# include <ctime>
# include <string>
# include <iostream>


Base * generate(void)
{
	std::srand(std::time(0));
    int randomNumber = std::rand() % 101;

	if (randomNumber <= 33)
		return new A;
	else if(randomNumber > 33 && randomNumber <= 66)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	A *a = dynamic_cast<A*>(p);
	if (a != NULL)
		std::cout << "p : A" << std::endl;	
	B *b = dynamic_cast<B*>(p);
	if (b != NULL)
		std::cout << "p : B" << std::endl;
	C *c = dynamic_cast<C*>(p);
	if (c != NULL)
		std::cout << "p : C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "p : A" << std::endl;
		return;
	}
	catch(const std::exception& e){}
	try
	{
		B a = dynamic_cast<B&>(p);
		std::cout << "p : B" << std::endl;
		return;
	}
	catch(const std::exception& e){}
	try
	{
		C a = dynamic_cast<C&>(p);
		std::cout << "p : C" << std::endl;
		return;
	}
	catch(const std::exception& e){}
}

int main(void)
{
	Base *ptr1, *ptr2, *ptr3;

	ptr1 = generate();
	ptr2 = generate();
	ptr3 = generate();
    
	identify(ptr1);
	identify(ptr2);
	identify(ptr3);

	std::cout << "With reference" << std::endl;
	identify(&(*ptr1));

	delete ptr1;
	delete ptr2;
	delete ptr3;
	return (0);
}