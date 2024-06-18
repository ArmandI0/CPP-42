#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{

}
template <typename T>
MutantStack<T>::MutantStack(MutantStack &cpy)
{
	*this = cpy;
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack<T> & cpy)
{
	iterator it = cpy.begin();
	iterator ite = cpy.end();

	while (this->empty() == false)
		this->pop();
	for(; it != ite; ++it)
	{
		this->push(*it);
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{

}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	iterator a = std::stack<T>::c.begin();
	return a;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	iterator a = std::stack<T>::c.end();
	return a;
}
