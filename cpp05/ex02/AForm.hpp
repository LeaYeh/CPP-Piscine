#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

#define DEFAULT_FORM_NAME "no-name"
#define DEFAULT_FORM_TARGET "random-target"
#define DEFAULT_SIGN_GRADE 150
#define DEFAULT_EXEC_GRADE 150

class Bureaucrat;

class AForm
{
public:
    AForm();
    AForm(const AForm &other);
    // AForm(std::string const &name, std::string const &target);
    AForm(std::string const &name, std::string const &target, const int sign_grade, const int exec_grade);
    AForm &operator=(const AForm &other);
    virtual ~AForm(){};

    void beSigned(Bureaucrat signer);
    const std::string &getName(void) const;
    const std::string getSignStatus(void) const;
    int getSignGrade(void) const;
    int getExecGrade(void) const;
    void execute(Bureaucrat const &executor) const;
    virtual std::string getTarget(void) const;
    virtual void handleExecutoion(void) const = 0;

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
    const std::string _target;

private:
    const std::string _name;
    bool _is_signed;
    const int _sign_grade;
    const int _exec_grade;
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);
