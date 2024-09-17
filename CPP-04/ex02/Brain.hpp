/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:10:40 by aranger           #+#    #+#             */
/*   Updated: 2024/05/17 13:22:07 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include "iostream"

class Brain
{
	private:
		std::string	_Ideas[100];
	public:
		Brain();
		Brain(Brain const &cpy);
		~Brain();

		Brain& operator=(Brain const &cpy);
		void setIdea(int Index, std::string Idea);
		std::string getIdea(int Index) const;
};

#endif
