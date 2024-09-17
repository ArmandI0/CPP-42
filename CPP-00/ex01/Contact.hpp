/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:23:20 by armandanger       #+#    #+#             */
/*   Updated: 2024/04/27 15:17:49 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_H
# define Contact_H
# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
	public:
		Contact();
		~Contact();
		
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhoneNumber();
		std::string getDarkestSecret();

		void setFirstName(std::string firstname);
		void setLastName(std::string lastname);
		void setNickname(std::string nickname);
		void setPhoneNumber(std::string phone_number);
		void setDarkestSecret(std::string darkest_secret);

	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_scrt;
	
};


#endif