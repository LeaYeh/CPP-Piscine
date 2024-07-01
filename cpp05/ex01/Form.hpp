#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

#define DEFAULT_FORM_NAME "no-name"
#define DEFAULT_SIGN_GRADE 150
#define DEFAULT_EXEC_GRADE 150

class Bureaucrat;

class Form
{
public:
    Form();
    Form(const Form &other);
    Form(std::string const &name, const int sign_grade, const int exec_grade);
    Form &operator=(const Form &other);
    ~Form(){};

    const std::string &getName(void) const;
    const std::string getSignStatus(void) const;
    int getSignGrade(void) const;
    int getExecGrade(void) const;
    void beSigned(Bureaucrat signer);

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
    const std::string _name;
    bool _is_signed;
    const int _sign_grade;
    const int _exec_grade;
};

std::ostream &operator<<(std::ostream &os, const Form &obj);
