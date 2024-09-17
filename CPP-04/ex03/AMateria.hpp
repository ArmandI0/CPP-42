/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:01:41 by armandanger       #+#    #+#             */
/*   Updated: 2024/05/17 21:14:16 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMateria_hpp
#define AMateria_hpp
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &Cpy);
		virtual ~AMateria() {};

		AMateria& operator=(AMateria const &cpy);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif