/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:06:26 by aranger           #+#    #+#             */
/*   Updated: 2024/05/30 15:08:21 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << std::endl << "TEST ShrubberyCreationForm" << std::endl;
	std::cout << std::endl << "Test 1 Bureaucrat with required grade" << std::endl;
	try
	{
		ShrubberyCreationForm newForm = ShrubberyCreationForm("FormSigned");
		Bureaucrat a = Bureaucrat("BureaucratOK", 10);
		a.signForm(newForm);
		a.executeForm(newForm);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "Test 2 bureaucrat attempt to execute a form without signature" << std::endl;
	try
	{
		ShrubberyCreationForm newForm = ShrubberyCreationForm("FormWithoutSignature");
		Bureaucrat a = Bureaucrat("BureaucratOK", 70);
		a.executeForm(newForm);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "Test 3 Bureaucrat attempt to execute form with too low grade" << std::endl;
	try
	{
		ShrubberyCreationForm newForm = ShrubberyCreationForm("FormWithoutSignature");
		Bureaucrat a = Bureaucrat("BureaucratOK", 138);
		a.signForm(newForm);
		a.executeForm(newForm);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "TEST RobotomyRequestForm" << std::endl;
	std::cout << std::endl << "Test 1 Bureaucrat with required grade" << std::endl;
	try
	{
		RobotomyRequestForm newForm = RobotomyRequestForm("FormSigned");
		Bureaucrat a = Bureaucrat("BureaucratOK", 10);
		a.signForm(newForm);
		a.executeForm(newForm);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "Test 2 bureaucrat attempt to execute a form without signature" << std::endl;
	try
	{
		RobotomyRequestForm newForm = RobotomyRequestForm("FormWithoutSignature");
		Bureaucrat a = Bureaucrat("BureaucratOK", 10);
		a.executeForm(newForm);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "Test 3 Bureaucrat attempt to execute form with too low grade" << std::endl;
	try
	{
		RobotomyRequestForm newForm = RobotomyRequestForm("FormWithoutSignature");
		Bureaucrat a = Bureaucrat("BureaucratOK", 70);
		a.signForm(newForm);
		a.executeForm(newForm);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "TEST PresidentialPardonForm" << std::endl;
	std::cout << std::endl << "Test 1 Bureaucrat with required grade" << std::endl;
	try
	{
		PresidentialPardonForm newForm = PresidentialPardonForm("BOB");
		Bureaucrat a = Bureaucrat("BureaucratOK", 5);
		a.signForm(newForm);
		a.executeForm(newForm);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "Test 2 bureaucrat attempt to execute a form without signature" << std::endl;
	try
	{
		PresidentialPardonForm newForm = PresidentialPardonForm("BOB");
		Bureaucrat a = Bureaucrat("BureaucratOK", 5);
		a.executeForm(newForm);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "Test 3 Bureaucrat attempt to execute form with too low grade" << std::endl;
	try
	{
		PresidentialPardonForm newForm = PresidentialPardonForm("BOB");
		Bureaucrat a = Bureaucrat("BureaucratOK", 20);
		a.signForm(newForm);
		a.executeForm(newForm);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}