#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(R_DEFAULT_FORM_NAME, R_SIGN_GRADE, R_EXEC_GRADE), _target(std::string(DEFAULT_FORM_TARGET)) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name, const std::string &target) : AForm(name, R_SIGN_GRADE, R_EXEC_GRADE), _target(target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

void RobotomyRequestForm::handleExecutoion(void) const
{
    std::srand(std::time(0));
    std::cout << "Drilling noises...";
    if (std::rand() % 2)
        std::cout << this->_target << " has been robotomized.\n";
    else
        std::cout << this->_target << " robotomization failed.\n";
}
