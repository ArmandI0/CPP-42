/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:58:35 by aranger           #+#    #+#             */
/*   Updated: 2024/06/11 17:50:43 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void ft_toupper(char &c)
{
	c = std::toupper(c);
}

void	add(int &a)
{
	a += 2;
}

int	main(void)
{
	int tab[10] = {1,2,3,4,5,6,7,8,9};
	for (int i = 0; i < 10; i++)
	{
		std::cout << " " << tab[i] << " "; 
	}
	iter(tab, 10, add);
	std::cout << "after iteration" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << " " << tab[i] << " "; 
	}

	// std::string a = "blablabalba";
	// iter(a, a, toupper);
	// std::cout << "Before ITER" << a << "After ITER" << std::endl;
}