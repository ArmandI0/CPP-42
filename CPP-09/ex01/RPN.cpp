/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:06:17 by aranger           #+#    #+#             */
/*   Updated: 2024/06/29 22:06:23 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static int		doOperation(int val1, int val2, char op)
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

void	rpnCalculate(std::string entry)
{
	std::stack<int> 		stack;
	size_t					start = 0;
	std::string 			validNumbers = "0123456789";
	std::string 			validOperator = "/*-+";
	int						size = 0;
	bool					space = true;

	for(size_t i = 0; i < entry.size(); i++)
	{
		if (std::isspace(entry[i]) == false)
		{
			start = i;
			space = false;
			size = 0;
		}
		if (validNumbers.find(entry[i]) == std::string::npos && validOperator.find(entry[i]) == std::string::npos && std::isspace(entry[i]) == false)
		{
			std::cerr << "Error : invalid input " << std::endl;
			return;
		}
		if (std::isspace(entry[i]) == true && space == false)
		{
			if (validOperator.find(entry[i]))
			{
				if(stack.size() < 2)
					return;
				else
				{
					int val1 = stack.top();
					stack.pop();
					int val2 = stack.top();
					stack.pop();
					stack.push(doOperation(val1, val2, entry[i]));
					std::cout << "add" << std::endl;
				}
			}
			else 
			{
				std::string tmp = entry.substr(start, i);
				int value = std::atoi(tmp.c_str());
				if (value < 0 || value > 10)
				{
					std::cerr << "Error : invalid number" << std::endl;
					return;
				}
				stack.push(value);
			}
			space = true;
			size = 0;
		}
		if (size > 2)
		{
			std::cerr << "Error : invalid input " << std::endl;
			return;
		}
		size++;
	}
	std::cout << "result = " << stack.top() << std::endl;
}
