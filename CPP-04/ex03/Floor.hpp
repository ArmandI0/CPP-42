/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:29:20 by aranger           #+#    #+#             */
/*   Updated: 2024/05/17 16:14:39 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
#define FLOOR_HPP
#include "Character.hpp"


class Floor
{
	public:
		Floor();
		Floor(AMateria* ptr);
		Floor(Floor const &cpy);
		Floor & operator=(Floor const &cpy);
		Floor* clone() const;
		~Floor();
	private:
		AMateria* ObjFloor;

};

#endif
