/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armandanger <armandanger@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:15:04 by aranger           #+#    #+#             */
/*   Updated: 2024/07/08 15:55:32 by armandanger      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac <= 2)
    {
        std::cerr << "Error : aruments required" <<std::endl;
        return 1;
	}
	PmergeMe a;
	try
	{
		a.tabCreate(ac, av);
		a.fordJhonsonSort();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}