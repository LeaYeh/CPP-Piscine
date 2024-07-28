#pragma once
#include <string>
#include <ctime>
#include <sstream>


bool isValidDate(const std::string &dateString);
bool isValidYear(const std::string &yearString);
bool isValidMonth(const std::string &monthString);
bool isValidDay(const int year, const int month, const std::string &dayString);

bool isValidFloat(const std::string &floatString);


