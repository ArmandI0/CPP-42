/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:57:49 by aranger           #+#    #+#             */
/*   Updated: 2024/06/16 14:17:20 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "easyfind.tpp"

int main(void)
{
	std::vector<int> tabInt;
	int find = 2;
	
	for (int i = 0; i < 10; i++)
	{
		tabInt.push_back(i);
	}
	std::vector<int>::iterator it = tabInt.begin();
	for (; it != tabInt.end(); ++it)
	{
		std::cout << "adress = " << &*it << "  value = " << *it << std::endl;
	}
	std::cout << std::endl << "try to find = "<< find << std::endl; 
	try{
		it = easyfind(tabInt, find);
		std::cout << "find :" << *it << " at : " << &*it << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "occurrence not found" << std::endl;
	}
	find = 28;
	std::cout << std::endl << "try to find = "<< find << std::endl; 
	try{
		it = easyfind(tabInt, find);
		std::cout << "find :" << *it << " at : " << &*it << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "occurrence not found" << std::endl;
	}
}