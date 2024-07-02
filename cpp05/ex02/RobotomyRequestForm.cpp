#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(R_DEFAULT_FORM_NAME, R_SIGN_GRADE, R_EXEC_GRADE), _target(std::string("default")) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name, const std::string &target) : AForm(name, R_SIGN_GRADE, R_EXEC_GRADE), _target(target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

void RobotomyRequestForm::handleExecutoion(void) const
{
    std::cout << "Drilling noises...";
    if (std::rand() % 2)
        std::cout << this->_target << " has been robotomized.\n";
    else
        std::cout << this->_target << " robotomization failed.\n";
}
