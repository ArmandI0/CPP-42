/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:25:11 by aranger           #+#    #+#             */
/*   Updated: 2024/07/03 20:37:57 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
}
PmergeMe::PmergeMe(std::vector<std::string> entry)
{
    for(std::vector<std::string>::iterator it = entry.begin(); it != entry.end(); ++it)
	{
		if (it->find_first_not_of("0123456789") == std::string::npos || it)
	}
}
PmergeMe::PmergeMe(PmergeMe &cpy)
{
    
}
PmergeMe PmergeMe::operator=(PmergeMe &cpy)
{
    
}
PmergeMe::~PmergeMe()
{
    
}

std::vector<int> PmergeMe::fordJhonsonSort(std::vector<int> tab)
{
    
}


