/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:23:07 by aranger           #+#    #+#             */
/*   Updated: 2024/05/01 11:22:02 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static int	compare(std::string str)
{
	std::string	tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (str.compare(tab[i]) == 0)
			return i;
	}
	return -1;
}

int main(int ac, char **av)
{
	Harl	hrl;
	if (ac != 2)
		return(0);
	std::string str = av[1];
	switch (compare(str))
	{
		case 0:
			hrl.complain("DEBUG");
			hrl.complain("INFO");
			hrl.complain("WARNING");
			hrl.complain("ERROR");
			break;
		case 1:
			hrl.complain("INFO");
			hrl.complain("WARNING");
			hrl.complain("ERROR");
			break;
		case 2:
			hrl.complain("WARNING");
			hrl.complain("ERROR");
			break;
		case 3:
			hrl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}