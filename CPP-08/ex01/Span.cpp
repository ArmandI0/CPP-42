/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:45:01 by aranger           #+#    #+#             */
/*   Updated: 2024/06/16 18:52:49 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _max(0)
{
	
}
Span::Span(const unsigned int & n) : _max(n)
{

}

Span::Span(Span const &cpy)
{
	*this = cpy;
}

Span & Span::operator=(Span const &cpy)
{
	for(std::vector<int>::const_iterator it = cpy._tab.begin(); it != cpy._tab.end(); ++it)
	{
		this->_tab.push_back(*it);
	}
	this->_max = cpy._max;
	return *this;
}

Span::~Span()
{

}

const char* Span::SpanIsFull::what() const throw()
{
	return ("The array is already full");	
}

const char* Span::NotEnoughtElem::what() const throw()
{
	return ("Not enought elements");
}

void Span::addNumber(const int & n)
{
	if (this->_tab.size() == this->_max)
		throw Span::SpanIsFull();
	this->_tab.push_back(n);
}

void	Span::addNumber(std::vector<int> & n)
{
	for(std::vector<int>::iterator it = n.begin(); it != n.end(); ++it)
	{
		addNumber(*it);
	}
}

int Span::shortestSpan()
{
	if (this->_tab.size() < 2)
		throw Span::NotEnoughtElem(); 

	Span tmp = *this;
	std::sort(tmp._tab.begin(), tmp._tab.end());

	std::vector<int>::iterator it = tmp._tab.begin();
	int span = std::abs(*it - *(it + 1));
	for (;it + 1 != tmp._tab.end(); ++it)
	{
		if(std::abs(*it - *(it + 1)) <= span)
			span = std::abs(*it - *(it + 1));
	}
	return span;
}
int Span::longestSpan()
{
	if (this->_tab.size() < 2)
		throw Span::NotEnoughtElem(); 
	Span tmp = *this;
	std::sort(tmp._tab.begin(), tmp._tab.end());
	int min = *tmp._tab.begin();
	int max = *(tmp._tab.end() - 1);
	return (std::abs(min - max));
}

void Span::printSpan()
{
	for (std::vector<int>::iterator it = this->_tab.begin(); it != _tab.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


