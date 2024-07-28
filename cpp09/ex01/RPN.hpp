#pragma once
#include <iostream>
#include <sstream>
#include <stack>
#include <list>
#include <climits>

class RPN
{
public:
    RPN() {};
    ~RPN() {};

    void calculate(const std::string &input);

private:
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    std::stack<int, std::list<int> > _stack;
    int _convertToInt(const std::string &token) const;
    bool _process(const std::string &input);
    bool _isValidateInt(const std::string &token);
    bool _isValidateCalculation(const int a, const int b, const std::string &op, int &result);
    bool _isValidateInput(const std::string &input);
    bool _isValidateToken(const std::string &token);
    bool _isOperator(const std::string &token);
};
