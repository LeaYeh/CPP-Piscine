#pragma once
#include <fstream>
#include "AForm.hpp"

#define S_SIGN_GRADE 145
#define S_EXEC_GRADE 137
#define S_DEFAULT_FORM_NAME "ShrubberyCreationForm"
#define S_DEFAULT_FORM_TARGET "Someone's home"

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm(const std::string &name, const std::string &target);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm(){};

    void handleExecutoion(void) const;

    class FileNotOpenException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};
