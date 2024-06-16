/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:57:49 by aranger           #+#    #+#             */
/*   Updated: 2024/06/16 18:53:01 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int main(void)
{
	try
	{
		std::cout << "TEST OF SUBJECT" << std::endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		
		std::cout << "OTHER TESTS WITH 20 RANDOM NUMBER" << std::endl;
		Span a(20);
		std::srand(std::time(0));
		for (int i = 0; i < 20; i++)
		{
			int randomNumber = std::rand() % 1000;
			a.addNumber(randomNumber);
		}
		a.printSpan();
		std::cout << "ShortestSpan = " << a.shortestSpan() << std::endl;
		std::cout << "LongestSpan = " << a.longestSpan() << std::endl;
		std::cout << "ADD 21 NUM in A  20 ARRAY" << std::endl;
		a.addNumber(1);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << "ADD AN ARRAY" << std::endl;
		std::vector<int> tab;
		std::srand(std::time(0));
		std::cout << "tab = ";
		for (int i = 0; i < 20; i++)
		{
			int randomNumber = std::rand() % 1000;
			tab.push_back(randomNumber);
			std::cout << randomNumber << " ";
		}
		std::cout << std::endl << std ::endl;
		Span a(100);
		a.addNumber(tab);
		std::cout << " add number = ";
		a.printSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	return (0);
}

// int main(void)
// {
// 	Span a(20000);
// 	std::srand(std::time(0));
	
// 	for (int i = 0; i < 20000; i++)
// 	{
//     	int randomNumber = std::rand() % 1500;
// 		a.addNumber(randomNumber);
// 	}
// 	std::cout << "ShortestSpan = " << a.shortestSpan() << std::endl;
// 	std::cout << "LongestSpan = " << a.longestSpan() << std::endl;
// }