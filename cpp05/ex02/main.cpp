#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testShrubberyFormExecute(void);
void testRobotomyFormExecute(void);
void testPresidentFormExecute(void);

int main(void)
{
    testShrubberyFormExecute();
    testRobotomyFormExecute();
    testPresidentFormExecute();

    return (0);
}

void testShrubberyFormExecute(void)
{
    AForm *form = new ShrubberyCreationForm("form1", "target1");
    Bureaucrat bureaucrat_base("base", 140);
    Bureaucrat bureaucrat_admin("admin", 1);

    std::cout << "\n[testShrubberyFormExecute]\n";
    std::cout << *form;
    std::cout << "---------------------------------" << std::endl;
    try
    {
        std::cout << bureaucrat_base << std::endl;
        std::cout << bureaucrat_base.getName() << " tries to sign " << form->getName() << std::endl;
        form->beSigned(bureaucrat_base);
        std::cout << *form;
        std::cout << bureaucrat_base.getName() << " tries to execute " << form->getName() << std::endl;
        bureaucrat_base.executeForm(*form);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << bureaucrat_admin << std::endl;
        std::cout << bureaucrat_admin.getName() << " tries to sign " << form->getName() << std::endl;
        form->beSigned(bureaucrat_admin);
        std::cout << *form;
        std::cout << bureaucrat_admin.getName() << " tries to execute " << form->getName() << std::endl;
        bureaucrat_admin.executeForm(*form);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete form;
}

void testRobotomyFormExecute(void)
{
    AForm *form = new RobotomyRequestForm("form2", "target2");
    Bureaucrat bureaucrat_base("base", 60);
    Bureaucrat bureaucrat_admin("admin", 1);

    std::cout << "\n[testRobotomyFormExecute]\n";
    std::cout << *form;
    std::cout << "---------------------------------" << std::endl;
    try
    {
        std::cout << bureaucrat_base << std::endl;
        std::cout << bureaucrat_base.getName() << " tries to sign " << form->getName() << std::endl;
        form->beSigned(bureaucrat_base);
        std::cout << *form;
        std::cout << bureaucrat_base.getName() << " tries to execute " << form->getName() << std::endl;
        bureaucrat_base.executeForm(*form);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << bureaucrat_admin << std::endl;
        std::cout << bureaucrat_admin.getName() << " tries to sign " << form->getName() << std::endl;
        form->beSigned(bureaucrat_admin);
        std::cout << *form;
        std::cout << bureaucrat_admin.getName() << " tries to execute " << form->getName() << std::endl;
        bureaucrat_admin.executeForm(*form);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete form;
}

void testPresidentFormExecute(void)
{
    AForm *form = new PresidentialPardonForm("form3", "target3");
    Bureaucrat bureaucrat_base("base", 20);
    Bureaucrat bureaucrat_admin("admin", 1);

    std::cout << "\n[testPresidentFormExecute]\n";
    std::cout << *form;
    std::cout << "---------------------------------" << std::endl;
    try
    {
        std::cout << bureaucrat_base << std::endl;
        std::cout << bureaucrat_base.getName() << " tries to sign " << form->getName() << std::endl;
        form->beSigned(bureaucrat_base);
        std::cout << *form;
        std::cout << bureaucrat_base.getName() << " tries to execute " << form->getName() << std::endl;
        bureaucrat_base.executeForm(*form);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << bureaucrat_admin << std::endl;
        std::cout << bureaucrat_admin.getName() << " tries to sign " << form->getName() << std::endl;
        form->beSigned(bureaucrat_admin);
        std::cout << *form;
        std::cout << bureaucrat_admin.getName() << " tries to execute " << form->getName() << std::endl;
        bureaucrat_admin.executeForm(*form);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete form;
}
