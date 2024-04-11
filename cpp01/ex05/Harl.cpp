#include "Harl.hpp"


Harl::Harl(void) {};

Harl::~Harl(void) {};

Harl::Level Harl::_mapStringToLevel(const std::string &level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
            return static_cast<Level>(i);
    }
    return UNKNOWN;
}

void Harl::debug(void)
{
    std::cout << std::setw(_PREFIX_LENGTH) << std::left << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
    std::cout << std::endl;
}

void Harl::info(void)
{
    std::cout << std::setw(_PREFIX_LENGTH) << std::left << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money." << std::endl;
    std::cout << "You don’t put enough! If you did I would not have to ask for it!" << std::endl;
    std::cout << std::endl;
}

void Harl::warning(void)
{
    std::cout << std::setw(_PREFIX_LENGTH) << std::left << "[ WARNING ]" << std::endl;
    std::cout << "I think I’ve lost my appetite." << std::endl;
    std::cout << "I’m going to cancel my order." << std::endl;
    std::cout << std::endl;
}

void Harl::error(void)
{
    std::cout << std::setw(_PREFIX_LENGTH) << std::left << "[ ERROR ]" << std::endl;;
    std::cout << "Sorry, I can’t take your order." << std::endl;
    std::cout << "The kitchen is closed." << std::endl;
    std::cout << std::endl;
}

void Harl::complain(std::string const &level)
{
    void (Harl::*complaints[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    Level lvl = _mapStringToLevel(level);

    for (int i = 0; i < 4; i++)
    {
        if (lvl == i)
        {
            (this->*complaints[i])();
            return;
        }
    }
}
