#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <map>
#include <fstream>
#include "Database.hpp"

class BitcoinExchange
{
public:
    static const std::string DATABASE_FILE;
    BitcoinExchange();
    BitcoinExchange(const std::string &filePath);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    std::string getFilePath(void) const;
    void setFilePath(const std::string &filePath);
    void run(void);

protected:
private:
    std::string _filePath;
    Database _database;
    void _calculate(const std::string &dateString, double value);
    bool _parseInputLine(const std::string &line, std::string &reason, std::string &dateString, double &value);
};
