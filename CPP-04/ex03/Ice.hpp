/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:10:08 by armandanger       #+#    #+#             */
/*   Updated: 2024/05/15 20:14:06 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Ice_hpp
#define Ice_hpp
#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		/* data */
	public:
		Ice();
		Ice(Ice const &cpy);
		~Ice();

		Ice & operator=(Ice const &cpy);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif