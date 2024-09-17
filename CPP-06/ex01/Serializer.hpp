/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:19:54 by aranger           #+#    #+#             */
/*   Updated: 2024/06/08 13:23:21 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Serializer_HPP
# define Serializer_HPP
# include <iostream>
# include <string>
# include <stdint.h>


struct Data
{
	int 		integer;
	char		character;
	std::string	str;
	bool		status;
};

class Serializer
{	
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private :
		Serializer();
		Serializer(Serializer const &cpy);
		Serializer & operator=(Serializer const &cpy);
		virtual ~Serializer();
};

#endif