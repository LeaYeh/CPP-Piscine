#include "iter.hpp"

template < typename T, typename Function >
void iter(T &array, int length, Function func)
{
    if (length > arraySize(array))
        throw (std::range_error("Cannot iter out of array size."));
    for (int i = 0; i < length; i++)
        func(array[i]);
}

template <typename T, int N>
int arraySize(T (&)[N])
{
    return N;
}
