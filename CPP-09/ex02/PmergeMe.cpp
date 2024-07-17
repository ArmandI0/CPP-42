/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:25:11 by aranger           #+#    #+#             */
/*   Updated: 2024/07/18 00:03:49 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Pair.hpp"

int	g_deep = 0;

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
	fordJhonsonSort<std::vector<int>, std::vector<Pair> >(this->_vector);
}

template <class Container, class ptrContainer>
void	fordJhonsonSort(Container toSort)
{
	ptrContainer	pair;
	
	for(typename Container::iterator it = toSort.begin(); it != toSort.end(); ++it)
	{
		if (it + 1 != toSort.end())
		{
			pair.push_back(Pair(*it, *(it + 1)));
			++it;
		}
		else
			pair.push_back(Pair(*it, -1));
	}
	for(typename ptrContainer::iterator it = pair.begin(); it != pair.end(); ++it)
	{
		it->printPair();
		it->sortPair();
		it->printPair();		
	}
	pair = mergeInsertion<Container, ptrContainer>(pair);
}

template <class Container, class ptrContainer>
ptrContainer mergeInsertion(ptrContainer pairs)
{
	std::cout << "DANS MERGE INSERTION" << std::endl;
	ptrContainer	newTab;
	if (pairs.size() <= 1)
		return pairs;
	for (typename ptrContainer::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it + 1 != pairs.end())
		{
			std::cout << "&*it = " << &*it << " &(*(it + 1) = " << &*(it + 1) << std::endl;
			newTab.push_back(Pair(&*it, &*(it + 1)));
			++it;
		}
		else
			(newTab.end() - 1)->addRest(&*it);
	}
	for(typename ptrContainer::iterator it = newTab.begin(); it != newTab.end(); ++it)
	{
		it->printPair();
		it->sortPair();
		it->printPair();		
	}
	ptrContainer output = mergeInsertion<Container, ptrContainer>(newTab);
	std::cout << " AFTER RECURCIVE " << std::endl;
	ptrContainer sortedList;
	Pair* rest = NULL;
	
	/* PUSH_BACK LOWER VALUE */
	
	for(typename ptrContainer::iterator it = output.begin(); it != output.end(); ++it)
	{
		if (it->getRest() != NULL)
			rest = &*(it->getRest()); 
		sortedList.push_back(*(it->getPairMax()));
	}
	sortedList.push_back(*(output.end() - 1)->getPairMin());

	/* INSERT REST IF EXIST */
	
	// if (rest != NULL)
	// {
	// 	std::cout << "RESTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT" << std::endl;
	// 	rest->printPair();
	// 	std::cout << "RESTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT" << std::endl;
	// }
	if (rest != NULL)
	{
		std::vector<Pair>::iterator it = std::lower_bound(sortedList.begin(), sortedList.end(), *rest, pairCompare);
		sortedList.insert(it, *rest);
	}

	/* INSERT MIN */
	
	// for(typename ptrContainer::iterator it = output.begin(); (it + 1) != output.end(); ++it)
	// {
	// 	std::vector<Pair>::iterator insert = std::lower_bound(sortedList.begin(), sortedList.end(), *(it->getPairMin()), pairCompare);
	// 	sortedList.insert(insert, *(it->getPairMin()));
	// }
	
	typename ptrContainer::iterator start, end;
	unsigned int index = 0;
	unsigned int n = 1;
	unsigned int JacobsthalNumber = 0;

	for (typename ptrContainer::iterator it = output.begin(); (it + 1) != output.end(); ++it)
	{
		std::cout << " it ";
		//it->printPair();
		start = end = it;
		index = 0;
		JacobsthalNumber = JacobsthalSuitCalcul(n);
		std::cout << "JacobsthalNumber = " << JacobsthalNumber << std::endl;
		
		// Incrémente end jusqu'à atteindre JacobsthalNumber ou la fin du conteneur
		while (index < JacobsthalNumber && (end + 1) != output.end())
		{
			index++;
			end++;
		}
		std::cout << "JACOB " << std::endl;
		// Insère les éléments dans sortedList dans l'ordre inverse
		while (end != start)
		{
			std::vector<Pair>::iterator insert = std::lower_bound(sortedList.begin(), sortedList.end(), *(end->getPairMin()), pairCompare);
			sortedList.insert(insert, *(end->getPairMin()));
			--end;
		}
		
		//Assurez-vous d'insérer start->getPairMin() si start != end
		if (start != end)
		{
			std::vector<Pair>::iterator insert = std::lower_bound(sortedList.begin(), sortedList.end(), *(start->getPairMin()), pairCompare);
			sortedList.insert(insert, *(start->getPairMin()));
		}
		n++;
		//it += JacobsthalNumber;
	}


	// for(typename ptrContainer::iterator it = output.begin(); (it + 1) != output.end(); ++it)
	// {
	// 	std::cout << " it " ;
	// 	it->printPair();
	// 	start = end = it;
	// 	index = 0;
	// 	JacobsthalNumber = JacobsthalSuitCalcul(n);
	// 	std::cout << "JacobsthalNumber = " << JacobsthalNumber << std::endl;
	// 	while (index < JacobsthalNumber && end + 2 != output.end())
	// 	{
	// 		index++;
	// 		it++;
	// 		end++;
	// 		//end->printPair();
	// 	}
	// 	std::cout << "JACOB " << std::endl;	
	// 	while (end != start)
	// 	{
	// 		std::vector<Pair>::iterator insert = std::lower_bound(start, sortedList.end(), *(end->getPairMin()), pairCompare);
	// 		sortedList.insert(insert, *(end->getPairMin()));
	// 		end--;
	// 	}
	// 	n++;
	// }

	for(typename ptrContainer::iterator it = sortedList.begin(); it != sortedList.end(); ++it)
	{
		it->printPair();		
	}
	return sortedList;
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

unsigned int JacobsthalSuitCalcul(unsigned int n)
{
	return ((pow(2, n) - pow(-1, n)) / 3 * 2); 
}
