#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN \"<expression>\"" << std::endl;
        return (1);
    }
    RPN rpn;

    rpn.calculate(argv[1]);
    return (0);
}
