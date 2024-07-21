/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:14:05 by aranger           #+#    #+#             */
/*   Updated: 2024/07/21 18:08:33 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_hpp
#define BitcoinExchange_hpp
# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <regex.h>
# include <algorithm> 

class BitcoinExchange
{
    private:
        std::map<std::string, double> _data;
    public:
	    BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange & cpy);
        BitcoinExchange & operator=(const BitcoinExchange & cpy);
        
		void	convertWallet(std::string wallet);
};

bool	dateIsValid(std::string date);
bool 	findMonth(int month, int *months, int size);
bool 	isSpace(char c);

#endif