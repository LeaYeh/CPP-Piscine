template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
    if (this != &other)
        std::stack<T>::operator=(other);
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const
{
    return (this->c.end());
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const MutantStack<T> &obj)
{
    typename MutantStack<T>::const_iterator it = obj.begin();
    typename MutantStack<T>::const_iterator ite = obj.end();
    while (it != ite)
    {
        os << *it << std::endl;
        ++it;
    }
    return os;
}
