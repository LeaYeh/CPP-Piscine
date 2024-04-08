#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <iostream>
#include <string>
#include <iomanip>

class Harl
{
public:
    Harl(void);
    ~Harl(void);
    enum Level
    {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        UNKNOWN
    };
    void complain(std::string const &level);

private:
    static const int _PREFIX_LENGTH = 15;

    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    Harl::Level _mapStringToLevel(const std::string &level);
};

#endif