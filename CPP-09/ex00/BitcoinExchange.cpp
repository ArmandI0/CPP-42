/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:14:00 by aranger           #+#    #+#             */
/*   Updated: 2024/06/28 17:15:11 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(std::string infile)
{
	(void)infile;
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

void	BitcoinExchange::printCsv()
{
        for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); ++it)
        {
            std::cout << it->first << "," << it->second << std::endl;
        }
}

double	BitcoinExchange::returnBtcValue(std::string date)
{
	std::map<std::string, double>::iterator it;
	it = this->_data.find(date);
	return it->second;
}

bool	dateIsValid(std::string date)
{
	const char *pattern = "([0-9]{4})-([0-9]{2})-([0-9]{2})";
	regex_t		regex;
	int			ret;
	
	date.empty();
	ret = regcomp(&regex, pattern, 0);
	if (ret != 0)
		throw std::bad_alloc();
	
	return true;
}
