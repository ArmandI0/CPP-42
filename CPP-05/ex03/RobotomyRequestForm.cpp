/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:56:57 by armandanger       #+#    #+#             */
/*   Updated: 2024/05/30 10:41:14 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(std::string Target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_Target = Target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy)
{
	*this = cpy;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &cpy)
{
	this->_Target = cpy._Target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getGradeToExec() < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
	if (this->getStatusAForm() == false)
		throw AForm::NeedToBeSigned();
	std::srand(std::time(NULL));
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << "Make some drilling noises, " << this->_Target << " has been robotomized " << std::endl;
	else
		std::cout << "Make some drilling noises, " << this->_Target << " robotomization failed " << std::endl;
}