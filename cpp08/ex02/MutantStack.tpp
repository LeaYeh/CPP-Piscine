#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack<T, Container> &other)
{
    if (this != &other)
    {
        std::stack<T, Container>::operator=(other);
    }
    return *this;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin(void)
{
    return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(void)
{
    return (this->c.end());
}
