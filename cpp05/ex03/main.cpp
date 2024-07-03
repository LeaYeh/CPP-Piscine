#include "Intern.hpp"
#include "Bureaucrat.hpp"

void testIntern(void);

int main(void)
{
    testIntern();
    return (0);
}

void testIntern(void)
{
    Intern intern;
    AForm *form;

    {
        std::cout << "\nA intern try to create form..." << FORM_TYPE_R << std::endl;
        form = intern.makeForm(FORM_TYPE_R, "target1");
        std::cout << *form;
        delete form;
    }
    {
        std::cout << "\nA intern try to create form..." << FORM_TYPE_S << std::endl;
        form = intern.makeForm(FORM_TYPE_S, "target2");
        std::cout << *form;
        delete form;
    }
    {
        std::cout << "\nA intern try to create form..." << FORM_TYPE_P << std::endl;
        form = intern.makeForm(FORM_TYPE_P, "target3");
        std::cout << *form;
        delete form;
    }
    {
        try
        {
            std::cout << "\nA intern try to create form which is not valid" << std::endl;
            form = intern.makeForm("invalid", "target3");
            delete form;
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
