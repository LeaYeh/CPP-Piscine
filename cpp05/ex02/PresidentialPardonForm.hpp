#pragma once
#include "AForm.hpp"

#define P_SIGN_GRADE 25
#define P_EXEC_GRADE 5
#define P_DEFAULT_FORM_NAME "PresidentialPardonForm"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm(const std::string &name, const std::string &target);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm(){};

    void handleExecutoion(void) const;

protected:
private:
    const std::string _target;
};
