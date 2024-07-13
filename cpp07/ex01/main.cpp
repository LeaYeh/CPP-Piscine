#include <iostream>
#include <iterator>
#include "iter.hpp"

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

int main(void)
{
    {
        std::cout << "Test iter() with const and non-const function\n";
        int arr[] = {1, 2, 3, 4};

        std::cout << "\nPrint out each element with non-const function\n";
        iter(arr, 4, printElement<int>);
        std::cout << "\nPrint out each element with const function\n";
        iter(arr, 4, printElement<const int>);
    }
    {
        int arr[] = {1, 2, 3, 4};

        std::cout << "\nPrint out each element with <int>\n";
        iter(arr, 4, printElement<int>);
        std::cout << "\nPrint out each with newline element with <int>\n";
        iter(arr, 4, printElementWithNewLine<int>);
    }
    {
        char arr[] = {'a', 'b', 'c', 'd'};

        std::cout << "\nPrint out each element with <char>\n";
        iter(arr, 4, printElement<char>);
        std::cout << "\nPrint out each with newline element with <char>\n";
        iter(arr, 4, printElementWithNewLine<char>);
    }
    {
        float arr[] = {1.1f, 2.2f, 3.3f, 4.4f};

        std::cout << "\nPrint out each element with <float>\n";
        iter(arr, 4, printElement<float>);
        std::cout << "\nPrint out each with newline element with <float>\n";
        iter(arr, 4, printElementWithNewLine<float>);
    }
    {
        int arr[] = {1, 2, 3, 4};

        try
        {
            std::cout << "\nPrint out each element with <int>\n";
            iter(arr, 10, printElement<int>);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
