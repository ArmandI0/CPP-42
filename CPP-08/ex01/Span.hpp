/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:45:06 by aranger           #+#    #+#             */
/*   Updated: 2024/06/16 18:47:54 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
#define SPAN_HPP
# include <vector>
# include <algorithm>
# include <iostream>

class Span
{
	public:
		Span(const unsigned int & n);
		Span(Span const &cpy);
		Span & operator=(Span const &cpy);
		~Span();

		void	addNumber(const int & n);
		void	addNumber(std::vector<int> & n);
		int		shortestSpan();
		int		longestSpan();
		void	printSpan();

	class SpanIsFull : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};

	class NotEnoughtElem : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};

	private:
		Span();
		std::vector<int>	_tab;
		unsigned int		_max;
};

#endif
