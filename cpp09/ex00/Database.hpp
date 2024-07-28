#pragma once

#include <fstream>  // Include for file I/O
#include <iostream> // Include for standard I/O
#include <string>   // Include for std::string
#include <sstream>
#include <algorithm>
#include <map>


class Database
{
public:
    Database();
    Database(const std::string &filePath);
    Database(const Database &other);
    Database &operator=(const Database &other);
    ~Database();

    void update(const std::string &filePath);
    double getExchangeRate(const std::string &dateString) const;
    const std::string &getFilePath(void) const;
    const std::map<std::string, double> &getRecords(void) const;

protected:
private:
    std::string _filePath;
    std::map<std::string, double> _records;
    bool _parseInputFile(const std::string &filePath);
    bool _parseInputLine(const std::string &line);
};
