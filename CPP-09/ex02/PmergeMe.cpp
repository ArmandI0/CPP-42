/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:25:11 by aranger           #+#    #+#             */
/*   Updated: 2024/07/10 15:10:56 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
}

PmergeMe::PmergeMe(PmergeMe &cpy)
{
    *this = cpy;
}
PmergeMe PmergeMe::operator=(PmergeMe &cpy)
{
    this->_deque = cpy._deque;
	this->_vector = cpy._vector;
	return *this;
}
PmergeMe::~PmergeMe()
{
    
}

void	PmergeMe::fordJhonsonSort()
{
	std::cout << "starting list = ";
	printContainer(this->_vector);
	mergeInsertion< std::vector<int>, std::vector<std::pair<int, int> > > (this->_vector);
}

template <class Container, class PairContainer>
Container mergeInsertion(Container values)
{
	if (values.size() <= 1)
	 	return values;
	PairContainer	pairedValues;
	pairedValues = makePair<Container, PairContainer>(values);
	printPairContainer(pairedValues);
	Container		maxOfEachPair, newValues;
	for (typename PairContainer::iterator it = pairedValues.begin(); it != pairedValues.end(); ++it)
	{
		maxOfEachPair.push_back(it->first);
	}
	std::cout << "max of each pair = ";
	printContainer(maxOfEachPair);
	newValues = mergeInsertion<Container, PairContainer>(maxOfEachPair);
	for (typename PairContainer::iterator it = pairedValues.begin(); it != pairedValues.end(); ++it)
	{
		if (it->second != -1)
		{
			typename Container::iterator insert;
			insert = std::lower_bound(newValues.begin(), newValues.end(), it->second);
			newValues.insert(insert, it->second);
		}
	}
	std::cout << "new values after pair " << std::endl;
	printContainer(newValues);
	return newValues;
}

void PmergeMe::tabCreate(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string str(av[i]);
		if (str.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << "find first of" << std::endl;
			throw std::invalid_argument("Error : invalid argument");
		}
		else if(str.size() > 10)
			throw std::invalid_argument("Error : invalid argument");
		else if(str.size() == 10 && str.compare("2147483647") > 0)
			throw std::invalid_argument("Error : invalid argument");
	}
	for (int i = 1; i < ac; i++)
	{
		this->_vector.push_back(std::atoi(av[i]));
		this->_deque.push_back(std::atoi(av[i]));
	}
}

template<class Container, class Pair>
Pair makePair(Container tab)
{
	Pair	sortedByPair;
	for (typename Container::iterator it = tab.begin(); it != tab.end(); ++it)
	{
		if (it + 1 != tab.end())
		{
			if (*(it + 1) >= *it)
				sortedByPair.push_back(std::make_pair(*(it + 1), *it));
			else
				sortedByPair.push_back(std::make_pair(*it, *(it + 1)));
			it++;
		}
		else
			sortedByPair.push_back(std::make_pair(*it, -1));
	}
	return sortedByPair;
}

template<class Container>
void printContainer(Container tab)
{
	for (typename Container::iterator it = tab.begin(); it != tab.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template<class pairContainer>
void printPairContainer(pairContainer tab)
{
	for (typename pairContainer::iterator it = tab.begin(); it != tab.end(); ++it)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}
