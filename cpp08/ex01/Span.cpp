#include "Span.hpp"

Span::Span(unsigned int N) : _capacity(N), _size(0)
{
    if (N < 1)
        throw(std::length_error("Capacity at least need to be 1."));
    this->_data = new int[N];
}

Span::~Span()
{
    if (this->_data != NULL)
        delete[] this->_data;
}

Span::Span(const Span &other) : _capacity(other.capacity())
{
    if (this != &other)
    {
        this->_data = new int[other.capacity()];
        this->_deepCopy(other);
    }
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
        this->_deepCopy(other);
    return (*this);
}

int &Span::operator[](const unsigned int index)
{
    if (index >= this->_size)
        throw(std::range_error("accessment out of boundary."));
    return (this->_data[index]);
}

const int &Span::operator[](const unsigned int index) const
{
    if (index >= this->_size)
        throw(std::range_error("accessment out of boundary."));
    return (this->_data[index]);
}

unsigned int Span::size(void) const
{
    return (this->_size);
}

unsigned int Span::capacity(void) const
{
    return (this->_capacity);
}

void Span::addNumber(const int &num)
{
    if (this->_size == this->_capacity)
        throw(std::length_error("Not enough capacity."));
    this->_data[this->_size++] = num;
}

int Span::shortestSpan(void)
{
    int dist = std::numeric_limits<int>::max();
    int tmp_dist;

    if (this->_size < 2)
        throw(std::runtime_error("No span can be found."));
    for (unsigned int i = 0; i < this->_size - 1; i++)
    {
        for (unsigned int j = i + 1; j < this->_size; j++)
        {
            tmp_dist = std::abs(this->_data[i] - this->_data[j]);
            if (dist > tmp_dist)
                dist = tmp_dist;
        }
    }
    return (dist);
}

int Span::longestSpan(void)
{
    int dist = std::numeric_limits<int>::min();
    int tmp_dist;

    if (this->_size < 2)
        throw(std::runtime_error("No span can be found."));
    for (unsigned int i = 0; i < this->_size - 1; i++)
    {
        for (unsigned int j = i + 1; j < this->_size; j++)
        {
            tmp_dist = std::abs(this->_data[i] - this->_data[j]);
            if (dist < tmp_dist)
                dist = tmp_dist;
        }
    }
    return (dist);
}

void Span::_deepCopy(const Span &other)
{
    if (this->_capacity < other.capacity())
        throw(std::length_error("The lvalue does not have enough capacity."));
    this->_size = other.size();
    for (unsigned int i = 0; i < this->_size; i++)
        this->_data[i] = other[i];
}

std::ostream &operator<<(std::ostream &os, const Span &obj)
{
    std::cout << "Capacity: " << obj.capacity() << std::endl;
    for (unsigned int i = 0; i < obj.size(); i++)
        std::cout << obj[i] << " ";
    std::cout << std::endl;

    return (os);
}
