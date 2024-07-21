/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:15:04 by aranger           #+#    #+#             */
/*   Updated: 2024/07/12 11:28:30 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac <= 2)
    {
        std::cerr << "Error : at least two arguments are required" <<std::endl;
        return 1;
	}
	PmergeMe a;
	try
	{
		a.tabCreate(ac, av);
        a.sort();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
