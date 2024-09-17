/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:16:31 by armandanger       #+#    #+#             */
/*   Updated: 2024/04/28 14:08:46 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    std::string input;
	PhoneBook phone;

	while(1)
	{
		std::cout << "Enter a command : ";
		if(!getline(std::cin, input))
			exit (1);
		if (input.compare("ADD") == 0)
		{
			phone.add_contact();	
		}
		else if (input.compare("SEARCH") == 0)		
		{
			phone.search();
		}
		else if (input.compare("EXIT") == 0)
			exit(0);
		else
			std::cout << "Command not found" << std::endl;
	}
    return 0;
}