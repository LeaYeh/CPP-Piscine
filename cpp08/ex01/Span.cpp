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
    std::vector< std::pair<int, int> > indexed_arr;
    int min_span = std::numeric_limits<int>::max();

    if (this->_size < 2)
        throw(std::runtime_error("No span can be found."));
    for (unsigned int i = 0; i < this->_size; i++)
        indexed_arr.push_back(std::make_pair(this->_data[i], i));
    std::sort(indexed_arr.begin(), indexed_arr.end());
    for (unsigned int i = 1; i < this->_size; i++)
    {
        int span = std::abs(indexed_arr[i].first - indexed_arr[i - 1].first);
        if (span < min_span)
            min_span = span;
    }
    return (min_span);
}

int Span::longestSpan(void)
{
    int min_elm;
    int max_elm;

    if (this->_size < 2)
        throw(std::runtime_error("No span can be found."));
    min_elm = *std::min_element(this->_data, this->_data + this->_size);
    max_elm = *std::max_element(this->_data, this->_data + this->_size);
    return (max_elm - min_elm);
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
