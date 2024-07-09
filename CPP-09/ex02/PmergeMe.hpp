/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:25:17 by aranger           #+#    #+#             */
/*   Updated: 2024/07/08 22:23:29 by aranger          ###   ########.fr       */
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

		void	fordJhonsonSort();
};

template<class Container, class Pair>
Pair makePair(Container tab);

template<class pairContainer>
void printContainer(pairContainer tab);

template <class Container, class pairContainer>
pairContainer mergeInsertion(Container c);

#endif