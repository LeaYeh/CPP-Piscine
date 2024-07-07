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

    iterator begin(void) { return (this->c.begin()); };
    iterator end(void) { return (this->c.end()); };

protected:
private:
};

#include "MutantStack.tpp"
