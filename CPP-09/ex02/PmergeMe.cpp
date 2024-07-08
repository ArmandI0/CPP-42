/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armandanger <armandanger@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:25:11 by aranger           #+#    #+#             */
/*   Updated: 2024/07/08 13:15:41 by armandanger      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
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

void PmergeMe::tabCreate(int ac, char **av)
{
	for (int i = 0; i < ac; i++)
	{
		std::string str(av[i]);
		if (str.find_first_not_of("0123456789"))
			throw std::invalid_argument("Error : invalid argument");
		else if(str.size() > 10)
			throw std::invalid_argument("Error : invalid argument");
		else if(str.size() == 10 && str.compare("2147483647") > 0)
			throw std::invalid_argument("Error : invalid argument");
	}
	for (int i = 0; i < ac; i++)
	{
		this->_vector.push_back(std::atoi(av[i]));
		this->_deque.push_back(std::atoi(av[i]));
	}
}



