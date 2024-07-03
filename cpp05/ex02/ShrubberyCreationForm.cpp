#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(S_DEFAULT_FORM_NAME, S_DEFAULT_FORM_TARGET, S_SIGN_GRADE, S_EXEC_GRADE) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name, const std::string &target) : AForm(name, target, S_SIGN_GRADE, S_EXEC_GRADE) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

void ShrubberyCreationForm::handleExecutoion(void) const
{
    std::ofstream file((this->_target + "_shrubbery").c_str());
    if (!file.is_open())
        throw(ShrubberyCreationForm::FileNotOpenException());
    file << "       #\n"
         << "      ###\n"
         << "     #####\n"
         << "    #######\n"
         << "   #########\n"
         << "  ###########\n"
         << " #############\n"
         << "###############\n"
         << "       H\n"
         << "       H\n"
         << "       H\n";
    file << "\n";
    file << "       #                                 \n"
         << "      ###                                \n"
         << "     #####            #                  \n"
         << "    #######          ###                 \n"
         << "   #########        #####                \n"
         << "  ###########     #########              \n"
         << " #############        H                  \n"
         << "###############       H         #        \n"
         << "       H                       ###       \n"
         << "       H                      #####      \n"
         << "       H                        H        \n";
    file.close();
}

const char *ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
    return ("File can not open <ShrubberyCreationForm>");
}
