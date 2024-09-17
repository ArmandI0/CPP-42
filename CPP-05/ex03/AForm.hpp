/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:08:43 by aranger           #+#    #+#             */
/*   Updated: 2024/05/20 20:11:08 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
	public:

		AForm();
		AForm(std::string Name, short GradeRqrToSign, short GradeRqrToExec);
		AForm(AForm const & Cpy);
		virtual ~AForm();
		AForm & operator=(AForm const & Cpy);
		void beSigned(Bureaucrat const & Brct);
		virtual void execute(Bureaucrat const & executor) const = 0;

		std::string	getName() const;
		int getGradeToSign() const;
		int	getGradeToExec() const;
		bool getStatusAForm() const;

		class AFormAlreadySign : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

		class NeedToBeSigned : public std::exception
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

std::ostream& operator<<(std::ostream& os, const AForm & Brct);

#endif
