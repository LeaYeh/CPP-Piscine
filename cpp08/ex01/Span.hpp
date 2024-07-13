#pragma once
#include <iostream>
#include <iterator>
#include <cmath>
#include <limits>
#include <algorithm>

class Span
{
public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    int &operator[](const unsigned int index);
    const int &operator[](const unsigned int index) const;

    unsigned int size(void) const;
    unsigned int capacity(void) const;
    void addNumber(const int &num);
    template <typename Iterator>
    void addNumbers(const Iterator begin, const Iterator end);
    int shortestSpan(void);
    int longestSpan(void);

protected:
private:
    const unsigned int _capacity;
    unsigned int _size;
    int *_data;

    void _deepCopy(const Span &other);
};

std::ostream &operator<<(std::ostream &os, const Span &obj);

#include "Span.tpp"
