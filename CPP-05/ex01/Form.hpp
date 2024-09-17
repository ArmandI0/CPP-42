/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:08:43 by aranger           #+#    #+#             */
/*   Updated: 2024/05/20 20:11:08 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
	public:

		Form();
		Form(std::string Name, short GradeRqrToSign, short GradeRqrToExec);
		Form(Form const & Cpy);
		~Form();
		Form & operator=(Form const & Cpy);
		void beSigned(Bureaucrat const & Brct);

		std::string	getName() const;
		int getGradeToSign() const;
		int	getGradeToExec() const;
		bool getStatusForm() const;

		class FormAlreadySign : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

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
		const int			_GradeRqrToSign;
		const int			_GradeRqrToExec;
		bool 				_Signed;
		
};

std::ostream& operator<<(std::ostream& os, const Form & Brct);

#endif
