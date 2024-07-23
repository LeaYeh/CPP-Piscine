#include "checker.hpp"

const int DaysLookupTable[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

static int _getCurrentYear(void);
static bool _isLeapYear(int year);

bool isValidDate(const std::string &dateString)
{
    if (dateString.length() != 10)
        return (false);
    if (dateString[4] != '-' || dateString[7] != '-')
        return (false);
    if (!isValidYear(dateString.substr(0, 4)))
        return (false);
    if (!isValidMonth(dateString.substr(5, 2)))
        return (false);
    if (!isValidDay(dateString.substr(5, 2),
            dateString.substr(8, 2)))
        return (false);
    return (true);
}

bool isValidYear(const std::string &yearString)
{
    if (yearString.length() != 4)
        return (false);
    for (size_t i = 0; i < yearString.length(); i++)
    {
        if (!isdigit(yearString[i]))
            return (false);
    }
    std::istringstream iss(yearString);
    int year;

    iss >> year;
    int currentYear = _getCurrentYear();
    if (year < 1900 || year > currentYear)
        return (false);
    return (true);
}

bool isValidMonth(const std::string &monthString)
{
    if (monthString.length() != 2)
        return (false);
    for (size_t i = 0; i < monthString.length(); i++)
    {
        if (!isdigit(monthString[i]))
            return (false);
    }
    std::istringstream iss(monthString);
    int month;

    iss >> month;
    if (month < 1 || month > 12)
        return (false);
    return (true);
}

#include <iostream>
bool isValidDay(const std::string &monthString, const std::string &dayString)
{
    if (dayString.length() != 2)
        return (false);
    for (size_t i = 0; i < dayString.length(); i++)
    {
        if (!isdigit(dayString[i]))
            return (false);
    }
    std::istringstream iss(dayString);
    int day;

    iss >> day;
    int month;
    iss.clear();
    iss.str(monthString);
    iss >> month;
    if (day < 1 || day > DaysLookupTable[month])
    {
        if (month == 2 && day == 29 && _isLeapYear(_getCurrentYear()))
            return (true);
        std::cout << "DaysLookupTable[month]: " << DaysLookupTable[month] << std::endl;
        std::cout << "month: " << month << std::endl;
        std::cout << "day: " << day << std::endl;
        return (false);
    }
    return (true);
}

bool isValidFloat(const std::string &floatString)
{
    size_t i = 0;

    if (floatString[i] == '-' || floatString[i] == '+')
        i++;
    for (; i < floatString.length(); i++)
    {
        if (!isdigit(floatString[i]) && floatString[i] != '.')
            return (false);
    }
    size_t pos = floatString.find_first_of(".");
    if (pos == std::string::npos)
        return (true);
    if (pos == 0 || pos == floatString.length() - 1)
        return (false);
    return (true);
}

static int _getCurrentYear(void)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;

    return currentYear;
}

static bool _isLeapYear(int year)
{
    if (year % 4 != 0)
        return (false);
    if (year % 100 != 0)
        return (true);
    if (year % 400 != 0)
        return (false);
    return (true);
}
