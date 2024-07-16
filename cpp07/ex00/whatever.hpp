#pragma once
#include <iostream>

/*
1. the implementation of the function template should be in the header file or the tpp file
2. Should put the reference in min and max function to avoid copying the value, sometimes it is not possible to copy the value
3. Always use the reference to avoid copying the value
4. Always use the const reference if it is not necessary to change the value
5. move semantics since c++11
    - move assignment
    ```example
        template <typename T>
        void swap(T &a, T &b)
        {
            move semantics since c++11
            T tmp = std::move(a);
            a = std::move(b);
            b = std::move(tmp);
        }
    ```
6. namespace
    - The default namespace is the global namespace
    - Use the namespace to avoid the conflict of the function name
*/

template <typename T>
void swap(T &a, T &b)
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T& min(T &a, T &b)
{
    return (a < b ? a : b);
}

template <typename T>
T& max(T &a, T &b)
{
    return (a > b ? a : b);
}
