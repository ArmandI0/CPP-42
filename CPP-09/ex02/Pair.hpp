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

bool    pairCompare(const Pair & a, const Pair & b);

#endif
