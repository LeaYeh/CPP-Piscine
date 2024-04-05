#include <iostream>
#include <string>

int main(void)
{
    std::string str = "string context abc";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "string(address): " << &str << std::endl;
    std::cout << "stringPTR(address): " << stringPTR << std::endl;
    std::cout << "stringREF(address): " << &stringREF << std::endl;
    std::cout << "string(context): " << str << std::endl;
    std::cout << "stringPTR(context): " << *stringPTR << std::endl;
    std::cout << "stringREF(context): " << stringREF << std::endl;
    return (0);
}