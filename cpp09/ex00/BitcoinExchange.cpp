#include "BitcoinExchange.hpp"
#include "checker.hpp"


const std::string BitcoinExchange::DATABASE_FILE = "data.csv";

BitcoinExchange::BitcoinExchange() : _filePath("")
{
    this->_database.update(DATABASE_FILE);
}

BitcoinExchange::BitcoinExchange(const std::string &filePath) : _filePath(filePath)
{
    this->_database.update(DATABASE_FILE);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _filePath(other.getFilePath()) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _filePath = other.getFilePath();
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::getFilePath(void) const
{
    return (this->_filePath);
}

void BitcoinExchange::setFilePath(const std::string &filePath)
{
    this->_filePath = filePath;
}

void BitcoinExchange::run()
{
    std::ifstream file(this->_filePath.c_str());
    std::string line;
    std::string reason;
    std::string dateString;
    double value;

    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.\n");
    for (int i = 0; std::getline(file, line); i++)
    {
        if (i == 0 || line.empty())
            continue;
        if (!this->_parseInputLine(line, reason, dateString, value))
            std::cout << reason << std::endl;
        else
            this->_calculate(dateString, value);
    }
}

void BitcoinExchange::_calculate(const std::string &dateString, double value)
{
    double exchange = this->_database.getExchangeRate(dateString);
    double bitcoin = value * exchange;

    std::cout << dateString << " => " << value << " = " << bitcoin << std::endl;
}

bool BitcoinExchange::_parseInputLine(
    const std::string &line,
    std::string &reason,
    std::string &dateString,
    double &value)
{
    size_t pos = line.find_first_of(" | ");
    std::string valueString = line.substr(pos + 3);
    std::map<std::string, double> log;

    dateString = line.substr(0, pos);
    reason = "";
    if (pos == std::string::npos || valueString.empty() || dateString.empty())
        reason = "Error: bad input => " + line;
    else if (!isValidDate(dateString))
        reason = "Error: bad input => " + dateString;
    else if (!isValidFloat(valueString))
        reason = "Error: bad input => " + valueString;
    if (reason.empty())
    {
        std::istringstream iss(valueString);
        iss >> value;
        if (value < 0)
            reason = "Error: not a positive number.";
        else if (value > 1000)
            reason = "Error: too large a number.";
    }
    return (reason.empty());
}
