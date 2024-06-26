#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Bureaucrat basic_staff("Alex", 150);
    Bureaucrat admin_staff("Bob", 1);
    Form form1("Document1", 5, 150);
    Form form2("Document2", 150, 150);

    try
    {
        std::cout << "Try to create a form with invalid grade\n";
        Form formInvalid("DocumentInvalid", 151, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << basic_staff << std::endl;
    basic_staff.signForm(&form1);
    std::cout << form1 << std::endl;
    basic_staff.signForm(&form2);
    std::cout << form2 << std::endl;

    std::cout << admin_staff << std::endl;
    admin_staff.signForm(&form1);
    std::cout << form1 << std::endl;
    admin_staff.signForm(&form2);
    std::cout << form2 << std::endl;

    return (0);
}
