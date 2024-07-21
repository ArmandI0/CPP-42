/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:06:17 by aranger           #+#    #+#             */
/*   Updated: 2024/07/06 16:54:40 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

float	doOperation(float val1, float val2, char op)
{
	if (op == 47)
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

void	rpnCalculate(std::string entry)
{
	std::stack<float>			stack;
	std::istringstream		iss(entry);
	std::string				tmp;
	std::string				validOperator = "/*-+";

	while (iss >> tmp)
	{
		if(tmp.length() < 4)
		{
			if (tmp.length() == 1 && validOperator.find(tmp[0]) != std::string::npos)
			{
				if (stack.size() >= 2)
				{
					float	top = stack.top();
					stack.pop();
					stack.top() = doOperation(stack.top(), top, tmp[0]);
				}
				else
					throw std::out_of_range("Error : invalid argument");
			}
			else if(tmp.find_first_not_of("0123456789") == std::string::npos)
			{
				int nb = std::atoi(tmp.c_str());
				if (nb < 0 || nb > 9)
					throw std::out_of_range("Error : invalid argument");
				stack.push(static_cast<float>(nb));
			}
			else
				throw std::out_of_range("Error : invalid argument");
		}
		else
			throw std::out_of_range("Error : invalid argument");
	}
	if (stack.size() == 1)
		std::cout << stack.top() << std::endl;
	else
		throw std::out_of_range("Error : invalid argument");
}

