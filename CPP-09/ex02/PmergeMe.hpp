/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:25:17 by aranger           #+#    #+#             */
/*   Updated: 2024/07/11 12:44:22 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_hpp
#define PmergeMe_hpp
# include <vector>
# include <iostream>
# include <deque>
# include <iterator>
# include <utility>
# include <algorithm>

class  PmergeMe
{
    private :
        std::vector<int>					_vector;
        std::deque<int>						_deque;

        PmergeMe(PmergeMe &cpy);
        PmergeMe operator=(PmergeMe &cpy);

    public :
        PmergeMe();
        ~PmergeMe();
        
        void    tabCreate(int ac, char **av);

		template <class Container, class PairContainer>
        void	PmergeMe::fordJhonsonSort();
};

template<class Container, class Pair>
Pair makePair(Container tab);

template<class Container>
void printContainer(Container tab);

template<class pairContainer>
void printPairContainer(pairContainer tab);

template <class Container, class PairContainer>
Container mergeInsertion(Container values);

#endif