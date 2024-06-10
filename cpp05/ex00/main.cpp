#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat bureaucrat_default;
        std::cout << bureaucrat_default << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bureaucrat_valid("Alex", 100);
        std::cout << bureaucrat_valid << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bureaucrat_invalid1("Bob", 15);
        std::cout << bureaucrat_invalid1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bureaucrat_invalid2("Claire", 200);
        std::cout << bureaucrat_invalid2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bureaucrat_invalid3("Duke", -10);
        std::cout << bureaucrat_invalid3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}
