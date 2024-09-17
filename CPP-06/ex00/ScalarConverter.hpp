/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:53:37 by aranger           #+#    #+#             */
/*   Updated: 2024/06/08 11:51:01 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include <sstream>
# include <limits>
# include <iomanip> 

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &cpy);
		ScalarConverter & operator=(ScalarConverter const &cpy);
		~ScalarConverter();

		static void	convert(std::string str);
};

char	convertToChar(std::string str);
char	convertToChar(int convertInt);

float	convertToFloat(double convertDouble);
float	convertToFloat(char c);

int		convertToInt(const char* str);
int		convertToInt(float convertFloat);
int		convertToInt(char c);

double	convertToDouble(std::string str);
double	convertToDouble(char c);

class impossibleConvertion : public std::exception
{
	public :
		virtual const char* what() const throw();
};

class nonDisplayable : public std::exception
{
	public :
		virtual const char* what() const throw();
};

#endif
