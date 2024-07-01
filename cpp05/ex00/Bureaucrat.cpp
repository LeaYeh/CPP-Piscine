#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name(std::string(UNDEFINE_NAME)), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat::Bureaucrat(std::string const &name, const int grade): _name(name), _grade(grade)
{
    if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
    else if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->_grade = other._grade;
    return (*this);
}

const std::string& Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
    if (this->_grade - 1 < HIGHEST_GRADE)
        throw GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if (this->_grade + 1 > LOWEST_GRADE)
        throw GradeTooLowException();
    this->_grade++;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return (os);
}
