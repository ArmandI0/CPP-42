/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:14:05 by aranger           #+#    #+#             */
/*   Updated: 2024/06/16 21:14:06 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_hpp
#define BitcoinExchange_hpp
# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _data;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        void printCsv();
};

#endif