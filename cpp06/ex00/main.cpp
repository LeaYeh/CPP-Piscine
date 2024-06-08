#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Invalid input\n";
        return (1);
    }
    ScalarConverter converter(argv[1]);
    converter.run();
    return (0);
}
