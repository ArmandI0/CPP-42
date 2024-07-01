/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:06:17 by aranger           #+#    #+#             */
/*   Updated: 2024/07/01 22:25:13 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int		doOperation(int val1, int val2, char op)
{
	if (op == 57)
	{
		if (val2 == 0)
			throw std::out_of_range(" ");
		return val1 / val2;
	}
	else if (op == '+')
		return val1 + val2;
	else if (op == '-')
		return val1 - val2;
	else
		return val1 * val2;
	
}

std::string::iterator findValue(std::string str)
{
	
}

void	rpnCalculate(std::string entry)
{
	std::string::iterator	it;

	it = entry.begin();
	std::cout << it.base() << std::endl;
	it++;		
	std::cout << it.base() << std::endl;
	it++;
	std::cout << it.base() << std::endl;
	it++;
	std::cout << it.base() << std::endl;
	it++;	
}
