/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armandanger <armandanger@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:25:11 by aranger           #+#    #+#             */
/*   Updated: 2024/07/15 17:20:12 by armandanger      ###   ########.fr       */
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

void    PmergeMe::sort()
{
	fordJhonsonSort<std::vector<int>, std::vector<int*> >(this->_vector);
}

template <class Container, class ptrContainer>
void	fordJhonsonSort(Container toSort)
{
	ptrContainer	startingList;
	for (typename Container::iterator it = toSort.begin(); it != toSort.end(); ++it)
	{
		startingList.push_back(&(*it));
	}
	printContainer(startingList);
	//Container		allMax;

	startingList = mergeInsertion<Container, ptrContainer>(toSort, startingList);

}

template <class Container, class ptrContainer>
ptrContainer mergeInsertion(Container values, ptrContainer ptr)
{
	/* STOP CONDITION */
	if (ptr.size() <= 1)
	 	return ptr;

	/* MAKE PAIR AND SORT EACH PAIRS */

	values = sortPair<Container>(values);
	printContainer(values);

	/* PUSH MAX OF EACH PAIR */

	Container			maxOfEachPair;
	ptrContainer		maxOfEachPtr, newValues;
	for (typename Container::iterator it = values.begin(); it != values.end(); ++it)
	{
		if (it + 1 != values.end())
		{
			maxOfEachPtr.push_back(&(*it));
			maxOfEachPair.push_back((*it));
			it++;
		}
	}
	//printContainer(maxOfEachPair);

	/* RECURSIVLY SORT PAIRS */

	newValues = mergeInsertion<Container, ptrContainer>(maxOfEachPair, maxOfEachPtr);
	std::cout << "newValues + 1 = " << *(maxOfEachPtr[0]) << std::endl;
	// if ((newValues[0] + 1) != &(*values.end()))
    // 	newValues.insert((newValues.begin()), *(newValues[0]) + 1);
	// if (std::next(newValues[0]) != values.end())
	// 	newValues.insert(newValues.begin(), (newValues[0] + 1));
	// for (typename Container::iterator it = newValues.begin(); it != newValues.end(); ++it)
	// {
	// 	if (it + 1 != values.end())
	// 	{
	// 		maxOfEachPair.push_back(*it);
	// 		it++;
	// 	}
	// }
	std::cout << "values = ";
	printContainer(values);
	std::cout << "newValues = ";
	printPtrContainer(ptr);
	std::cout << "maxOfEachPair = ";
	printContainer(maxOfEachPair);
	std::cout << std::endl;
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

template<class Container, class PairContainer>
PairContainer makePair(Container tab)
{
	PairContainer	sortedByPair;
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
Container sortPair(Container tab)
{
	std::cout << "BEFORE = ";
	printContainer(tab);
	//std::cout << std::endl;
	//std::cout << "SORT   = ";
	for (typename Container::iterator it = tab.begin(); it != tab.end(); ++it)
	{
		if (it + 1 != tab.end())
		{
		//	std::cout << "(" << *(it + 1) << ", " << *it << ")";
			if ((*(it + 1)) > (*it))
				std::swap((*it), (*(it + 1)));
			++it;
		}
	}
	//std::cout << std::endl;
	std::cout << "AFTER  = ";
	printContainer(tab);
	std::cout << std::endl;
	return tab;
}

template<class Container>
void printContainer(Container tab)
{
	for (typename Container::iterator it = tab.begin(); it != tab.end(); ++it)
	{
		if (it + 1 != tab.end())
		{
			std::cout << "(" << (*it) << ", " << (*(it + 1)) << ")";
			it++;
		}
		else
			std::cout << *it;
	}
	std::cout << std::endl;
}

template<class Container>
void printPtrContainer(Container tab)
{
	for (typename Container::iterator it = tab.begin(); it != tab.end(); ++it)
	{
		if (it + 1 != tab.end())
		{
			std::cout << "(" << *(*it) << ", " << *(*(it + 1)) << ")";
			it++;
		}
		else
			std::cout << *it;
	}
	std::cout << std::endl;
}

template<class PairContainer>
void printPairContainer(PairContainer tab)
{
	for (typename PairContainer::iterator it = tab.begin(); it != tab.end(); ++it)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}
