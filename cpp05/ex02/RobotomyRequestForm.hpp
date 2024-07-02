#pragma once
#include "AForm.hpp"

#define R_SIGN_GRADE 72
#define R_EXEC_GRADE 45
#define R_DEFAULT_FORM_NAME "RobotomyRequestForm"

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm(const std::string &name, const std::string &target);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm(){};

    void handleExecutoion(void) const;

protected:
private:
    const std::string _target;
};
