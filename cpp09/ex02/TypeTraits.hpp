#pragma once
#include <vector>
#include <deque>
#include <queue>

template <typename Container>
struct TypeTraits
{
    typedef typename Container::value_type value_type;
};

template <typename T>
struct TypeTraits<std::vector<T> >
{
    typedef T value_type;

    template <typename U>
    struct rebind
    {
        typedef std::vector<U> other;
    };
};

template <typename T>
struct TypeTraits<std::deque<T> >
{
    typedef T value_type;

    template <typename U>
    struct rebind
    {
        typedef std::deque<U> other;
    };
};
