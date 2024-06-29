/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:14:05 by aranger           #+#    #+#             */
/*   Updated: 2024/06/29 17:54:30 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_hpp
#define BitcoinExchange_hpp
# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <sstream>
# include <regex.h>
# include <cstdlib>
# include <algorithm> 
# include <cctype>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _data;
    public:
	    BitcoinExchange();
        ~BitcoinExchange();
		void	convertWallet(std::string wallet);
};

bool	dateIsValid(std::string date);
bool 	findMonth(int month, int *months, int size);
bool 	isSpace(char c);

#endif