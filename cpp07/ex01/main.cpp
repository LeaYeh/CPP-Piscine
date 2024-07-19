#include "iter.hpp"

/*
1. The tpp file will be included in the header file, we can consider the tpp file is the extension of the header file
    - But the tpp file is not so common, for the simplicity, we can put the implementation of the function template in the header file
2. During the compilation, the compiler will know the declaration of the variable,
    it will replace the content of the function template with the actual type, like the following example: `arraySize<int, 5>(array)`
    ```
        template <typename T, int N>
        int arraySize(T (&)[N]);
    ```
*/

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
