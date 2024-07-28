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

    int year;
    int month;

    std::istringstream iss(dateString.substr(0, 4));
    iss >> year;
    iss.clear();
    iss.str(dateString.substr(5, 2));
    iss >> month;
    if (!isValidDay(year, month, dateString.substr(8, 2)))
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

bool isValidDay(const int year, const int month, const std::string &dayString)
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
    if (day < 1 || day > DaysLookupTable[month])
    {
        if (month == 2 && day == 29 && _isLeapYear(year))
            return (true);
        return (false);
    }
    return (true);
}

bool isValidFloat(const std::string &floatString)
{
    size_t i = 0;

    if (floatString.empty())
        return (false);
    if (floatString[i] == '-' || floatString[i] == '+')
        i++;
    for (; i < floatString.length(); i++)
    {
        if (!isdigit(floatString[i]) && floatString[i] != '.')
            return (false);
    }
    size_t pos = floatString.find_first_of(".");
    size_t pos2 = floatString.find_first_of(".", pos + 1);
    if (pos == std::string::npos)
        return (true);
    if (pos == floatString.length() - 1 || pos2 != std::string::npos)
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
