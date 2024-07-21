/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:14:00 by aranger           #+#    #+#             */
/*   Updated: 2024/07/21 18:07:12 by aranger          ###   ########.fr       */
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
			std::cerr << "Data error : invalid header. " << std::endl;
			break;
		}
		else if (lineNumber != 1)
		{
			i = line.find(',');
			if (i == -1)
				std::cerr << "Data error : invalid format at line " << lineNumber << std::endl;
			else
			{
				char* end;
				entry = strtod(&line[i + 1], &end);
				date = line.substr(0, i);
				if (end == &line[i + 1] || dateIsValid(date) == false || *end != 0)
				{
					std::cerr << "Data error : invalid format at line " << lineNumber << std::endl;
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

	if (getline(data, line))
	{
		line.erase(std::remove_if(line.begin(), line.end(), isSpace), line.end());
		if (lineNumber == 1 && line.compare("date|value") != 0)
		{
			std::cerr << "Error : invalid file or header." << std::endl;
			return;
		}
	}
	else
	{
		std::cerr << "Error : Empty file " << line << std::endl;
		return;
	}
    while (getline(data, line))
	{
		line.erase(std::remove_if(line.begin(), line.end(), isSpace), line.end());
		i = line.find('|');
		if (i == -1)
			std::cerr << "Error : bad input " << line << std::endl;
		else
		{
			char* end;
			entry = strtod(&line[i + 1], &end);
			date = line.substr(0, i);
			if (dateIsValid(date) == false)
				std::cerr << "Error : invalid date : " << line << std::endl;
			else if (end == &line[i + 1] || *end != 0)
				std::cerr << "Error : invalid number." << std::endl;
			else if (entry < 0.0)
				std::cerr << "Error : not a positive number." << std::endl;
			else if (entry > 1000)
				std::cerr << "Error: too large number." << std::endl;				
			else
			{
				it = this->_data.lower_bound(date);
				if(it == this->_data.end())
				{
					std::cerr << "Error : No data available for this date" << std::endl;
					continue;
				}
				else if ((it != this->_data.begin() && it->first.compare(date) != 0))
					it--;
				std::cout << date << " => " << entry << " = " << entry * it->second << std::endl;
			}
		}
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & cpy)
{
    this->_data = cpy._data;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & cpy)
{
    if (this != &cpy)
	{
        this->_data = cpy._data;
    }
    return *this;
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
	char	*error;
	long	year = std::strtol(date.c_str(), &error,date.size());
	long	month = std::strtol(&date.c_str()[5], &error,date.size());
	long	day = std::strtol(&date.c_str()[8], &error,date.size());
	int		fullMonth[7] = {1, 3, 5, 7, 8, 10, 12};
	int		leanMonth[4] = {4, 6, 9, 11};
	bool	bisextilYear = false;

	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		bisextilYear = true;
	if ((month == 2 && ((bisextilYear == false && (day > 28 || day < 1)) || (bisextilYear == true && (day > 29|| day < 1)))))
		boolean = false;
	else if ((findMonth(month, fullMonth, 7) && (day > 31 || day < 1)) || month > 12 || month < 1)
		boolean = false;
	else if (findMonth(month, leanMonth, 4) && (day > 30 || day < 1))
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
