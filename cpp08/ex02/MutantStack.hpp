#pragma once
#include <iostream>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    MutantStack() : std::stack<T, Container>(){};
    MutantStack(const MutantStack &other) : std::stack<T, Container>(other){};
    MutantStack &operator=(const MutantStack &other);
    ~MutantStack(){};

    iterator begin(void);
    iterator end(void);

protected:
private:
};

std::ostream &operator<<(std::ostream &os, const MutantStack<T, Container> &obj);

#include "MutantStack.tpp"
