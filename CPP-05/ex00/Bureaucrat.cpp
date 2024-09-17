/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:32:21 by aranger           #+#    #+#             */
/*   Updated: 2024/05/30 14:53:06 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _Name("Bob") , _Grade(150)
{
	
}

Bureaucrat::Bureaucrat(std::string Name, short Grade) : _Name(Name) , _Grade(Grade)
{
	if (Grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (Grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &Cpy)
{
	*this = Cpy;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &cpy)
{
	if (this != &cpy)
		this->_Grade = cpy._Grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->_Name;
}
int Bureaucrat::getGrade() const
{
	return this->_Grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Brct)
{
	os << Brct.getName() << ", bureaucrat grade " <<  Brct.getGrade() << " ." << std::endl;
	return os;
}

void Bureaucrat::promote(short lvl)
{
	if (this->_Grade - lvl < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_Grade -= lvl;
}

void Bureaucrat::decrement(short lvl)
{
	if (this->_Grade + lvl > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_Grade += lvl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat promote is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat promote is too low");	
}