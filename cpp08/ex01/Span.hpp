#pragma once
#include <iostream>
#include <iterator>
#include <cmath>
#include <limits>
#include <vector>
#include <algorithm>

class Span
{
public:
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    int &operator[](const unsigned int index);
    const int &operator[](const unsigned int index) const;

    unsigned int size(void) const;
    unsigned int capacity(void) const;
    void addNumber(const int &num);
    int shortestSpan(void);
    int longestSpan(void);

    template <typename Iterator>
    void addNumbers(const Iterator begin, const Iterator end)
    {
        if (this->_size + std::distance(begin, end) > this->_capacity)
            throw(std::length_error("Not enough capacity."));
        for (Iterator it = begin; it != end; it++)
            this->_data[this->_size++] = *it;
    }

protected:
private:
    const unsigned int _capacity;
    unsigned int _size;
    int *_data;

    void _deepCopy(const Span &other);
};

std::ostream &operator<<(std::ostream &os, const Span &obj);
