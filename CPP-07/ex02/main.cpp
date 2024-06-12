/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:58:35 by aranger           #+#    #+#             */
/*   Updated: 2024/06/12 21:42:56 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
		std::cout << " NUMBERS " << std::endl;
		for (int i = 0; i < 10; i++)
		{
			std::cout << numbers[i] << " ";
		}
		std::cout << std::endl;
        Array<int> tmp = numbers;
		std::cout << " = " << std::endl;
		for (int i = 0; i < 10; i++)
		{
			std::cout << numbers[i] << " ";
		}
		std::cout << std::endl;
        Array<int> test(tmp);
		std::cout << " COPY " << std::endl;
		for (int i = 0; i < 10; i++)
		{
			std::cout << numbers[i] << " ";
		}
		std::cout << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}