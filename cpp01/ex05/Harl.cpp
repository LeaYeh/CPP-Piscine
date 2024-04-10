#include "Harl.hpp"


Harl::Harl(void) {};

Harl::~Harl(void) {};

Harl::Level Harl::_mapStringToLevel(const std::string &level)
{
    if (level == "debug") return DEBUG;
    else if (level == "info") return INFO;
    else if (level == "warning") return WARNING;
    else if (level == "error") return ERROR;
    else return UNKNOWN;
}

void Harl::debug(void)
{
    std::cout << std::setw(_PREFIX_LENGTH) << std::left << "[ DEBUG ]";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << std::setw(_PREFIX_LENGTH) << std::left << "[ INFO ]";
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << std::setw(_PREFIX_LENGTH) << std::left << "[ WARNING ]";
    std::cout << "I think I’ve lost my appetite. I’m going to cancel my order." << std::endl;
}

void Harl::error(void)
{
    std::cout << std::setw(_PREFIX_LENGTH) << std::left << "[ ERROR ]";
    std::cout << "Sorry, I can’t take your order. The kitchen is closed." << std::endl;
}

void Harl::complain(std::string const &level)
{
    switch (this->_mapStringToLevel(level))
    {
        case DEBUG:
            debug();
            break;
        case INFO:
            info();
            break;
        case WARNING:
            warning();
            break;
        case ERROR:
            error();
            break;
        default:
            std::cout << "Unknown level" << std::endl;
            break;
    }
}
