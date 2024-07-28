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
PmergeMe<Container, true>::PmergeMe() {}

template <typename Container>
PmergeMe<Container, true>::PmergeMe(const std::string &input)
{
    if (!this->_parseInput(input))
        throw std::exception();
}

template <typename Container>
PmergeMe<Container, true>::PmergeMe(const PmergeMe &other) : _inputNumbers(other._inputNumbers) {}

template <typename Container>
PmergeMe<Container, true> &PmergeMe<Container, true>::operator=(const PmergeMe &other)
{
    if (this != &other)
        this->_inputNumbers = other._inputNumbers;
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
            std::cerr << "Invalid integer: " << token << std::endl;
            return (false);
        }
        else if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
        {
            std::cerr << "Invalid integer: " << token << std::endl;
            return (false);
        }
        else if (tmp < 0)
        {
            std::cerr << "Error" << std::endl;
            return (false);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Invalid integer: " << token << std::endl;
        std::cerr << e.what() << std::endl;
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
void PmergeMe<Container, true>::_printElements(const Container &container) const
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
bool PmergeMe<Container, true>::sort(void)
{
    if (this->_inputNumbers.empty())
        throw std::runtime_error("Can not sort with empty or invalid input.");
    else if (this->_inputNumbers.size() == 1)
        throw std::runtime_error("Only one element in the container, no need to sort.");

    this->_fjs.setNumbers(this->_inputNumbers);
    if (this->_isSorted(this->_inputNumbers))
    {
        std::cout << "Container is already sorted" << std::endl;
        std::cout << this->_getFormattedNumbers(this->_inputNumbers);
        return (false);
    }
    this->_fjs.sort();
    if (!this->_isSorted(this->_fjs.getSortedNumbers()))
    {
        std::cerr << "Failed to sort the container" << std::endl;
        Container sorted_numbers = this->_fjs.getSortedNumbers();

        for (typename Container::const_iterator it = sorted_numbers.begin(); it != sorted_numbers.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        return (false);
    }
    return (true);
}

template <typename Container>
void PmergeMe<Container, true>::printSortedResult(void) const
{
    std::cout << "Before:\t" << this->_getFormattedNumbers(this->_inputNumbers);
    std::cout << "After:\t" << this->_getFormattedNumbers(this->_fjs.getSortedNumbers());
}

template <typename Container>
void PmergeMe<Container, true>::printTaskInfo(void) const
{
    std::cout << this->_getFormattedTaskInfo(this->_fjs);
}

template <typename Container>
double PmergeMe<Container, true>::_roundToDecimalPlaces(double value, int places) const
{
    return (round(value * std::pow(10, places)) / std::pow(10, places));
}

template <typename Container>
std::string PmergeMe<Container, true>::_getFormattedTaskInfo(const FordJohnsonSort<Container> &fjs) const
{
    std::ostringstream oss;

    oss << std::right << "Time to process a range of " << std::setw(4) << fjs.getNumbers().size() << " elements ";
    oss << "with " << std::right << std::setw(16) << this->_getFormattedContainerType(Container()) << " : ";
    oss << std::right << std::setw(7) << this->_roundToDecimalPlaces(fjs.getTimeElapsed(), 5) << "us" << std::endl;
    oss << "Comparisons: " << fjs.getCompareCount() << std::endl;
    return (oss.str());
}

template <typename Container>
std::string PmergeMe<Container, true>::_getFormattedContainerType(const Container &container) const
{
    const std::type_info& typeInfo = typeid(container);

    if (typeInfo == typeid(std::vector<int>))
        return ("std::vector<int>");
    else if (typeInfo == typeid(std::deque<int>))
        return ("std::deque<int>");
    else
        return ("Unknown container type");
    // Because the stupid subject, I can't use std::free() so I can't use this code :(((
    // int status;
    // std::auto_ptr<char> demangled(abi::__cxa_demangle(typeInfo.name(), NULL, NULL, &status));
    // std::string containerType;

    // if (status == 0 && demangled.get())
    //     containerType = demangled.get();
    // else
    //     return ("Failed to demangle the type name.\n");
    // return (this->_simplifyContainerType(containerType));
}

template <typename Container>
std::string PmergeMe<Container, true>::_simplifyContainerType(const std::string &containerType) const
{
    std::string simplifiedType = containerType;
    std::size_t pos = containerType.find(", std::allocator");

    if (pos != std::string::npos)
        simplifiedType = containerType.substr(0, pos) + ">";
    return (simplifiedType);
}



template <typename Container>
std::string PmergeMe<Container, true>::_getFormattedNumbers(const Container &container) const
{
    std::ostringstream oss;
    typename Container::const_iterator it = container.begin();

    for (int i = 0; it != container.end(); i++)
    {
        if ((container.size() > 5 && i >= 4))
            break;
        oss << *it << " ";
        ++it;
    }
    if (it != container.end())
        oss << "[...]";
    oss << std::endl;
    return (oss.str());
}

template <typename Container>
bool PmergeMe<Container, true>::_isSorted(const Container &container) const
{
    typename Container::const_iterator it = container.begin();
    typename Container::const_iterator itNext = container.begin();

    if (it == container.end())
        return (true);
    while (itNext != container.end())
    {
        if (*it > *itNext)
            return (false);
        it = itNext;
        ++itNext;
    }
    return (true);
}
