/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:23:07 by aranger           #+#    #+#             */
/*   Updated: 2024/05/01 10:33:28 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl	hrl;

	hrl.complain("DEBUG");
	hrl.complain("INFO");
	hrl.complain("WARNING");
	hrl.complain("ERROR");
}