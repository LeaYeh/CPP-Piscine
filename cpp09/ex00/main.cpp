#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "usage: ./btc [input_file]" << std::endl;
        return (1);
    }
    try
    {
        BitcoinExchange btc(argv[1]);

        btc.run();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
