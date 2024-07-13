#pragma once
#include <iostream>

template <typename T>
class Array
{
public:
    Array();
    Array(const unsigned int &n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();

    T &operator[](const unsigned int index);
    const T &operator[](const unsigned int index) const;

    unsigned int size(void) const;
    void printElements(void) const;

protected:
private:
    unsigned int _size;
    T *_data;

    void _deepCopy(const Array &other);
};

#include "Array.tpp"
