#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(P_DEFAULT_FORM_NAME, P_DEFAULT_FORM_TARGET, P_SIGN_GRADE, P_EXEC_GRADE) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name, const std::string &target) : AForm(name, target, P_SIGN_GRADE, P_EXEC_GRADE) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

void PresidentialPardonForm::handleExecutoion(void) const
{
    std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
