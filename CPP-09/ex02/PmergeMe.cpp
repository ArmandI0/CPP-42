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
	Container		output;
	ptrContainer	pair;
	int				rest = -1;

	for(typename Container::iterator it = toSort.begin(); it != toSort.end(); ++it)
	{
		if (it + 1 != toSort.end())
		{
			pair.push_back(Pair(*it, *(it + 1)));
			++it;
		}
		else
			rest = *it;
	}
	/* SORT PAIR */
	for(typename ptrContainer::iterator it = pair.begin(); it != pair.end(); ++it)
	{
		it->printPair();
		it->sortPair();
		it->printPair();		
	}
	pair = mergeInsertion<Container, ptrContainer>(pair);

	for(typename ptrContainer::iterator it = pair.begin(); it != pair.end(); ++it)
	{
		output.insert(output.begin(), it->getMax());
		if (it + 1 == pair.end())
		{
			output.insert(output.begin(), it->getMin());
			pair.erase((pair.end() - 1));
			break;
		}
	}

	if (rest != -1)
	{
		typename Container::iterator it = std::lower_bound(output.begin(), output.end(), rest);
		output.insert(it, rest);
	}

	unsigned int jacobIndex = 1;
	bool		a = true;
    while (a)
    {

        unsigned int pos = JacobsthalSuitCalcul(jacobIndex);
		typename ptrContainer::iterator end = pair.end();
		typename ptrContainer::iterator start = end;
		while (pos != 0)
		{
			if (start == pair.begin())
			{
				a = false;
				break;
			}
			start--;
			pos--;
		}
		while (start != pair.end())
		{
			typename Container::iterator insert = std::lower_bound(output.begin(), output.end(), (start->getMin()));
			output.insert(insert, start->getMin());
			pair.erase(start);
		}
        jacobIndex++;
    }



	for(typename Container::iterator it = output.begin(); it != output.end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;
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
	output.erase((output.end() - 1));

	/* INSERT REST IF EXIST */

	if (rest != NULL)
	{
		typename ptrContainer::iterator it = std::lower_bound(sortedList.begin(), sortedList.end(), *rest, pairCompare);
		sortedList.insert(it, *rest);
	}

	/* INSERT MIN */
	
	// for(typename ptrContainer::iterator it = output.begin(); (it + 1) != output.end(); ++it)
	// {
	// 	std::vector<Pair>::iterator insert = std::lower_bound(sortedList.begin(), sortedList.end(), *(it->getPairMin()), pairCompare);
	// 	sortedList.insert(insert, *(it->getPairMin()));
	// }


    /* INSERT MIN ACCORDING TO JACOBSTAHL SEQUENCE FROM THE END */

    unsigned int jacobIndex = 1;
	bool		a = true;
    while (a)
    {

        unsigned int pos = JacobsthalSuitCalcul(jacobIndex);
		typename ptrContainer::iterator end = output.end();
		typename ptrContainer::iterator start = end;
		while (pos != 0)
		{
			if (start == output.begin())
			{
				a = false;
				break;
			}
			start--;
			pos--;
		}
		while (start != output.end())
		{
			typename ptrContainer::iterator insert = std::lower_bound(sortedList.begin(), sortedList.end(), *(start->getPairMin()), pairCompare);
			sortedList.insert(insert, *(start->getPairMin()));
			output.erase(start);
		}
        jacobIndex++;
    }

    // /* HANDLE REMAINING PAIRS */
    // for (unsigned int i = 0; i < output.size(); ++i)
    // {
    //     if (!inserted[i])
    //     {
    //         std::vector<Pair>::iterator insert = std::lower_bound(sortedList.begin(), sortedList.end(), *(output[i].getPairMin()), pairCompare);
    //         sortedList.insert(insert, *(output[i].getPairMin()));
    //     }
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
