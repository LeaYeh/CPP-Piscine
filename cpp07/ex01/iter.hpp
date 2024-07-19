#pragma once
#include <iostream>
#include <iterator>


// https://cplusplus.com/articles/D4SGz8AR/
template < typename T, int N, typename Function >
void iter(T (&array)[N], int length, Function func)
{
    if (length > N)
        throw (std::range_error("Cannot iter out of array size."));
    for (int i = 0; i < length; i++)
        func(array[i]);
}

template <typename T>
void printElementWithNewLine(T &value)
{
    std::cout << value << std::endl;
}

template <typename T>
void printElement(T &value)
{
    std::cout << value << " ";
}

// template <typename T, int N>
// int arraySize(T (&)[N])
// {
//     return N;
// }

// template < typename T >
// void iter(T &array, const size_t length, void (*f)(T &));

// template < typename T >
// void iter(const T &array, const size_t length, void (*f)(const T &));

