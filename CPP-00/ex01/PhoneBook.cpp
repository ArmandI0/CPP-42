/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:58:26 by aranger           #+#    #+#             */
/*   Updated: 2024/04/27 17:41:34 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){}
PhoneBook::~PhoneBook(void){}

void PhoneBook::add_contact()
{
	static int i = 0;
	
	if (i == 8)
		i = 0;
	rep[i].setFirstName(get_info("Firstname :"));
	rep[i].setLastName(get_info("Lastname :"));
	rep[i].setNickname(get_info("Nickname :"));
	rep[i].setPhoneNumber(get_info("Phone number :"));
	rep[i].setDarkestSecret(get_info("Darkest secret :"));
	i++;
}

void PhoneBook::search()
{
	std::string	input;
	int	i;
	
	print_contacts(rep);
	input = get_number("Index :");
	i = std::stoi(input);
	std::cout << "Firstname : " << rep[i].getFirstName() << std::endl;
	std::cout << "Lastname : " << rep[i].getLastName() << std::endl;
	std::cout << "Nickname : " << rep[i].getNickname() << std::endl;
	std::cout << "Phone number : " << rep[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << rep[i].getDarkestSecret() << std::endl;
}