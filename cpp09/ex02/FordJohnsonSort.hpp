#pragma once
#include <cmath>
#include "Pair.hpp"
#include "JacobsthalGenerator.hpp"
#include "TypeTraits.hpp"

// Container = std::vector<int>
template <typename Container>
class FordJohnsonSort
{
public:
    typedef typename TypeTraits<Container>::value_type ValueType;
    typedef Pair<Container> ContainerPair;
    typedef typename TypeTraits<Container>::template rebind<ContainerPair>::other ContainerPairContainer;

    FordJohnsonSort();
    FordJohnsonSort(Container &numbers);
    FordJohnsonSort(const FordJohnsonSort &other);
    FordJohnsonSort &operator=(const FordJohnsonSort &other);
    ~FordJohnsonSort();

    int getCompareCount(void) const;
    int getLevel(void) const;
    Container getNumbers(void) const;
    Container getSortedNumbers(void) const;
    void setNumbers(Container &numbers);
    void sort(void);

protected:
private:
    Container _numbers;
    Container _sortedNumbers;
    int _level;
    int _compareCount;

    ContainerPairContainer _recursiveSort(ContainerPairContainer &pairs);
    bool _pairwise(ContainerPairContainer &pairs, ContainerPairContainer &currentLevelRemainderPairs);
    void _setupPairElement(ContainerPairContainer &pairs, Container &numbers, int index, int elementSize);
    void _insertion(ContainerPairContainer &pairs, ContainerPairContainer &remainderPairs);
    void _binarySort(ContainerPairContainer &container, ContainerPair target);
    void _reshapePairs(ContainerPairContainer &pairs, int elementSize) const;
    void _mergePairs(ContainerPairContainer &pairs, ContainerPairContainer &remainderPairs);
    Container _convertToNumbers(const ContainerPairContainer &pairs) const;
};

#include "FordJohnsonSort.tpp"
