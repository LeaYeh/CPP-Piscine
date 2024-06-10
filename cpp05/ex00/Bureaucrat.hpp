#pragma once
#include <iostream>

/*
Notes: Exception in class
*/
class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat(std::string const &type);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat() {};

    const std::string& getName(void) const;
    const int getGrade(void) const;

    class GradeTooHighException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };

protected:
private:
    const std::string& _name;
    int _grade;
};