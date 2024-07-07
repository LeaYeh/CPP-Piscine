#include "MutantStack.hpp"


template<typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack<T, Container>& other) {
    if (this != &other) {
        std::stack<T, Container>::operator=(other);
    }
    return *this;
}
