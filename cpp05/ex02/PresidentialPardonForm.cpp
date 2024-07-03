#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(P_DEFAULT_FORM_NAME, P_SIGN_GRADE, P_EXEC_GRADE), _target(std::string(DEFAULT_FORM_TARGET)) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name, const std::string &target) : AForm(name, P_SIGN_GRADE, P_EXEC_GRADE), _target(target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

void PresidentialPardonForm::handleExecutoion(void) const
{
    std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
