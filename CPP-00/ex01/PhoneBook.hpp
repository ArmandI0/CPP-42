/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:15:17 by aranger           #+#    #+#             */
/*   Updated: 2024/04/27 17:41:19 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_H
# define PhoneBook_H
# include "Contact.hpp"

std::string	get_info(std::string req);
void		print_contacts(Contact *rep);
std::string	get_number(std::string req);

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		Contact rep[8];
		void	add_contact();
		void	search();
};

#endif