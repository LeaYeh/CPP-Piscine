#include "AForm.hpp"

AForm::AForm() : _target(std::string(DEFAULT_FORM_TARGET)), _name(std::string(DEFAULT_FORM_NAME)), _is_signed(false), _sign_grade(DEFAULT_SIGN_GRADE), _exec_grade(DEFAULT_EXEC_GRADE) {}

AForm::AForm(const AForm &other) : _target(other._target), _name(other._name), _is_signed(other._is_signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade) {}

AForm::AForm(std::string const &name, std::string const &target, const int sign_grade, const int exec_grade) : _target(target), _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    if (sign_grade > Bureaucrat::LOWEST_GRADE)
        throw (AForm::GradeTooLowException());
    else if (sign_grade < Bureaucrat::HIGHEST_GRADE)
        throw (AForm::GradeTooHighException());
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->_is_signed = other._is_signed;
    return (*this);
}

const std::string &AForm::getName(void) const
{
    return (this->_name);
}

int AForm::getSignGrade(void) const
{
    return (this->_sign_grade);
}

int AForm::getExecGrade(void) const
{
    return (this->_exec_grade);
}

std::string AForm::getTarget(void) const
{
    return (this->_target);
}

const std::string AForm::getSignStatus(void) const
{
    if (this->_is_signed)
        return ("signed");
    return ("un-signed");
}

void AForm::beSigned(Bureaucrat signer)
{
    if (signer.getGrade() > this->_sign_grade)
        throw (AForm::GradeTooLowException());
    if (!this->_is_signed)
    {
        this->_is_signed = true;
        std::cout << signer.getName() << " signed " << this->getName() << std::endl;
    }
    else
        std::cout << signer.getName() << " tried to sign " << \
            this->getName() << " but it is already be signed." << std::endl;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getExecGrade() ||
        executor.getGrade() > this->getSignGrade())
        throw(AForm::GradeTooLowException());
    this->handleExecutoion();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
    os << "Form name: " << obj.getName() << std::endl;
    os << "Target: " << obj.getTarget() << std::endl;
    os << "Sign status: " << obj.getSignStatus() << std::endl;
    os << "Sign grade: " << obj.getSignGrade() << std::endl;
    os << "Execution grade: " << obj.getExecGrade() << std::endl;
    return (os);
}
