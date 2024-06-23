/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:14:00 by aranger           #+#    #+#             */
/*   Updated: 2024/06/16 21:14:01 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream data("data.csv");
    if (!data)
        throw std::invalid_argument("Error : data.csv needed");
    else
    {
        std::string line;
        size_t      i;
        double      entry = 0.0;
        while (getline(data, line))
        {
            i = line.find(',');
            std::stringstream convertDouble(line.substr(i + 1, line.size()));
            convertDouble >> entry;
            if (convertDouble.fail())
            {
                _data.insert(std::make_pair(line.substr(0, i), -1));
            }
            else
                _data.insert(std::make_pair(line.substr(0, i), entry));
        }
    }  
}

BitcoinExchange::~BitcoinExchange()
{
    
}

void BitcoinExchange::printCsv()
{
        for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); ++it)
        {
            std::cout << it->first << "," << it->second << std::endl;
        }
}
