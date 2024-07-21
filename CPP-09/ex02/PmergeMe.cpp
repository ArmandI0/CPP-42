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
	this->_size = cpy._size;
	return *this;
}
PmergeMe::~PmergeMe()
{
    
}

void    PmergeMe::sort()
{
	std::vector<int> r;

	clock_t start = clock();
	r = fordJhonsonSort<std::vector<int>, std::vector<Pair> >(this->_vector);
	clock_t end = clock();
	double time = (end - start)  / (double)CLOCKS_PER_SEC * 10;

	std::cout << "Before: ";
	printContainer(this->_vector);
	std::cout << "After: ";
	printContainer(r);

	std::cout << "Time to process a range of " << this->_size << " elements with std::vector: ";
	std::cout << std::fixed << std::setprecision(5) << time;
	std::cout << " us" << std::endl;

	start = clock();
	fordJhonsonSort<std::deque<int>, std::deque<Pair> >(this->_deque);
	end = clock();
	time = (end - start)  / (double)CLOCKS_PER_SEC * 10;
	std::cout << "Time to process a range of " << this->_size << " elements with std::deque: ";
	std::cout << std::fixed << std::setprecision(5) << time;
	std::cout << " us" << std::endl;
}

template <class Container, class ptrContainer>
Container	fordJhonsonSort(Container toSort)
{
	Container		output;
	ptrContainer	pair;
	int				rest = -1;

	/* MAKE PAIR */

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
		it->sortPair();

	pair = mergeInsertion<Container, ptrContainer>(pair);

	for (typename ptrContainer::iterator it = pair.begin(); it != pair.end(); ++it)
	{
		output.insert(output.begin(), it->getMax());
		typename ptrContainer::iterator next_it = it;
		++next_it;
		if (next_it == pair.end())
		{
			output.insert(output.begin(), it->getMin());
			pair.erase(--pair.end());
			break;
		}
	}

	if (rest != -1)
	{
		typename Container::iterator it = std::lower_bound(output.begin(), output.end(), rest);
		output.insert(it, rest);
	}

	unsigned int jacobIndex = 1;
	bool a = true;

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
			--start;
			--pos;
		}
		while (start != pair.end())
		{
			typename Container::iterator insert = std::lower_bound(output.begin(), output.end(), start->getMin());
			output.insert(insert, start->getMin());
			start = pair.erase(start);
		}
		jacobIndex++;
	}
	return output;
}

template <class Container, class ptrContainer>
ptrContainer mergeInsertion(ptrContainer pairs)
{
    /* MAKE AND SORT NEW PAIRS */

    ptrContainer newTab;

    if (pairs.size() <= 1)
        return pairs;

    for (typename ptrContainer::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        typename ptrContainer::iterator next_it = it;
        ++next_it;

        if (next_it != pairs.end())
        {
            newTab.push_back(Pair(&*it, &*next_it));
            ++it;
        }
        else
        {
            (newTab.end() - 1)->addRest(&*it);
        }
    }

    for (typename ptrContainer::iterator it = newTab.begin(); it != newTab.end(); ++it)
        it->sortPair();

    /* RECURSIVELY SORT */

    ptrContainer output = mergeInsertion<Container, ptrContainer>(newTab);
    ptrContainer sortedList;

    typename ptrContainer::iterator rest;
    bool r = false;

    /* PUSH BACK LOWER VALUE */

    for (typename ptrContainer::iterator it = output.begin(); it != output.end(); ++it)
    {
        if (it->getRest() != NULL)
        {
            r = true;
            rest = it;
        }
        sortedList.push_back(*(it->getPairMax()));
    }
    sortedList.push_back(*(output.back().getPairMin()));

    /* INSERT REST IF EXISTS */

    if (r)
    {
        typename ptrContainer::iterator it = std::lower_bound(sortedList.begin(), sortedList.end(), *(rest->getRest()), pairCompare);
        sortedList.insert(it, *(rest->getRest()));
    }
    output.pop_back();

    /* INSERT MIN WITH JACOBSTHAL SEQUENCE */
	
    unsigned int jacobIndex = 1;
    bool a = true;
    while (a)
    {
        unsigned int pos = JacobsthalSuitCalcul(jacobIndex);
        typename ptrContainer::iterator start = output.end();
        while (pos != 0)
        {
            if (start == output.begin())
            {
                a = false;
                break;
            }
            --start;
            --pos;
        }
        while (start != output.end())
        {
            typename ptrContainer::iterator insert = std::lower_bound(sortedList.begin(), sortedList.end(), *(start->getPairMin()), pairCompare);
            sortedList.insert(insert, *(start->getPairMin()));
            start = output.erase(start);
        }
        ++jacobIndex;
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
			throw std::invalid_argument("Error : numeric and positive arguments are required");
		}
		else if(str.size() > 10)
			throw std::invalid_argument("Error : The function accepts numbers between 0 and 2 147 483 647 as valid input.");
		else if(str.size() == 10 && str.compare("2147483647") > 0)
			throw std::invalid_argument("Error : The function accepts numbers between 0 and 2 147 483 647 as valid input.");
	}
	for (int i = 1; i < ac; i++)
	{
		this->_vector.push_back(std::atoi(av[i]));
		this->_deque.push_back(std::atoi(av[i]));
	}
	this->_size = ac - 1;
}

unsigned int JacobsthalSuitCalcul(unsigned int n)
{
	return ((pow(2, n) - pow(-1, n)) / 3 * 2); 
}

template<class Container>
void printContainer(Container & tab)
{
	for (typename Container::iterator it = tab.begin(); it != tab.end(); ++it)
	{
		std::cout << " " << (*it);
	}
	std::cout << std::endl;
}
