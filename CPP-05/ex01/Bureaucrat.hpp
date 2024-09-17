/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:32:10 by aranger           #+#    #+#             */
/*   Updated: 2024/05/20 21:33:09 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include "Form.hpp"
#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string Name, short Grade);
		Bureaucrat(const Bureaucrat &Cpy);
		~Bureaucrat();

		Bureaucrat& operator=(Bureaucrat const &cpy);		
		std::string getName() const;
		int getGrade() const;
		void promote(short lvl);
		void decrement(short lvl);
		void signForm(Form &f);
	
		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
		
	private:
		const std::string	_Name;
		int					_Grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Brct);

#endif

