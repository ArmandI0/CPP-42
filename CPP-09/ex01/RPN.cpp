/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:06:17 by aranger           #+#    #+#             */
/*   Updated: 2024/07/03 16:14:22 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int		doOperation(int val1, int val2, char op)
{
	if (op == 57)
	{
		if (val2 == 0)
			throw std::out_of_range("Error : division by 0");
		return val1 / val2;
	}
	else if (op == '+')
		return val1 + val2;
	else if (op == '-')
		return val1 - val2;
	else
		return val1 * val2;
	
}

bool	checkIsValid(std::string nb)
{
	std::string				validNumbers = "0123456789";

	for(size_t i = 0; i < nb.size(); i++)
	{
		if(validNumbers.find(nb[i]) == std::string::npos)
			return false;
	}
	return true;
}


void	rpnCalculate(std::string entry)
{
	std::stack<int>			stack;
	std::istringstream		iss(entry);
	std::string				tmp;
	std::string				validOperator = "/*-+";

	while (iss >> tmp)
	{
		std::cout << "tmp value = " << tmp << std::endl;
		if(tmp.length() < 4)
		{
			if (tmp.length() == 1 && validOperator.find(tmp[0]) != std::string::npos)
			{
				if (stack.size() >= 2)
				{
					int	top = stack.top();
					stack.pop();
					stack.top() = doOperation(stack.top(), top, tmp[0]);
					std::cout << "stack top after operation = " << stack.top() << std::endl;
				}
				std::cout << "do operation " << std::endl;
			}
			else if(checkIsValid(tmp) == true)
				stack.push(std::atoi(tmp.c_str()));	
			else
			{
				std::cerr << "Error : invalid argument" << std::endl;
				return;
			}
		}
		else
		{
			std::cerr << "Error : invalid argument" << std::endl;
			return;
		}
	}
	if (stack.size() == 1)
		std::cout << stack.top() << std::endl;
	else
		std::cerr << "Error : invalid argument" << std::endl;
}
