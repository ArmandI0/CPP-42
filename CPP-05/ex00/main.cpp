/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:06:26 by aranger           #+#    #+#             */
/*   Updated: 2024/05/30 15:05:46 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << std::endl << "Test 1" << std::endl;
	try
	{
		Bureaucrat a;
		std::cout << "Attempt to promote bureaucrat to 155" << std::endl;
		a.promote(155);
	}
	catch (std::exception& e) {std::cout << e.what() << std::endl;}
	
	std::cout << std::endl << "Test 2" << std::endl;
	try 
	{
		std::cout << "Attempt to create b Bucreaucrat with a grade = 150" << std::endl;
		Bureaucrat b = Bureaucrat("newbureaucrat", 150);
		std::cout << "decrement bureaucrat of 5" << std::endl;
		b.decrement(5);
		std::cout << "new grade = " << b.getGrade() << std::endl;
		std::cout << "increment bureaucrat of 10" << std::endl;
		b.promote(10);
		std::cout << "new grade = " << b.getGrade() << std::endl;
	}
	catch (std::exception& e) {std::cout << e.what() << std::endl;}

	std::cout << std::endl << "Test 3" << std::endl;
	try 
	{
		std::cout << "Attempt to create a Bucreaucrat with a grade = 151" << std::endl;
		Bureaucrat b = Bureaucrat("newbureaucrat", 151);
	}
	catch (std::exception& e) {std::cout << e.what() << std::endl;}

	std::cout << std::endl << "Test 4" << std::endl;
	try 
	{
		std::cout << "Attempt to create a Bucreaucrat with a grade = 0" << std::endl;
		Bureaucrat b = Bureaucrat("newbureaucrat", 0);
	}
	catch (std::exception& e) {std::cout << e.what() << std::endl;}
	
	return 0;
}