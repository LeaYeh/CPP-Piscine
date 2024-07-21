#include "JacobsthalGenerator.hpp"

JacobsthalGenerator::JacobsthalGenerator() : _n(3), _j0(1), _j1(1) {}

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
0 1 1 3 5 11 21
only need: 3 5 11 21 ...
*/
unsigned long JacobsthalGenerator::next(void)
{
    unsigned long j_next;

    j_next = this->_j1 + 2 * this->_j0;
    this->_j0 = this->_j1;
    this->_j1 = j_next;
    this->_n++;

    return (j_next);
}

void JacobsthalGenerator::reset(void)
{
    this->_n = 3;
    this->_j0 = 1;
    this->_j1 = 1;
}
