#pragma once
#include <iostream>
#include <limits>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include "FordJohnsonSort.hpp"

template <typename T>
struct is_supported_container
{
    enum
    {
        value = 0
    };
};

template <>
struct is_supported_container<std::vector<int> >
{
    enum
    {
        value = 1
    };
};

template <>
struct is_supported_container<std::deque<int> >
{
    enum
    {
        value = 1
    };
};


template <typename Container, bool IsSupported = is_supported_container<Container>::value>
class PmergeMe;

// Primary template for unsupported types
// Container = std::vector<int>
template <typename Container>
class PmergeMe<Container, false>
{
// Only defined for unsupported types, to trigger a compile-time error
public:
    PmergeMe();
    PmergeMe(const std::string &input);
    void sort(void) {};
};

// Specialization for supported types
template <typename Container>
class PmergeMe<Container, true>
{
public:
    // typedef std::pair<int, int> Pair;
    PmergeMe();
    PmergeMe(const std::string &input);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void sort(void);

private:
    Container _inputNumbers;

    bool _isValidateInt(const std::string &token);
    bool _parseInput(const std::string &input);
    void _printElements(const Container &container) const;
};

#include "PmergeMe.tpp"
