#include "PmergeMe.hpp"
#include <list>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <integers>" << std::endl;
        return (1);
    }
    std::string input = "";

    for (int i = 1; i < argc; i++)
    {
        input += argv[i];
        if (i < argc - 1)
            input += " ";
    }
    PmergeMe<std::list<int> > pmm(input);

    pmm.sort();

    return (0);
}
