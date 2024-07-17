/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:53:08 by aranger           #+#    #+#             */
/*   Updated: 2024/07/17 23:25:41 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Pair_hpp
#define Pair_hpp
# include "PmergeMe.hpp"

class   Pair
{
    private :
        int     _max;
        int     _min;
        Pair*   _pairMax;
        Pair*   _pairMin;
        Pair*   _rest;

    public :
        Pair();
        Pair(int max, int min);
        Pair(Pair* max, Pair* min);
        ~Pair();

        Pair(const Pair & cpy);
        Pair & operator=(const Pair & cpy);

        void    sortPair();
        void    printPair();
        void    addRest(Pair* rest);
        
        int     getMin() const;
        int     getMax() const;
        Pair*   getPairMax();
        Pair*   getPairMin();
        Pair*   getRest();
};

bool    pairCompare(const Pair & a, const Pair & b)
{
    if (a.getMax() < b.getMax())
        return false;
    return true;
}

Pair::Pair() : _max(-1) , _min(-1) , _pairMax(NULL) , _pairMin(NULL) , _rest(NULL)
{
    
}

Pair::Pair(int max, int min) : _max(max) , _min(min) , _pairMax(NULL) , _pairMin(NULL) , _rest(NULL)
{

}

Pair::Pair(Pair* max, Pair* min) : _pairMax(max) , _pairMin(min) , _rest(NULL)
{
    if (max != NULL)
        this->_max = _pairMax->getMax();
    if (min != NULL)
        this->_min = _pairMin->getMax();
    else
        this->_min = -1;
}

Pair::~Pair()
{
    
}

Pair::Pair(const Pair & cpy)
{
    this->_pairMax = cpy._pairMax;
    this->_pairMin = cpy._pairMin;
    *this = cpy; 
}

Pair & Pair::operator=(const Pair & cpy)
{
    // if (this == &cpy)
    //     return (*this);
    this->_max = cpy._max;
    this->_min = cpy._min;
    this->_pairMax = cpy._pairMax;
    this->_pairMin = cpy._pairMin;
    this->_rest = cpy._rest;
    return *this;
}

void    Pair::sortPair()
{
    if (this->_max < _min)
    {
        std::swap(this->_pairMax, this->_pairMin);
        std::swap(this->_max, this->_min);
    }    
}

void    Pair::printPair()
{
    std::cout << this->_max << " " << this->_min << std::endl;
    //std::cout << "REST = " << _rest << std::endl;
    //std::cout << "pairMax = " << _pairMax << std::endl;
    //std::cout << "pairMin = " << _pairMin << std::endl;

}

void    Pair::addRest(Pair* rest)
{
    this->_rest = rest;
}

int Pair::getMin() const
{
    return this->_min;            
}

int Pair::getMax() const
{
    return this->_max;        
}

Pair*   Pair::getPairMax()
{
    return this->_pairMax;
}
Pair*   Pair::getPairMin()
{
    return this->_pairMin;
}
Pair*   Pair::getRest()
{
    return this->_rest;
}



#endif
