/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:57:15 by aranger           #+#    #+#             */
/*   Updated: 2024/06/18 15:28:39 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
# include <iostream>
# include <stack>
# include <list>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack &cpy);
		MutantStack & operator=(MutantStack & cpy);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();		
		iterator end();

		
	private:
		
};

#endif
