/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:06:26 by aranger           #+#    #+#             */
/*   Updated: 2024/05/30 15:11:52 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern intern;
		std::cout << std::endl << "Attempt to create inexistant form" << std::endl;
		AForm* a = intern.makeForm("dfs", "BOB");
		delete a;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Intern intern;
		std::cout << std::endl << "Attempt to create empty form" << std::endl;
		AForm* a = intern.makeForm("", "");
		std::cout << *a << std::endl;
		delete a;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Intern intern;
		std::cout << std::endl << "Intern Make shrubbery form" << std::endl;
		AForm* a = intern.makeForm("shrubbery creation", "BOB");
		std::cout << *a << std::endl;
		delete a;
		std::cout << std::endl << "Intern Make robotomy form" << std::endl;
		a = intern.makeForm("robotomy request", "BOB");
		std::cout << *a << std::endl;
		delete a;
		std::cout << std::endl << "Intern Make presidential form" << std::endl;
		a = intern.makeForm("presidential pardon", "BOB");
		std::cout << *a << std::endl;
		delete a;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}