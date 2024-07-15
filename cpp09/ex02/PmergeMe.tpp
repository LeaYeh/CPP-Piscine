#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container, false>::PmergeMe()
{
    std::cerr << "Unsupported container type" << std::endl;
}

template <typename Container>
PmergeMe<Container, false>::PmergeMe(const std::string &input)
{
    (void)input;
    std::cerr << "Unsupported container type" << std::endl;
}

template <typename Container>
PmergeMe<Container, true>::PmergeMe() : _compare_cnt(0), _swap_cnt(0) {}

template <typename Container>
PmergeMe<Container, true>::PmergeMe(const std::string &input) : _compare_cnt(0), _swap_cnt(0)
{
    if (!this->_parseInput(input))
        return ;
    this->printElements(this->_inputNumbers);
}

template <typename Container>
PmergeMe<Container, true>::PmergeMe(const PmergeMe &other) : _inputNumbers(other._inputNumbers), _compare_cnt(other._compare_cnt), _swap_cnt(other._swap_cnt) {}

template <typename Container>
PmergeMe<Container, true> &PmergeMe<Container, true>::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->_inputNumbers = other._inputNumbers;
        this->_compare_cnt = other._compare_cnt;
        this->_swap_cnt = other._swap_cnt;
    }
    return (*this);
}

template <typename Container>
PmergeMe<Container, true>::~PmergeMe() {}


template <typename Container>
bool PmergeMe<Container, true>::_isValidateInt(const std::string &token)
{
    try
    {
        long int tmp;
        char *end;

        tmp = std::strtol(token.c_str(), &end, 10);
        if (*end != '\0')
        {
            std::cout << "Invalid integer: " << token << std::endl;
            return (false);
        }
        else if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
        {
            std::cout << "Invalid integer: " << token << std::endl;
            return (false);
        }
    }
    catch(const std::exception& e)
    {
        std::cout << "Invalid integer: " << token << std::endl;
        std::cout << e.what() << std::endl;
        return (false);
    }
    return (true);
}

template <typename Container>
bool PmergeMe<Container, true>::_parseInput(const std::string &input)
{
    std::istringstream iss(input);
    std::string token;
    int tmp;

    while (iss >> token)
    {
        if (!this->_isValidateInt(token))
            return (false);
        tmp = static_cast<int>(std::strtol(token.c_str(), NULL, 10));
        this->_inputNumbers.push_back(tmp);
    }
    return (true);
}

template <typename Container>
void PmergeMe<Container, true>::printElements(const Container &container) const
{
    typename Container::const_iterator it = container.begin();

    if (it == container.end())
    {
        std::cout << "Container is empty" << std::endl;
        return ;
    }
    while (it != container.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

template <typename Container>
void PmergeMe<Container, true>::sort(void)
{
}
