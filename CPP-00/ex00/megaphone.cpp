/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 23:36:56 by armandanger       #+#    #+#             */
/*   Updated: 2024/04/26 13:36:30 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	std::string str;
	for (int i = 1; i < ac; i++)
		str.append(std::string(av[i]));
	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);	
	std::cout << str << std::endl;
}