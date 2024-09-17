/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:49:52 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 11:05:14 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string	&ref = str;
	
	std::cout << "Adress str: " << &str << std::endl; 	
	std::cout << "Adress ptr: " << ptr << std::endl; 	
	std::cout << "Adress ref: " << &ref<< std::endl;

	std::cout << "Value of str = " << str << std::endl;	
	std::cout << "Value of ptr = " << *ptr << std::endl;
	std::cout << "Value of ref = " << ref << std::endl;
}