/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:57:49 by aranger           #+#    #+#             */
/*   Updated: 2024/06/29 21:50:51 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **argv)
{
	if (ac != 2)
		return 1;
	rpnCalculate(argv[1]);
	return 0;
}