#pragma once
#include <iostream>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <deque>
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
    PmergeMe();
    PmergeMe(const std::string &input);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    bool sort(void);
    void printSortedResult(void) const;
    void printTaskInfo(void) const;

private:
    Container _inputNumbers;
    FordJohnsonSort<Container> _fjs;

    bool _isValidateInt(const std::string &token);
    bool _parseInput(const std::string &input);
    void _printElements(const Container &container) const;
    double _roundToDecimalPlaces(double value, int places) const;
    std::string _getFormattedContainerType(const Container &container) const;
    std::string _simplifyContainerType(const std::string &containerType) const;
    std::string _getFormattedNumbers(const Container &container) const;
    std::string _getFormattedTaskInfo(const FordJohnsonSort<Container> &fjs) const;
    bool _isSorted(const Container &container) const;
};

#include "PmergeMe.tpp"
