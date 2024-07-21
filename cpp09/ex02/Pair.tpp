template <typename T>
Pair<T>::Pair() : _first(T()), _second(T()), _single(T()), _elementSize(0) {}

template <typename T>
Pair<T>::Pair(T first, T second) : _first(first), _second(second)
{
    if (first.size() != second.size())
        throw std::invalid_argument("Pair: first and second must have the same size");
    this->_elementSize = first.size();
    this->_updateSingle();
}

template <typename T>
Pair<T>::Pair(T silo) : _first(silo), _second(T()), _elementSize(1)
{
    this->_updateSingle();
}

template <typename T>
Pair<T>::Pair(const Pair &other) : _first(other._first), _second(other._second), _single(other._single), _elementSize(other._elementSize) {}

template <typename T>
Pair<T> &Pair<T>::operator=(const Pair &other)
{
    if (this != &other)
    {
        this->_first = other.first();
        this->_second = other.second();
        this->_single = other.single();
        this->_elementSize = other.getElementSize();
    }
    return (*this);
}

template <typename T>
Pair<T>::~Pair(void) {}

template <typename T>
const T& Pair<T>::first() const
{
    return (this->_first);
}

template <typename T>
const T& Pair<T>::second() const
{
    return (this->_second);
}

template <typename T>
const T& Pair<T>::single() const
{
    return (this->_single);
}

template <typename T>
void Pair<T>::swap()
{
    T tmp = this->_first;
    this->_first = this->_second;
    this->_second = tmp;
    this->_updateSingle();
}

template <typename T>
const typename T::value_type &Pair<T>::getUpperBound() const
{
    if (this->_second.empty())
        return (this->_first.back());
    return (this->_second.back());
}

template <typename T>
const typename T::value_type &Pair<T>::getLowerBound() const
{
    return (this->_first.back());
}

template <typename T>
int Pair<T>::getElementSize() const
{
    return (this->_elementSize);
}

template <typename T>
void Pair<T>::printPairs() const
{
    std::cout << "Pair(elementSize): " << this->_elementSize << std::endl;
    std::cout << "Pair(first): " << this->_first << std::endl;
    std::cout << "Pair(second): " << this->_second << std::endl;
    std::cout << "Pair(single): " << this->_single << std::endl;
}

// single = T = std::vector<int>
template <typename T>
void Pair<T>::_updateSingle(void)
{
    this->_single = this->_first;
    this->_single.insert(this->_single.end(), this->_second.begin(), this->_second.end());
}
