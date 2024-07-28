#include "RPN.hpp"

bool RPN::_isValidateInput(const std::string &input)
{
    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        if (!this->_isValidateToken(token))
            return (false);
    }
    return (true);
}

bool RPN::_isValidateInt(const std::string &token)
{
    std::istringstream iss(token);
    int value;
    char leftover;

    if (!(iss >> value) || iss.get(leftover))
    {
        std::cerr << "Error\n";
        return (false);
    }
    return (true);
}

bool RPN::_isValidateToken(const std::string &token)
{
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return (true);
    else if (!this->_isValidateInt(token))
        return (false);
    return (true);
}

bool RPN::_isValidateCalculation(const int a, const int b, const std::string &op, int &result)
{
    if (op == "/" && a == 0)
    {
        std::cerr << "Error: Division by zero is invalid" << std::endl;
        return (false);
    }
    if (op == "+")
    {
        result = b + a;
        if ((a > 0 && b > 0 && result < 0) || (a < 0 && b < 0 && result > 0))
        {
            std::cerr << "Error: Overflow detected" << std::endl;
            return (false);
        }
    }
    else if (op == "-")
    {
        result = b - a;
        if ((a > 0 && b < 0 && result > 0) || (a < 0 && b > 0 && result < 0))
        {
            std::cerr << "Error: Overflow detected" << std::endl;
            return (false);
        }
    }
    else if (op == "*")
    {
        result = b * a;
        if (a != 0 && result / a != b)
        {
            std::cerr << "Error: Overflow detected" << std::endl;
            return (false);
        }
    }
    else if (op == "/")
        result = b / a;
    return (true);
}

bool RPN::_isOperator(const std::string &token)
{
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return (true);
    return (false);
}

int RPN::_convertToInt(const std::string &token) const
{
    int value;

    std::istringstream converter(token);
    converter >> value;
    return (value);
}

bool RPN::_process(const std::string &input)
{
    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        if (this->_isOperator(token))
        {
            if (this->_stack.size() < 2)
            {
                std::cerr << "Error: Invalid input sequence cannot calculate." << std::endl;
                return (false);
            }
            int a = this->_stack.top();
            this->_stack.pop();
            int b = this->_stack.top();
            this->_stack.pop();
            int result;
            if (!this->_isValidateCalculation(a, b, token, result))
                return (false);
            this->_stack.push(result);
        }
        else
            this->_stack.push(this->_convertToInt(token));
    }
    return (true);
}

void RPN::calculate(const std::string &input)
{
    if (!this->_isValidateInput(input) || !this->_process(input))
        return;
    if (this->_stack.size() != 1)
    {
        std::cerr << "Error: Invalid input sequence cannot calculate." << std::endl;
        return;
    }
    std::cout << this->_stack.top() << std::endl;
}
