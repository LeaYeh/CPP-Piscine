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
    {
        this->_grade = other._grade;
        this->_name = other._name;
    }
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

void Bureaucrat::signForm(AForm *form)
{
    try
    {
        form->beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << this->_name << " couldn’t sign " << form->getName() << " because ";
        std::cout << e.what() << ".\n";
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << this->_name << " couldn’t execute " << form.getName() << " because ";
        std::cout << e.what() << ".\n";
    }
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
