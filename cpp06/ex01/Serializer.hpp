#pragma once
#include <iostream>
#include <stdint.h>

struct Data
{
    std::string key;
    int value;
};

class Serializer
{
public:
    Serializer() {};
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
    ~Serializer() {};

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

protected:
private:
};
