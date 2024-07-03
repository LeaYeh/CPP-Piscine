#pragma once
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

#define R_SIGN_GRADE 72
#define R_EXEC_GRADE 45
#define R_DEFAULT_FORM_NAME "RobotomyRequestForm"
#define R_DEFAULT_FORM_TARGET "Someone's home"

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm(const std::string &name, const std::string &target);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm(){};

    std::string getTarget(void) const;
    void handleExecutoion(void) const;

private:
    const std::string _target;
};
