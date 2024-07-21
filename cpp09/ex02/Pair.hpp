#pragma once

// T = std::vector<int>
template <typename T>
class Pair
{
public:
    Pair();
    Pair(T first, T second);
    Pair(T silo);
    Pair(const Pair &other);
    Pair &operator=(const Pair &other);
    ~Pair();

    const T &first(void) const;
    const T &second(void) const;
    const T &single(void) const;
    const typename T::value_type &getUpperBound(void) const;
    const typename T::value_type &getLowerBound(void) const;
    int getElementSize(void) const;
    void swap(void);
    void printPairs(void) const;

protected:
private:
    T _first;
    T _second;
    T _single;
    int _elementSize;

    void _updateSingle(void);
};

#include "Pair.tpp"
