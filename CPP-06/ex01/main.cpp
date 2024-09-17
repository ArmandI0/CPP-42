/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:45:50 by aranger           #+#    #+#             */
/*   Updated: 2024/06/08 13:29:45 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	//Serializer a = Serializer();
	Data* test;
	Data* out;
	uintptr_t ptr;

	test = new Data;
	test->character = 'F';
	test->integer = 2314;
	test->status = false;
	test->str = "BLABLA";
	
	std::cout << "BEFORE" << std::endl;	
	std::cout << test->character << std::endl;	
	std::cout << test->integer << std::endl;
	std::cout << test->str << std::endl;
	std::cout << test->status << std::endl;
	
	ptr = Serializer::serialize(test);
	out = Serializer::deserialize(ptr);

	std::cout << "AFTER" << std::endl;	
	std::cout << out->character << std::endl;	
	std::cout << out->integer << std::endl;
	std::cout << out->str << std::endl;
	std::cout << out->status << std::endl;

	delete test;
    return (0);
}