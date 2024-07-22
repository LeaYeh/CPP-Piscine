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
    try
    {
        PmergeMe<std::vector<int> > pmm_vector(input);
        PmergeMe<std::deque<int> > pmm_deque(input);

        pmm_vector.sort();
        pmm_deque.sort();

        pmm_vector.printSortedResult();
        pmm_vector.printTaskInfo();
        pmm_deque.printTaskInfo();
    } catch (std::exception &e)
    {
        return (1);
    }

    return (0);
}
