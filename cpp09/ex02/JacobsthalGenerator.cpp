#include "JacobsthalGenerator.hpp"

JacobsthalGenerator::JacobsthalGenerator() : _n(0), _j0(0), _j1(1) {}

JacobsthalGenerator::JacobsthalGenerator(const JacobsthalGenerator &other) : _n(other._n), _j0(other._j0), _j1(other._j1) {}

JacobsthalGenerator &JacobsthalGenerator::operator=(const JacobsthalGenerator &other)
{
    if (this != &other)
    {
        this->_n = other._n;
        this->_j0 = other._j0;
        this->_j1 = other._j1;
    }
    return (*this);
}

JacobsthalGenerator::~JacobsthalGenerator() {}

/*
J(0) = 0
J(1) = 1
J(n) = J(n - 1) + 2 * J(n - 2)
*/
int JacobsthalGenerator::next(void)
{
    int j_next;

    if (this->_n == 0)
        j_next = this->_j0;
    else if (this->_n == 1)
        j_next = this->_j1;
    else
    {
        j_next = this->_j1 + 2 * this->_j0;
        this->_j0 = this->_j1;
        this->_j1 = j_next;
    }
    this->_n++;

    return (j_next);
}

void JacobsthalGenerator::reset(void)
{
    this->_n = 0;
    this->_j0 = 0;
    this->_j1 = 1;
}
