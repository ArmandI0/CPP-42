/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:53:34 by aranger           #+#    #+#             */
/*   Updated: 2024/06/08 16:43:06 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	
}

ScalarConverter::ScalarConverter(ScalarConverter const &cpy)
{
	*this = cpy;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const &cpy)
{
	(void)cpy;
	return *this;
}

ScalarConverter::~ScalarConverter()
{

}

void	ScalarConverter::convert(std::string str)
{
	double	convertedDouble;
	float	convertedFloat;
	int		convertedInt;
	char	convertedChar;
	std::string* tab[4] = {NULL};

	try{
		convertedDouble = convertToDouble(str);
		try{
			convertedFloat = convertToFloat(convertedDouble);
			try {
				convertedInt = convertToInt(convertedFloat);
				try {
					convertedChar = convertToChar(convertedInt);
				}
				catch (std::exception & e){
					tab[3] = new std::string(e.what());
				}
			}
			catch (std::exception & e){
				tab[2] = new std::string(e.what());
				tab[3] = new std::string(e.what());
			}
		}
		catch (std::exception & e){
			tab[1] = new std::string(e.what());
			tab[2] = new std::string(e.what());
			tab[3] = new std::string(e.what());
		}
	}
	catch (std::exception & e){
		try {
			convertedChar = convertToChar(str);
			convertedInt = convertToInt(convertedChar);
			convertedFloat = convertToFloat(convertedChar);
			convertedDouble = convertToDouble(convertedChar);
		}
		catch (std::exception & e){
			tab[3] = new std::string(e.what());
			std::string error = e.what();
			if (error.compare("non displayable") == 0)
			{
				convertedInt = convertToInt(convertedChar);
				convertedFloat = convertToFloat(convertedChar);
				convertedDouble = convertToDouble(convertedChar);
			}
			else
			{
				tab[2] = new std::string(e.what());
				tab[1] = new std::string(e.what());
				tab[0] = new std::string(e.what()); 
			}
		}
	}
	
	std::cout << std::fixed << std::setprecision(1);
	/* PRINT CHAR */
	if (tab[3] == NULL)
		std::cout << "Char : " << convertedChar << std::endl;
	else
		std::cout << "Char : " << *tab[3] << std::endl;
	
	/* PRINT INT */

	if (tab[2] == NULL)
		std::cout << "Int : " << convertedInt << std::endl;
	else
		std::cout << "Int : " << *tab[2] << std::endl;

	/* PRINT FLOAT */

	if (tab[1] == NULL)
		std::cout << "Float : " << convertedFloat << "f" << std::endl;
	else
		std::cout << "Float : " << *tab[1] << std::endl;
	
	/* PRINT DOUBLE */

	if (tab[0] == NULL)
		std::cout << "Double : " << convertedDouble << std::endl;
	else
		std::cout << "Double : " << *tab[0] << std::endl;
	
	for (int i = 0; i < 4; i++)
	{
		delete tab[i];
	}
}

char	convertToChar(std::string str)
{
	if(str.empty() || str.length() > 1)
		throw impossibleConvertion();
	if(std::isprint(str[0]) == 0)
		throw nonDisplayable();
	return (str[0]);
}

char	convertToChar(int convertInt)
{
	if (convertInt > 127 || convertInt < -128)
		throw impossibleConvertion();
	if (std::isprint(convertInt) == false)
		throw nonDisplayable();
	else
		return (static_cast<char>(convertInt));
}

float	convertToFloat(char c)
{
	float convertFloat = static_cast<float>(c);
	return convertFloat;
}

int		convertToInt(const char* str)
{
		int a = std::atoi(str);
		return(a);
}

int	convertToInt(float convertFloat)
{
	int	convertInt;

	if (convertFloat == std::numeric_limits<float>::quiet_NaN())
		throw impossibleConvertion();
	if (convertFloat > std::numeric_limits<int>::max() || convertFloat < std::numeric_limits<int>::min())
		throw impossibleConvertion();
	if (convertFloat != convertFloat)
		throw impossibleConvertion();
	convertInt = static_cast<int>(convertFloat);
	return convertInt;
}

int		convertToInt(char c)
{
	int convertInt = static_cast<int>(c);
	return convertInt;
}

double	convertToDouble(std::string str)
{
	double convertDouble;

	if (str.compare("-inff") == 0 || str.compare("-inf") == 0)
		return (-std::numeric_limits<double>::infinity());
	if (str.compare("+inff") == 0 || str.compare("-inf") == 0)
		return (std::numeric_limits<double>::infinity());
	if (str.compare("nan") == 0 || str.compare("nanf") == 0)
		return (std::numeric_limits<double>::quiet_NaN());
	std::istringstream iss(str);
	if (!(iss >> convertDouble))
		throw impossibleConvertion();
	else
		return (convertDouble);
}

double	convertToDouble(char c)
{
	double convertDouble = static_cast<double>(c);
	return convertDouble;
}

float	convertToFloat(double convertDouble)
{
	float convertFloat;

	if (convertDouble == -std::numeric_limits<float>::infinity())
		return (-std::numeric_limits<float>::infinity());
	if (convertDouble == std::numeric_limits<float>::infinity())
		return (std::numeric_limits<float>::infinity());
	if((convertDouble < -std::numeric_limits<float>::max() || convertDouble > std::numeric_limits<float>::max())) //&& convertDouble != 0)	
		throw impossibleConvertion();
	convertFloat = static_cast<float>(convertDouble);
	return convertFloat;
}

const char* impossibleConvertion::what() const throw()
{
	return ("impossible");
}

const char* nonDisplayable::what() const throw()
{
	return ("non displayable");
}
