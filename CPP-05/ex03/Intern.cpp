/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:44:49 by aranger           #+#    #+#             */
/*   Updated: 2024/05/30 14:52:36 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	
}

Intern::Intern(Intern const &cpy)
{
	*this = cpy;
}

Intern & Intern::operator=(Intern const &cpy)
{
	(void)cpy;
	return (*this);
}

Intern::~Intern()
{

}

const char *Intern::InvalidFormOrTarget::what() const throw()
{
	return ("invalid request");
}

AForm* Intern::makeForm(std::string formName, std::string targetName)
{
	int form = -1;
	std::string tab[3] = {"shrubbery creation","robotomy request","presidential pardon"};

	if (formName.empty() || targetName.empty())
		throw Intern::InvalidFormOrTarget();
	for(int i = 0; i < 3; i++)
	{
		if (formName.compare(tab[i]) == 0)
		{
			form = i;
			break;
		}
	}
	if (form == -1)
		throw Intern::InvalidFormOrTarget();
	std::cout << "Intern creates " << tab[form] << std::endl;
	switch (form)
	{
		case 0 :
			return (new ShrubberyCreationForm);
		case 1 :
			return (new RobotomyRequestForm);
		case 2 :
			return (new PresidentialPardonForm);
	}
	return NULL;
}
