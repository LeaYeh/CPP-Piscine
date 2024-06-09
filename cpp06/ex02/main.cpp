#include "Base.hpp"


int main()
{
    for (int i = 0; i < 10; i++)
    {
        Base *tmp = generate();
        std::cout << "Case " << i + 1 << ":\n";
        identify(tmp);
        identify(*tmp);
        delete tmp;
    }
    return 0;
}
