/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:16:59 by aranger           #+#    #+#             */
/*   Updated: 2024/05/16 19:41:11 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &cpy);
		MateriaSource & operator=(MateriaSource const &cpy);
		~MateriaSource();

		void learnMateria(AMateria* Add);
		AMateria* createMateria(std::string const & type);
	private:
		AMateria* LearnM[4];
};

#endif

