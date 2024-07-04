/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:25:17 by aranger           #+#    #+#             */
/*   Updated: 2024/07/03 20:36:39 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_hpp
#define PmergeMe_hpp
# include <vector>
# include <iostream>

class  PmergeMe
{
    private :
        std::vector<int>    tab;
        PmergeMe();
        PmergeMe(PmergeMe &cpy);
        PmergeMe operator=(PmergeMe &cpy);

    public :
        PmergeMe(std::vector<std::string> entry);
        ~PmergeMe();
        static std::vector<int> fordJhonsonSort(std::vector<int> tab);
};

#endif