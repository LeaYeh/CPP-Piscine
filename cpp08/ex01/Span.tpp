template <typename Iterator>
void Span::addNumbers(const Iterator begin, const Iterator end)
{
    if (this->_size + std::distance(begin, end) > this->_capacity)
        throw(std::length_error("Not enough capacity."));
    for (Iterator it = begin; it != end; it++)
        this->_data[this->_size++] = *it;
}
