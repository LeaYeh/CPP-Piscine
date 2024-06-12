#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

#define DEFAULT_FORM_NAME "no-name"
#define DEFAULT_SIGN_GRADE 150
#define DEFAULT_EXEC_GRADE 150

class Bureaucrat;

class AForm
{
public:
    AForm();
    AForm(const AForm &other);
    AForm(std::string const &name, const int sign_grade, const int exec_grade);
    AForm &operator=(const AForm &other);
    ~AForm(){};

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
    std::string _name;
    bool _is_signed;
    int _sign_grade;
    int _exec_grade;
};

std::ostream &operator<<(std::ostream &os, const Form &obj);
