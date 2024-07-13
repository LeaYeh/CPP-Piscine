#pragma once
#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;

    MutantStack() : std::stack<T, std::deque<T> >(){};
    MutantStack(const MutantStack &other) : std::stack<T, std::deque<T> >(other){};
    MutantStack &operator=(const MutantStack &other);
    ~MutantStack(){};

    iterator begin(void);
    iterator end(void);
    const_iterator begin(void) const;
    const_iterator end(void) const;

protected:
private:
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const MutantStack<T> &obj);

#include "MutantStack.tpp"
