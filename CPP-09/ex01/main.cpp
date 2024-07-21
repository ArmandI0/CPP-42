/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:57:49 by aranger           #+#    #+#             */
/*   Updated: 2024/07/03 15:07:34 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **argv)
{
	if (ac != 2)
	{
		std::cout << "Error: invalid input. Please enter a valid expression like '1 2 +' " << std::endl;
		return 1;
	}
	try
	{
		rpnCalculate(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}