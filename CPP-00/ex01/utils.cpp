/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:13:55 by aranger           #+#    #+#             */
/*   Updated: 2024/04/28 14:25:53 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string	str_rsz(std::string in)
{
  if (in.length() > 10)
    {
        in = in.substr(0, 9) + ".";
    }
    return in;
}

void	print_contacts(Contact *rep)
{
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for(int i = 0; i < 8; i++)
	{
		std::cout << "|"<< std::setw(10) << i << "|" << std::setw(10) << str_rsz(rep[i].getFirstName()) << "|" << std::setw(10) << str_rsz(rep[i].getLastName()) << "|" << std::setw(10) << str_rsz(rep[i].getNickname()) << "|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}
	
}

bool	only_spaces(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (std::isspace(str[i]) == false)
			return(false);
	}
	return (true);	
}

std::string	get_info(std::string req)
{
	std::string	input;

	while (1)
	{
		std::cout << req;
		if(!getline(std::cin, input))
			exit(1);
		if (input.empty() == false && only_spaces(input) == false)
			break;
		std::cerr << "Error : enter a valid argument" << std::endl;
	}
	return input;
}

bool	valid_index(std::string str)
{
	int	nb = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (std::isspace(str[i]) == false && std::isdigit(str[i]) == false)
			return false;
		if (std::isdigit(str[i]) == true)
			nb++;
		if (nb > 1)
			return false;
	}
	return true;
}

std::string	get_number(std::string req)
{
	std::string	input;

	while (1)
	{
		std::cout << req;
		if(!getline(std::cin, input))
			exit(1);
		if (input.empty() == false && valid_index(input) == true)
			break;
		std::cerr << "Error : enter a valid index" << std::endl; 
	}
	return input;
}