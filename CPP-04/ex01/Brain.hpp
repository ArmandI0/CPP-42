/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armandanger <armandanger@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:10:40 by aranger           #+#    #+#             */
/*   Updated: 2024/05/19 17:57:55 by armandanger      ###   ########.fr       */
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
