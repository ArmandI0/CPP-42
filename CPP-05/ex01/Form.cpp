/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:08:39 by aranger           #+#    #+#             */
/*   Updated: 2024/05/30 15:01:13 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _Name("Default") , _GradeRqrToSign(50) , _GradeRqrToExec(70) , _Signed(false)
{
	std::cout << "Form Constructor called." << std::endl;
}

Form::Form(std::string Name, short GradeRqrToSign, short GradeRqrToExec) : _Name(Name) , _GradeRqrToSign(GradeRqrToSign) , _GradeRqrToExec(GradeRqrToExec) , _Signed(false)
{
	if (GradeRqrToSign < 1 || GradeRqrToExec < 1)
		throw Form::GradeTooHighException();
	if (GradeRqrToSign > 150 || GradeRqrToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & cpy) : _Name(cpy._Name) , _GradeRqrToSign(cpy._GradeRqrToSign) , _GradeRqrToExec(cpy._GradeRqrToExec) , _Signed(cpy._Signed)
{
	std::cout << "Form Copy constructor called." << std::endl;
}

Form&	Form::operator=(Form const & Cpy)
{
	this->_Signed = Cpy._Signed;
	return *this;
}

Form::~Form()
{
	
}

void Form::beSigned(Bureaucrat const & Brct)
{
	if (this->_Signed == true)
	{
		std::cout << Brct.getName() << " couldn’t sign " << this->_Name << " because ";
		throw Form::FormAlreadySign();
	}
	else if (this->_GradeRqrToSign < Brct.getGrade())
	{
		std::cout << Brct.getName() << " couldn’t sign " << this->_Name << " because ";
		throw Bureaucrat::GradeTooLowException();
	}
	else
	{
		this->_Signed = true;
		std::cout << Brct.getName() << " signs " << this->_Name << std::endl;
	}
}

const char* Form::FormAlreadySign::what() const throw()
{
	return ("the form is already signed.");
}
const char* Form::GradeTooLowException::what() const throw()
{
	return ("the Form grade is too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("the Form grade is too high");
}

std::ostream& operator<<(std::ostream& os, const Form & f)
{
	os << "############### FORM INFOS ###############" << std::endl
	<< "Form name              : " << f.getName() << std::endl
	<< "Grade required to sign : " << f.getGradeToSign() << std::endl
	<< "Grade required to sign : " << f.getGradeToExec() << std::endl
	<< "Form is signed         : " << f.getStatusForm() << std::endl
	<< "##########################################" << std::endl;
	return os;
}

/* GETTERS*/

std::string	Form::getName() const {return this->_Name;}
int Form::getGradeToSign() const {return this->_GradeRqrToSign;}
int	Form::getGradeToExec() const {return this->_GradeRqrToExec;}
bool Form::getStatusForm() const {return this->_Signed;}
