#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{

}
template <typename T>
MutantStack<T>::MutantStack(MutantStack const &cpy)
{
	cpy++;
	*this = cpy;
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack<T> const &cpy)
{
	
	return this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{

}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return this->begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return this->end();
}

