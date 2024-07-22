template <typename Container>
FordJohnsonSort<Container>::FordJohnsonSort()
    : _numbers(Container()), _sortedNumbers(Container()), _level(0), _compareCount(0), _timeElapsed(0) {}

template <typename Container>
FordJohnsonSort<Container>::FordJohnsonSort(Container &numbers)
    : _numbers(numbers), _sortedNumbers(Container()), _level(0), _compareCount(0), _timeElapsed(0) {}

template <typename Container>
FordJohnsonSort<Container>::FordJohnsonSort(const FordJohnsonSort &other)
    : _numbers(other.getNumbers()), _sortedNumbers(Container()), _level(0), _compareCount(other.getCompareCount()), _timeElapsed(other.getTimeElapsed) {}

template <typename Container>
FordJohnsonSort<Container> &FordJohnsonSort<Container>::operator=(const FordJohnsonSort &other)
{
    if (this != &other)
    {
        this->_numbers = other.getNumbers();
        this->_sortedNumbers = other.getSortedNumbers();
        this->_level = other.getLevel();
        this->_compareCount = other.getCompareCount();
        this->_timeElapsed = other.getTimeElapsed();
    }
    return (*this);
}

template <typename Container>
FordJohnsonSort<Container>::~FordJohnsonSort()
{
    this->_numbers.clear();
    this->_sortedNumbers.clear();
}

template <typename Container>
int FordJohnsonSort<Container>::getCompareCount(void) const
{
    return (this->_compareCount);
}

template <typename Container>
int FordJohnsonSort<Container>::getLevel(void) const
{
    return (this->_level);
}

template <typename Container>
Container FordJohnsonSort<Container>::getNumbers(void) const
{
    return (this->_numbers);
}

template <typename Container>
Container FordJohnsonSort<Container>::getSortedNumbers(void) const
{
    return (this->_sortedNumbers);
}

template <typename Container>
double FordJohnsonSort<Container>::getTimeElapsed(void) const
{
    return (this->_timeElapsed);
}

template <typename Container>
void FordJohnsonSort<Container>::setNumbers(Container &numbers)
{
    this->_numbers = numbers;
}

// ValueType = int
// Container = std::vector<int> or std::deque<int> or std::queue<int>
// ContainerPair = Pair<std::vector<int> >
// ContainerPairContainer = std::vector<Pair<std::vector<int> > >
template <typename Container>
void FordJohnsonSort<Container>::sort(void)
{
    ContainerPairContainer pairs;

    for (unsigned long i = 0; i < this->_numbers.size(); i++)
    {
        Container single;
        single.push_back(this->_numbers[i]);
        ContainerPair siloPair(single);
        pairs.push_back(siloPair);
    }
    std::clock_t start = std::clock();
    this->_recursiveSort(pairs);
    std::clock_t end = std::clock();
    this->_timeElapsed = (end - start) / (double)CLOCKS_PER_SEC;
}

// remainderPairs = ContainerPairContainer = std::vector<Pair<std::vector<int> > >
template <typename Container>
typename FordJohnsonSort<Container>::ContainerPairContainer FordJohnsonSort<Container>::_recursiveSort(ContainerPairContainer &pairs)
{
    ContainerPairContainer currentLevelRemainderPairs;
    ContainerPairContainer lowerLevelRemainderPairs;

    if (!this->_pairwise(pairs, currentLevelRemainderPairs))
        return (ContainerPairContainer());
    this->_level++;
    lowerLevelRemainderPairs = this->_recursiveSort(pairs);
    this->_level--;
    if (this->_level == 0)
        this->_insertion(pairs, currentLevelRemainderPairs);
    else
        this->_insertion(pairs, lowerLevelRemainderPairs);
    return (currentLevelRemainderPairs);
}

// pairs = ContainerPairContainer = std::vector<Pair<std::vector<int> > >, a vector of 1 element pairs
// remainderPairs = ContainerPairContainer = std::vector<Pair<std::vector<int> > >
template <typename Container>
bool FordJohnsonSort<Container>::_pairwise(
    ContainerPairContainer &pairs,
    ContainerPairContainer &currentLevelRemainderPairs)
{
    const unsigned long levelElementSize = std::pow(2, this->_level);
    const unsigned long lowerLevelElementSize = std::pow(2, std::max(this->_level - 1, 0));
    Container numbers = this->_convertToNumbers(pairs);

    if (numbers.size() < levelElementSize * 2)
        return (false);
    pairs.clear();
    currentLevelRemainderPairs.clear();
    unsigned long i;
    for (i = 0; i <= numbers.size() - (levelElementSize * 2); i += levelElementSize * 2)
    {
        ContainerPairContainer tmpPairs;
        this->_setupPairElement(tmpPairs, numbers, i, levelElementSize, true);
        pairs.insert(pairs.end(), tmpPairs.begin(), tmpPairs.end());
    }
    for (unsigned long j = i; j < numbers.size(); j += lowerLevelElementSize * 2)
    {
        ContainerPairContainer tmpPairs;
        this->_setupPairElement(tmpPairs, numbers, j, lowerLevelElementSize, false);
        currentLevelRemainderPairs.insert(currentLevelRemainderPairs.end(), tmpPairs.begin(), tmpPairs.end());
    }
    return (true);
}

template <typename Container>
void FordJohnsonSort<Container>::_setupPairElement(
    ContainerPairContainer &pairs,
    Container &numbers,
    int index,
    int elementSize,
    bool needToCompare)
{
    if ((unsigned long)(index + elementSize) > numbers.size())
        throw std::runtime_error("Not enough elements to setup pair, at least 1 silo elements is required");
    if ((unsigned long)(index + elementSize * 2) <= numbers.size())
    {
        Container left = Container(numbers.begin() + index, numbers.begin() + index + elementSize);
        Container right = Container(numbers.begin() + index + elementSize, numbers.begin() + index + elementSize * 2);
        Pair<Container> pair(left, right);

        if (needToCompare)
        {
            this->_compareCount++;
            if (pair.getUpperBound() < pair.getLowerBound())
                pair.swap();
        }
        pairs.push_back(pair);
    }
    else
    {
        Container single = Container(numbers.begin() + index, numbers.end());
        Pair<Container> pair(single);
        pairs.push_back(pair);
    }
}

template <typename Container>
void FordJohnsonSort<Container>::_insertion(ContainerPairContainer &unsortedPairs, ContainerPairContainer &remainderPairs)
{
    const int lowerLevelElementSize = std::pow(2, this->_level - 1);
    JacobsthalGenerator jacobSeq;
    unsigned long jb;
    unsigned long jb_prev = 0;

    this->_mergePairs(unsortedPairs, remainderPairs);
    this->_reshapePairs(unsortedPairs, lowerLevelElementSize);

    ContainerPairContainer mainChain;
    ContainerPairContainer subChain;
    this->_splitToChain(unsortedPairs, mainChain, subChain);
    mainChain.insert(mainChain.begin(), subChain[0]);
    for (unsigned long i = 1; i < subChain.size();)
    {
        jb = jacobSeq.next();
        for (unsigned long k = std::min(jb, subChain.size() - 1); k > jb_prev; k--)
        {
            this->_binarySort(mainChain, subChain[k]);
            i++;
        }
        jb_prev = jb;
    }
    if (this->_level == 0)
        this->_sortedNumbers = this->_convertToNumbers(mainChain);
    else
        unsortedPairs = mainChain;
    // sortedPairs.insert(sortedPairs.end(), unsortedPairs.begin(), unsortedPairs.begin() + 2);
    // for (unsigned long i = 2; i < unsortedPairs.size();)
    // {
    //     jb = jacobSeq.next();
    //     for (unsigned long k = std::min(jb, unsortedPairs.size() - 1); k > jb_prev; k--)
    //     {
    //         this->_binarySort(sortedPairs, unsortedPairs[k]);
    //         i++;
    //     }
    //     jb_prev = jb;
    // }
    // if (this->_level == 0)
    //     this->_numbers = this->_convertToNumbers(sortedPairs);
    // else
    //     unsortedPairs = sortedPairs;
}

template <typename Container>
void FordJohnsonSort<Container>::_splitToChain(
    ContainerPairContainer &pairs,
    ContainerPairContainer &mainChain,
    ContainerPairContainer &subChain)
{
    if (pairs.size() == 0)
        throw std::runtime_error("Pairs is empty and can not be split");
    for (unsigned long i = 0; i < pairs.size(); i++)
    {
        if (i % 2 == 1)
            mainChain.push_back(pairs[i]);
        else
            subChain.push_back(pairs[i]);
    }
}

template <typename Container>
void FordJohnsonSort<Container>::_mergePairs(ContainerPairContainer &pairs, ContainerPairContainer &remainderPairs)
{
    if (remainderPairs.size() == 0)
        return ;
    if (pairs.size() == 0)
        throw std::runtime_error("Pairs is empty");
    else if (remainderPairs.size() > 0 && remainderPairs[0].getElementSize() != pairs[0].getElementSize())
        throw std::runtime_error("Can not merge when element of the pair is not the same size");
    pairs.insert(pairs.end(), remainderPairs.begin(), remainderPairs.end());
}

template <typename Container>
void FordJohnsonSort<Container>::_reshapePairs(ContainerPairContainer &pairs, int elementSize) const
{
    Container numbers = this->_convertToNumbers(pairs);

    pairs.clear();
    if (elementSize == 0)
    {
        for (unsigned long i = 0; i < numbers.size(); i++)
        {
            Container single;
            single.push_back(numbers[i]);
            pairs.push_back(Pair<Container>(single));
        }
    }
    else
    {
        unsigned long i;
        for (i = 0; i < numbers.size(); i += elementSize * 2)
        {
            Container first(numbers.begin() + i, numbers.begin() + i + elementSize);
            Container second(numbers.begin() + i + elementSize, numbers.begin() + i + 2 * elementSize);
            pairs.push_back(Pair<Container>(first, second));
        }
    }
}

// Container = std::vector<int>
// ValueType = int
// ContainerPair = std::vector<Pair<int> >
template <typename Container>
Container FordJohnsonSort<Container>::_convertToNumbers(const ContainerPairContainer &pairs) const
{
    Container numbers;

    for (unsigned long i = 0; i < pairs.size(); i++)
    {
        const Container& single = pairs[i].single();
        numbers.insert(numbers.end(), single.begin(), single.end());
    }
    return (numbers);
}

// ValueType = int
// Container = std::vector<int> or std::deque<int> or std::queue<int>
// ContainerPair = Pair<std::vector<int> >
// ContainerPairContainer = std::vector<Pair<std::vector<int> > >
template <typename Container>
void FordJohnsonSort<Container>::_binarySort(ContainerPairContainer &container, ContainerPair target)
{
    int low = 0;
    int high = container.size() - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        this->_compareCount++;
        if (target.getUpperBound() < container[mid].getUpperBound())
            high = mid - 1;
        else if (target.getUpperBound() > container[mid].getUpperBound())
            low = mid + 1;
        else
        {
            low = mid;
            break ;
        }
    }
    container.insert(container.begin() + low, target);
}
