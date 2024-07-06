#include <vector>
#include <list>
#include "easyfind.hpp"

int main(void)
{
    {
        int target;
        std::vector<int> vec;

        for (int i = 0; i < 5; i++)
            vec.push_back(i);
        target = 3;
        std::cout << "Try to find target " << target << std::endl;
        easyfind(vec, target);
        target = 10;
        std::cout << "Try to find target " << target << std::endl;
        easyfind(vec, target);
    }
    {
        float target;
        std::list<float> list;

        for (int i = 0; i < 5; i++)
            list.push_back(i * 0.5);
        target = 1.5;
        std::cout << "Try to find target " << target << std::endl;
        easyfind(list, target);
        target = 10.2;
        std::cout << "Try to find target " << target << std::endl;
        easyfind(list, target);
    }

    return (0);
}
