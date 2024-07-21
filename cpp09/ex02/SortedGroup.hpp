#pragma once

template <typename ContainerPair, typename Container>
struct SortedGroup
{
    ContainerPair pairs;
    Container siloNumbers;

    SortedGroup(const ContainerPair& p, const Container& s) : pairs(p), siloNumbers(s) {}
};
