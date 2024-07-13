#include "MutantStack.hpp"

int main()
{
    {
        std::cout << "Test basic functionality:\n";
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    {
        std::cout << "Test type string:\n";
        MutantStack<std::string> mstack;

        mstack.push("haha");
        mstack.push("so funny");
        MutantStack<std::string>::iterator it = mstack.begin();
        MutantStack<std::string>::iterator ite = mstack.end();
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    {
        std::cout << "Test const iterator:\n";
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);
        mstack.push(3);

        MutantStack<int>::const_iterator it = mstack.begin();
        MutantStack<int>::const_iterator ite = mstack.end();

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::cout << mstack << std::endl;
    }
    return (0);
}
