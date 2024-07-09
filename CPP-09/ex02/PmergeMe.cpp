/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:25:11 by aranger           #+#    #+#             */
/*   Updated: 2024/07/08 22:26:43 by aranger          ###   ########.fr       */
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
	mergeInsertion< std::vector<int>, std::vector<std::pair<int, int> > > (this->_vector);
}

template <class Container, class PairContainer>
PairContainer mergeInsertion(Container c)
{
	PairContainer	pair;
	pair = makePair<Container, PairContainer>(c);
	std::cout << "wouhou" << std::endl;
	if (c.size() <= 2)
		return pair;
	Container maxOfEachPairRight, maxOfEachPairLeft;
	size_t i = 0;
	for (typename PairContainer::iterator it = pair.begin(); it != pair.end(); ++it)
	{
		if (i <= pair.size())
			maxOfEachPairLeft.push_back(it->first);
		else
			maxOfEachPairRight.push_back(it->first);
	}
	PairContainer	pairedLeft, pairedRight;
	pairedRight = mergeInsertion<Container, PairContainer>(maxOfEachPairRight);
	printContainer(pairedRight);
	pairedLeft = mergeInsertion<Container, PairContainer>(maxOfEachPairLeft);
	printContainer(pairedLeft);
	for (typename PairContainer::iterator it = pairedRight.begin(); it != pairedRight.end(); ++it)
	{
		pairedLeft.push_back(*it);
	}
	return pairedLeft;
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

template<class pairContainer>
void printContainer(pairContainer tab)
{
	for (typename pairContainer::iterator it = tab.begin(); it != tab.end(); ++it)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}
