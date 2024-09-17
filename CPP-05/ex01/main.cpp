/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:06:26 by aranger           #+#    #+#             */
/*   Updated: 2024/05/30 15:04:56 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	
	Bureaucrat a;
	Form newForm = Form("Form1", 130, 130);
	{
		std::cout << newForm << std::endl;

		std::cout << std::endl << "Attempt to create a form that is too low." << std::endl;
		try {newForm = Form("Form", 160, 160);}
		catch (std::exception& e) {std::cout << e.what() << std::endl;}

		std::cout << std::endl << "Attempt to create a form that is too high." << std::endl;
		try {newForm = Form("Form", 0, 0);}
		catch (std::exception& e) {std::cout << e.what() << std::endl;}

		std::cout << std::endl << "Attempt to sign with a grade that is too low." << std::endl;
		try 
		{
			Form newForm2 = Form("Form", 30, 30);
			a = Bureaucrat("Aranger", 40);
			a.signForm(newForm2);
		}
		catch (std::exception& e) {std::cout << e.what() << std::endl;}

		std::cout << std::endl << "Attempt to sign a form already sign" << std::endl;
		Form newForm3 = Form("Form", 30, 30);
		try
		{
			a = Bureaucrat("Aranger", 10);
			a.signForm(newForm3);
			a.signForm(newForm3);
		}
		catch (std::exception& e) {std::cout << e.what() << std::endl;}
	}
	return 0;
}