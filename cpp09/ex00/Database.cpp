#include "Database.hpp"
#include "checker.hpp"

Database::Database() : _filePath(""), _records(std::map<std::string, double>()) {}

Database::Database(const std::string &filePath) : _filePath(filePath), _records(std::map<std::string, double>())
{
    this->update(filePath);
}

Database::Database(const Database &other) : _filePath(other.getFilePath()), _records(other.getRecords()) {}

Database &Database::operator=(const Database &other)
{
    if (this != &other)
    {
        this->_filePath = other.getFilePath();
        this->_records = other.getRecords();
    }
    return (*this);
}

Database::~Database()
{
    this->_records.clear();
}

void Database::update(const std::string &filePath)
{
    if (!this->_parseInputFile(filePath) || this->_records.empty())
        throw std::exception();
}

double Database::getExchangeRate(const std::string &dateString) const
{
    double exchange = this->_records.begin()->second;

    for (std::map<std::string, double>::const_iterator it = this->_records.begin(); it != this->_records.end(); it++)
    {
        if (it->first > dateString)
            return (exchange);
        exchange = it->second;
    }
    return (exchange);
}

std::string &Database::getFilePath(void) const
{
    return (const_cast<std::string &>(this->_filePath));
}

std::map<std::string, double> &Database::getRecords(void) const
{
    return (const_cast<std::map<std::string, double> &>(this->_records));
}

bool Database::_parseInputFile(const std::string &filePath)
{
    std::ifstream file(filePath.c_str());
    std::string line;

    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.\n");
    for (int i = 0; std::getline(file, line); i++)
    {
        if (i == 0 || line.empty())
            continue;
        if (!this->_parseInputLine(line))
        {
            file.close();
            throw std::runtime_error("Error: invalid input: " + line + "\n");
        }
    }
    file.close();
    return (true);
}

bool Database::_parseInputLine(const std::string &line)
{
    size_t pos = line.find_first_of(",");

    if (pos == std::string::npos)
        return (false);

    std::string dateString = line.substr(0, pos);
    std::string exchangeString = line.substr(pos + 1);
    double exchange;

    if (!isValidDate(dateString) || !isValidFloat(exchangeString))
        return (false);
    std::istringstream iss(exchangeString);

    iss >> exchange;
    if (exchange < 0)
        return (false);
    this->_records[dateString] = exchange;
    return (true);
}
