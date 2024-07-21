/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:25:17 by aranger           #+#    #+#             */
/*   Updated: 2024/07/17 23:16:32 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_hpp
#define PmergeMe_hpp
# include <vector>
# include <iostream>
# include <deque>
# include <algorithm>
# include <cmath>
# include <iomanip>

class  PmergeMe
{
    private :
        std::vector<int>					_vector;
        std::deque<int>						_deque;
        int                                 _size;

        PmergeMe(PmergeMe &cpy);
        PmergeMe operator=(PmergeMe &cpy);

    public :
        PmergeMe();
        ~PmergeMe();
        
        void    tabCreate(int ac, char **av);
        void    sort();
};

template <class Container, class ptrContainer>
Container	fordJhonsonSort(Container toSort);

template <class Container, class ptrContainer>
ptrContainer mergeInsertion(ptrContainer pairs);

template<class Container>
void printContainer(Container & tab);

unsigned int JacobsthalSuitCalcul(unsigned int n);

#endif