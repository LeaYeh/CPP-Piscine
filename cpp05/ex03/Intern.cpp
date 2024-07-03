#include "Intern.hpp"

std::string Intern::formType[3] = {FORM_TYPE_R, FORM_TYPE_S, FORM_TYPE_P};

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
    // AForm *(Intern::*makeForm[3])(const std::string &name, const std::string &target) const = {
    //     &Intern::makeFormR, &Intern::makeFormS, &Intern::makeFormP};
    AForm *form = NULL;
    typedef AForm *(Intern::*FormMaker)(const std::string &name, const std::string &target) const;
    typedef FormMaker FormMakerArray[3];
    FormMakerArray formMakers = {&Intern::makeFormR, &Intern::makeFormS, &Intern::makeFormP};
    bool matchFound = false;

    for (int i = 0; i < 3; i++)
    {
        if (name == formType[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            form = (this->*formMakers[i])(name, target);
            matchFound = true;
            break;
        }
    }
    if (!matchFound)
    {
        throw std::runtime_error("No matching form type found");
    }
    return (form);
}

AForm *Intern::makeFormR(const std::string &name, const std::string &target) const
{
    return (new RobotomyRequestForm(name, target));
}

AForm *Intern::makeFormS(const std::string &name, const std::string &target) const
{
    return (new ShrubberyCreationForm(name, target));
}

AForm *Intern::makeFormP(const std::string &name, const std::string &target) const
{
    return (new PresidentialPardonForm(name, target));
}
