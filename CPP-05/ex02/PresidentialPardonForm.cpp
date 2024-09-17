/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:10:34 by armandanger       #+#    #+#             */
/*   Updated: 2024/05/30 10:41:07 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(std::string Target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->_Target = Target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cpy)
{
	*this = cpy;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &cpy)
{
	this->_Target = cpy._Target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getGradeToExec() < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
	if (this->getStatusAForm() == false)
		throw AForm::NeedToBeSigned();
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	std::cout << this->_Target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}