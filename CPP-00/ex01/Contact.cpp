/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:17:29 by aranger           #+#    #+#             */
/*   Updated: 2024/04/27 15:13:59 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

Contact::Contact(void)
{
	firstname = "";
	lastname = "";
	nickname = "";
	phone_number = "";
	darkest_scrt = "";
}
Contact::~Contact(void){}

std::string Contact::getFirstName(){return firstname;}
std::string Contact::getLastName(){return lastname;}
std::string Contact::getNickname(){return nickname;}
std::string Contact::getPhoneNumber(){return phone_number;}
std::string Contact::getDarkestSecret(){return darkest_scrt;}

void Contact::setFirstName(std::string firstname){this->firstname = firstname;}
void Contact::setLastName(std::string lastname){this->lastname = lastname;}
void Contact::setNickname(std::string nickname){this->nickname = nickname;}
void Contact::setPhoneNumber(std::string phone_number){this->phone_number = phone_number;}
void Contact::setDarkestSecret(std::string darkest_secret){this->darkest_scrt = darkest_secret;}