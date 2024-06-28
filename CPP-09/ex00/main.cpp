/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:57:49 by aranger           #+#    #+#             */
/*   Updated: 2024/06/28 15:42:56 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **argv)
{
	if (ac != 2)
	{
		std::cout << "Error : could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange a(argv[1]);
	a.printCsv();
	return 0;
}