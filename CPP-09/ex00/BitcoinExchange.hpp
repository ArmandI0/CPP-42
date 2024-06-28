/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:14:05 by aranger           #+#    #+#             */
/*   Updated: 2024/06/28 17:08:47 by aranger          ###   ########.fr       */
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

class BitcoinExchange
{
    private:
        std::map<std::string, double> _data;
        BitcoinExchange();
    public:
	    BitcoinExchange(std::string infile);
        ~BitcoinExchange();
        void printCsv();
		double returnBtcValue(std::string date);
};

bool	dateIsValid(std::string date);

#endif