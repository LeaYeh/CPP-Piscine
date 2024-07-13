#include <random>
#include "Span.hpp"

int main()
{
    {
        std::cout << "Test copy constructor:\n";
        Span sp1 = Span(10);
        std::vector<int> vec;

        for (int i = 0; i < 10; i++)
            vec.push_back(i);
        sp1.addNumbers(vec.begin(), vec.end());
        Span sp2 = Span(sp1);
        std::cout << sp1;
        std::cout << sp2;
    }
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine engine(seed);
        std::cout << "Test with large size of array:\n";
        Span sp = Span(1000000);
        std::vector<int> vec;

        for (int i = 0; i < 1000000; i++)
            vec.push_back(i);
        std::shuffle(vec.begin(), vec.end(), engine);
        try
        {
            sp.addNumbers(vec.begin(), vec.end());
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << std::endl;
    }
    {
        std::cout << "Test copy operator:\n";
        Span sp1 = Span(10);
        Span sp2 = Span(5);

        for (int i = 0; i < 10; i++)
            sp1.addNumber(i);
        for (int i = 0; i < 5; i++)
            sp2.addNumber(i * 10);
        std::cout << "Before...\n";
        std::cout << sp1;
        std::cout << sp2;
        sp1 = sp2;
        std::cout << "After...\n";
        std::cout << sp1;
        std::cout << sp2;
        std::cout << std::endl;
    }
    {
        std::cout << "Test functionality:\n";
        Span sp = Span(5);
        std::vector<int> vec;

        vec.push_back(6);
        vec.push_back(3);
        vec.push_back(17);
        vec.push_back(9);
        vec.push_back(11);

        sp.addNumbers(vec.begin(), vec.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << std::endl;
    }
    {
        try
        {
            std::cout << "Test exception 1:\n";
            Span sp = Span(0);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << std::endl;
    }
    {
        try
        {
            std::cout << "Test exception 2:\n";
            Span sp = Span(1);

            std::cout << sp.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << std::endl;
    }
    {
        try
        {
            std::cout << "Test exception 3:\n";
            Span sp1 = Span(1);
            Span sp2 = Span(2);

            sp1 = sp2;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << std::endl;
    }

    return (0);
}
