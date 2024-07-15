/*
1. pair
    - sort the elements first and the second is larger than the first
    - if the input is odd, the last element will be alone and process it at last step
2. compare the pairs second element and sort them
3. 
*/

#pragma once
#include <iostream>

template <typename Container>
class PmergeMe
{
public:
    typedef std::pair<int, int> Pair;
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void sort(void);

private:
    Container _inputNumbers;
    Container _element
    int _compare_cnt;
    int _swap_cnt;
    bool _parseInput(const std::string &input);
    void _printSortingResult(void) const;
    void _initPair(void);
    bool _isLarger(const int &a, const int &b) const;
};
