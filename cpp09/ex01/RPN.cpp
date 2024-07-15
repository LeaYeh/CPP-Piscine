#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    (void)other;
}

RPN &RPN::operator=(const RPN &other)
{
    (void)other;
    return *this;
}

RPN::~RPN()
{
    this->_emptyStack();
}

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
    try
    {
        std::size_t pos;
        std::stoi(token, &pos);
        if (pos != token.size())
        {
            std::cout << "Invalid integer" << std::endl;
            return (false);
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
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

bool RPN::_isValidateCalculation(const int &a, const std::string &op)
{
    if (op == "/" && a == 0)
    {
        std::cout << "Division by zero is invalid" << std::endl;
        this->_emptyStack();
        return (false);
    }
    return (true);
}

bool RPN::_isOperator(const std::string &token)
{
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return (true);
    return (false);
}

void RPN::_emptyStack(void)
{
    while (!this->_stack.empty())
        this->_stack.pop();
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
                std::cout << "Invalid input sequence cannot calculate." << std::endl;
                this->_emptyStack();
                return (false);
            }
            int a = this->_stack.top();
            this->_stack.pop();
            int b = this->_stack.top();
            this->_stack.pop();
            if (!this->_isValidateCalculation(a, token))
                return (false);
            if (token == "+")
                this->_stack.push(b + a);
            else if (token == "-")
                this->_stack.push(b - a);
            else if (token == "*")
                this->_stack.push(b * a);
            else if (token == "/")
                this->_stack.push(b / a);
        }
        else
            this->_stack.push(std::stoi(token));
    }
    return (true);
}

void RPN::calculate(const std::string &input)
{
    if (!this->_isValidateInput(input) || !this->_process(input))
        return;
    if (this->_stack.size() != 1)
    {
        std::cout << "Invalid input sequence cannot calculate." << std::endl;
        this->_emptyStack();
        return;
    }
    std::cout << this->_stack.top() << std::endl;
}