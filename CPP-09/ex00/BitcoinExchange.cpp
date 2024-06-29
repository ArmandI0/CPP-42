/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:14:00 by aranger           #+#    #+#             */
/*   Updated: 2024/06/29 18:50:43 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream data("data.csv");
    if (!data)
        throw std::invalid_argument("Error : data.csv needed");

    std::string line;
    std::string	date;
	size_t		lineNumber = 1;
	int      	i;
    double      entry = 0.0;
	
    while (getline(data, line))
    {
		if (lineNumber == 1 && line.compare("date,exchange_rate") != 0)
		{
			std::cerr << "Error : invalid header. " << std::endl;
			break;
		}
		else if (lineNumber != 1)
		{
			i = line.find(',');
			if (i == -1)
				std::cerr << "Error : invalid format at line " << lineNumber << std::endl;
			else
			{
				std::stringstream convertDouble(line.substr(i + 1, line.size()));
				convertDouble >> entry;
				date = line.substr(0, i);
				if (convertDouble.fail() || dateIsValid(date) == false)
				{
					std::cerr << "Error : invalid format at line " << lineNumber << std::endl;
				}
				else
					_data.insert(std::make_pair(date, entry));
			}
    	}
		lineNumber++;
	}
}

BitcoinExchange::~BitcoinExchange()
{
    
}

void	BitcoinExchange::convertWallet(std::string wallet)
{
	std::ifstream data(wallet.c_str());
    if (!data)
	{
        throw std::invalid_argument("Error : bad infile");
	}
	std::map<std::string, double>::iterator it;
	std::string line;
	std::string	date;
	int      i;
	size_t		lineNumber = 1;
    double      entry = 0.0;

    while (getline(data, line))
	{
		line.erase(std::remove_if(line.begin(), line.end(), isSpace), line.end());
		if (lineNumber == 1 && line.compare("date|value") != 0)
		{
			std::cerr << "Error : invalid header." << std::endl;
			break;
		}
		else if (lineNumber != 1)
		{
			i = line.find('|');
			if (i == -1)
				std::cerr << "Error : bad input " << line << std::endl;
			else
			{
				std::stringstream convertDouble(line.substr(i + 1, line.size()));
				convertDouble >> entry;
				date = line.substr(0, i);
				if (dateIsValid(date) == false)
					std::cerr << "Error : invalid date." << line << std::endl;
				else if (convertDouble.fail())
					std::cerr << "Error : invalid number." << std::endl;
				else if (entry < 0.0)
					std::cerr << "Error : not a positive number." << std::endl;
				else if (entry > 1000)
					std::cerr << "Error: too large a number." << std::endl;				
				else
				{
					it = this->_data.lower_bound(date);
					if (it == this->_data.end() || (it != this->_data.begin() && it->first.compare(date) != 0))
						it--;
					std::cout << date << " => " << entry << " = " << entry * it->second << std::endl;
				}
			}
		}
		lineNumber++;
	}
}

bool	dateIsValid(std::string date)
{
	regex_t		regex;
	int			ret;
	bool		boolean = true;
	
	ret = regcomp(&regex, "^([0-9]{4}-[0-9]{2}-[0-9]{2})", REG_EXTENDED | REG_ICASE);
	if (ret != 0)
		throw std::bad_alloc();
	ret = regexec(&regex, date.c_str(),0, NULL, 0);
	if (ret != 0)
	{
		regfree(&regex);
		return false;
	}
	int		year = std::atoi(date.c_str());
	int		month = std::atoi(&date.c_str()[5]);
	int		day = std::atoi(&date.c_str()[8]);
	int		fullMonth[7] = {1, 3, 5, 7, 8, 10, 12};
	int		leanMonth[4] = {4, 6, 9, 11};
	bool	bisextilYear = false;
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		bisextilYear = true;
	if ((month == 2 && ((bisextilYear == false && day > 28) || (bisextilYear == true && day > 29))))
		boolean = false;
	else if ((findMonth(month, fullMonth, 7) && day > 31) || month > 12)
		boolean = false;
	else if (findMonth(month, leanMonth, 4) && day > 30)
		boolean = false;
	regfree(&regex);
	return boolean;
}

bool findMonth(int month, int *months, int size)
{
    for (int i = 0; i < size; ++i)
	{
        if (months[i] == month)
            return true;
    }
    return false;
}

bool isSpace(char c)
{
	return (std::isspace(c));
}
