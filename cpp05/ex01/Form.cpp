#include "Form.hpp"

Form::Form() : _name(std::string(DEFAULT_FORM_NAME)), _is_signed(false), _sign_grade(DEFAULT_SIGN_GRADE), _exec_grade(DEFAULT_EXEC_GRADE) {}

Form::Form(const Form &other) : _name(other._name), _is_signed(other._is_signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade) {}

Form::Form(std::string const &name, const int sign_grade, const int exec_grade) : _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    if (sign_grade > Bureaucrat::LOWEST_GRADE)
        throw (Form::GradeTooLowException());
    else if (sign_grade < Bureaucrat::HIGHEST_GRADE)
        throw (Form::GradeTooHighException());
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_is_signed = other._is_signed;
        this->_sign_grade = other._sign_grade;
        this->_exec_grade = other._exec_grade;
    }
    return (*this);
}

const std::string &Form::getName(void) const
{
    return (this->_name);
}

int Form::getSignGrade(void) const
{
    return (this->_sign_grade);
}

int Form::getExecGrade(void) const
{
    return (this->_exec_grade);
}

const std::string Form::getSignStatus(void) const
{
    if (this->_is_signed)
        return ("signed");
    return ("un-signed");
}

void Form::beSigned(Bureaucrat signer)
{
    if (signer.getGrade() > this->_sign_grade || signer.getGrade() > this->_exec_grade)
        throw (Form::GradeTooLowException());
    if (!this->_is_signed)
    {
        this->_is_signed = true;
        std::cout << signer.getName() << " signed " << this->getName() << std::endl;
    }
    else
        std::cout << signer.getName() << " tried to sign " << \
            this->getName() << " but it is already be signed." << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
    os << "[Form]\n";
    os << "\tName: " << obj.getName() << std::endl;
    os << "\tSigned status: " << obj.getSignStatus() << std::endl;
    os << "\tSigned required grade: " << obj.getSignGrade() << std::endl;
    os << "\tExecuted required grade: " << obj.getExecGrade() << std::endl;
    return (os);
}
