#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define FORM_TYPE_R "robotomy request"
#define FORM_TYPE_S "shrubbery creation request"
#define FORM_TYPE_P "presidential pardon"




class Intern
{
public:
    static std::string formType[3];
    Intern(){};
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern(){};

    AForm *makeForm(const std::string &name, const std::string &target) const;

private:
    AForm *makeFormR(const std::string &name, const std::string &target) const;
    AForm *makeFormS(const std::string &name, const std::string &target) const;
    AForm *makeFormP(const std::string &name, const std::string &target) const;
};
