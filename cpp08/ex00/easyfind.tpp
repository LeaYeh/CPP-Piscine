template <typename T>
void easyfind(const T &container, int target)
{
    typename T::const_iterator it;
    // int i = 0;

    it = std::find(container.begin(), container.end(), target);
    if (it != container.end())
        std::cout << "Find the target at index: " << std::distance(container.begin(), it) << std::endl;
    else
        std::cout << "Cannot Find the target\n";
    // for (it = container.begin(); it != container.end(); it++, i++)
    // {
    //     if (target == *it)
    //     {
    //         std::cout << "Find the target at index: " << i << std::endl;
    //         return ;
    //     }
    // }
    // std::cout << "Cannot Find the target\n";
}
