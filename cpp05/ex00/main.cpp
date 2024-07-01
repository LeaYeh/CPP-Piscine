#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        std::cout << "Try to create a bureaucrat with default constructor\n";
        Bureaucrat bureaucrat_default;
        std::cout << bureaucrat_default << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "Try to create a bureaucrat with valid grade: 100\n";
        Bureaucrat bureaucrat_valid("Alex", 100);
        std::cout << bureaucrat_valid << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "Try to create a bureaucrat with valid grade: 15\n";
        Bureaucrat bureaucrat_valid("Bob", 15);
        std::cout << bureaucrat_valid << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "Try to create a bureaucrat with invalid grade: 200\n";
        Bureaucrat bureaucrat_invalid2("Claire", 200);
        std::cout << bureaucrat_invalid2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "Try to create a bureaucrat with invalid grade: -10\n";
        Bureaucrat bureaucrat_invalid3("Duke", -10);
        std::cout << bureaucrat_invalid3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bureaucrat_valid("Alex", 3);
        std::cout << "Try to increment grade of bureaucrat with grade 3\n";
        bureaucrat_valid.incrementGrade();
        std::cout << bureaucrat_valid << std::endl;
        /* code */
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat bureaucrat_valid("Alex", 149);
        std::cout << "Try to decrement grade of bureaucrat with grade 149\n";
        bureaucrat_valid.decrementGrade();
        std::cout << bureaucrat_valid << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat bureaucrat_valid("Alex", 1);
        std::cout << "Try to increment grade of bureaucrat with grade 1\n";
        bureaucrat_valid.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat bureaucrat_valid("Alex", 150);
        std::cout << "Try to decrement grade of bureaucrat with grade 150\n";
        bureaucrat_valid.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}
