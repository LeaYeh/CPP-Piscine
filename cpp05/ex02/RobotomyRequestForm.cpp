#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(R_DEFAULT_FORM_NAME, R_DEFAULT_FORM_TARGET, R_SIGN_GRADE, R_EXEC_GRADE) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name, const std::string &target) : AForm(name, target, R_SIGN_GRADE, R_EXEC_GRADE) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
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
