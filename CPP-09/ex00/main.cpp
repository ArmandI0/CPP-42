/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:57:49 by aranger           #+#    #+#             */
/*   Updated: 2024/06/29 18:53:52 by aranger          ###   ########.fr       */
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
	try
	{
		BitcoinExchange a;
		a.convertWallet(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}