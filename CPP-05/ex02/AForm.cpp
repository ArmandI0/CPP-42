/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:08:39 by aranger           #+#    #+#             */
/*   Updated: 2024/05/20 21:44:39 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _Name("Default") , _GradeRqrToSign(50) , _GradeRqrToExec(70) , _Signed(false)
{
	std::cout << "AForm Constructor called." << std::endl;
}

AForm::AForm(std::string Name, short GradeRqrToSign, short GradeRqrToExec) : _Name(Name) , _GradeRqrToSign(GradeRqrToSign) , _GradeRqrToExec(GradeRqrToExec) , _Signed(false)
{
	if (GradeRqrToSign < 1 || GradeRqrToExec < 1)
		throw AForm::GradeTooHighException();
	if (GradeRqrToSign > 150 || GradeRqrToExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & cpy) : _Name(cpy._Name) , _GradeRqrToSign(cpy._GradeRqrToSign) , _GradeRqrToExec(cpy._GradeRqrToExec) , _Signed(cpy._Signed)
{
	std::cout << "AForm Copy constructor called." << std::endl;
}

AForm&	AForm::operator=(AForm const & Cpy)
{
	this->_Signed = Cpy._Signed;
	return *this;
}

AForm::~AForm()
{
	
}

void AForm::beSigned(Bureaucrat const & Brct)
{
	if (this->_Signed == true)
	{
		std::cout << Brct.getName() << " couldn’t sign " << this->_Name << " because ";
		throw AForm::AFormAlreadySign();
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

const char* AForm::AFormAlreadySign::what() const throw()
{
	return ("The AForm is already signed.");
}

const char* AForm::NeedToBeSigned::what() const throw()
{
	return ("The form needs to be signed before execution.");
};
const char* AForm::GradeTooLowException::what() const throw()
{
	return ("The AForm grade is too low");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("The AForm grade is too high");
}

std::ostream& operator<<(std::ostream& os, const AForm & f)
{
	os << "############### AForm INFOS ###############" << std::endl
	<< "AForm name              : " << f.getName() << std::endl
	<< "Grade required to sign : " << f.getGradeToSign() << std::endl
	<< "Grade required to sign : " << f.getGradeToExec() << std::endl
	<< "AForm is signed         : " << f.getStatusAForm() << std::endl
	<< "##########################################" << std::endl;
	return os;
}

/* GETTERS*/

std::string	AForm::getName() const {return this->_Name;}
int AForm::getGradeToSign() const {return this->_GradeRqrToSign;}
int	AForm::getGradeToExec() const {return this->_GradeRqrToExec;}
bool AForm::getStatusAForm() const {return this->_Signed;}
