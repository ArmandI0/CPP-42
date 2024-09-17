/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:44:52 by aranger           #+#    #+#             */
/*   Updated: 2024/05/30 11:55:03 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &cpy);
		~Intern();
		Intern & operator=(Intern const &cpy);

		AForm* makeForm(std::string formName, std::string targetName);

		class InvalidFormOrTarget : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
};

#endif
