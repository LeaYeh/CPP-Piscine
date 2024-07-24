#pragma once
#include <iostream>
#include <sstream>
#include <stack>
#include <list>

class RPN
{
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    void calculate(const std::string &input);

private:
    std::stack<int, std::list<int> > _stack;
    int _convertToInt(const std::string &token) const;
    bool _process(const std::string &input);
    bool _isValidateInt(const std::string &token);
    bool _isValidateCalculation(const int &a, const std::string &op);
    bool _isValidateInput(const std::string &input);
    bool _isValidateToken(const std::string &token);
    bool _isOperator(const std::string &token);
    void _emptyStack(void);
};
