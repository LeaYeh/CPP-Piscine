#pragma once

template <typename T, typename Function>
void iter(T &array, int length, Function func);

template <typename T, int N>
int arraySize(T (&)[N]);

// template < typename T >
// void iter(T &array, const size_t length, void (*f)(T &));

// template < typename T >
// void iter(const T &array, const size_t length, void (*f)(const T &));

#include "iter.tpp"
