#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _data(NULL)
{
    std::cout << "Array default constructor be called.\n";
}

template <typename T>
Array<T>::Array(const unsigned int &n)
{
    std::cout << "Array(n) constructor be called.\n";
    this->_size = n;
    this->_data = new T[n];
    // the T() is a temp value of type T, which will be consider as a const varible during the compiler time.
    // so if the T is an object, the copy operator's parameter should be a const reference.
    for (unsigned int i = 0; i < this->_size; i++)
        this->_data[i] = T();
}

template <typename T>
Array<T>::Array(const Array &other)
{
    std::cout << "Array copy constructor be called.\n";
    this->_deepCopy(other);
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    std::cout << "Array copy operator be called.\n";
    if (this != &other)
        this->_deepCopy(other);
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    std::cout << "Array deconstructor be called.\n";
    delete[] _data;
}

template <typename T>
T &Array<T>::operator[](const unsigned int index)
{
    if (index >= this->size())
        throw (std::range_error("accessment out of boundary."));
    return (this->_data[index]);
}

template <typename T>
const T &Array<T>::operator[](const unsigned int index) const
{
    if (index >= this->size())
        throw (std::range_error("accessment out of boundary."));
    return (this->_data[index]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return (this->_size);
}

template <typename T>
void Array<T>::printElements(void) const
{
    for (unsigned int i = 0; i < this->size(); i++)
        std::cout << (*this)[i] << " ";
    std::cout << std::endl;
}

template <typename T>
void Array<T>::_deepCopy(const Array &other)
{
    this->_size = other.size();
    if (this->_data)
        delete[] this->_data;
    this->_data = new T[this->_size];
    for (unsigned int i = 0; i < this->_size; i++)
        this->_data[i] = other[i];
}
