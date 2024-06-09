#include <iostream>
#include "Serializer.hpp"


int main(void)
{
    Data data = {"key1", 1};
    Data *tmp_data;
    uintptr_t raw;

    raw = Serializer::serialize(&data);
    std::cout << "serialize(data): " << raw << std::endl;
    tmp_data = Serializer::deserialize(raw);
    std::cout << "deserialize(raw): {" << tmp_data->key << ", " << tmp_data->value << "}" << std::endl;

    return (0);
}
