#include "Array.hpp"


int main(void)
{
    {
        std::cout << std::endl;
        Array<int> array_int;
        Array<float> array_float;
        Array<char> array_char;
    }
    {
        std::cout << std::endl;
        Array<int> array_int(10);

        array_int.printElements();
    }
    {
        std::cout << std::endl;
        Array<int> array_int(5);
        Array<float> array_float(10);

        for (int i = 0; i < 5; i++)
            array_int[i] = i + 1;
        for (int i = 0; i < 10; i++)
            array_float[i] = i * 0.5;
        array_int.printElements();
        array_float.printElements();
    }
    {
        std::cout << std::endl;
        Array<int> array_int(5);
        Array<int> array_int2(10);

        for (int i = 0; i < 5; i++)
            array_int[i] = i + 1;
        for (int i = 0; i < 10; i++)
            array_int2[i] = i * 2;

        std::cout << "array_int: ";
        array_int.printElements();
        std::cout << "array_int2: ";
        array_int2.printElements();

        array_int = array_int2;
        std::cout << "array_int: ";
        array_int.printElements();
    }
    {
        std::cout << std::endl;
        Array<int> array_int(5);

        for (int i = 0; i < 5; i++)
            array_int[i] = 0;
        array_int.printElements();
        array_int[1] = 5;
        array_int.printElements();
        try
        {
            std::cout << "array_int[10]: " << array_int[10];
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return (0);
}
