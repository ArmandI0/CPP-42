/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:12:37 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 21:54:30 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	Harl_cpp
#define Harl_cpp

#include <string>
#include <iostream>

class	Harl
{
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
	
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif