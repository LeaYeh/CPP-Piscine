#pragma once
#include <iostream>


#define UNDEFINE_NAME "no-name"
#define UNDEFINE_GRADE 150

/*
Notes: Exception in class
*/
class Bureaucrat
{
public:
    static const int HIGHEST_GRADE = 1;
    static const int LOWEST_GRADE = 150;
    Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat(std::string const &name, const int grade);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat() {};

    const std::string& getName(void) const;
    int getGrade(void) const;
    void incrementGrade(void);
    void decrementGrade(void);

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
    int _grade;
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& obj);
