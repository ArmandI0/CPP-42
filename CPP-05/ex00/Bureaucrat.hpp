/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:32:10 by aranger           #+#    #+#             */
/*   Updated: 2024/05/30 14:44:28 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string Name, short Grade);
		Bureaucrat(const Bureaucrat & Cpy);
		~Bureaucrat();

		Bureaucrat & operator=(Bureaucrat const & cpy);		
		std::string getName() const;
		int getGrade() const;
		void promote(short lvl);
		void decrement(short lvl);
	
	private:
		const std::string 	_Name;
		int					_Grade;

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
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Brct);

#endif

