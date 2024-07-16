#include "Array.hpp"

/*
1. We don't need to initialize the array element value iteraly, we can use the default constructor of the type.
    - `this->_data = new T[n]();`
2. In C++98 When the copy assignment operator argument is a non-const reference, it will be bind to rvalues.
     But if the argument is a const reference, it will not bind to lvalues.
    - For example,
        ```cpp
        Awesome & operator= (Awesome & a) { _n = a._n; return *this; } // This will not bind to lvalues.
        Awesome & operator= (Awesome const & a) { _n = a._n; return *this; } // This will bind to lvalues.
        ```
    - So, we should use `const` keyword in the copy assignment operator.
    - In C++11, we could use `&&` to bind to rvalues.
        - For example,
            ```cpp
                Awesome & operator= (Awesome && a) { _n = a._n; return *this; } // This will bind to rvalues.
            ```
        - Other example,
            ```cpp
                bool operator==( Awesome const & rhs ) const & { return (this->_n == rhs._n); } // for lvalue
                bool operator!=( Awesome const & rhs ) && { return (this->_n != rhs._n); } // only for rvalue
            ```
*/

class Awesome
{
  public:
    Awesome(void) : _n(0) {}
    Awesome( int n ) : _n( n ) {}
    Awesome & operator= (Awesome const & a) { _n = a._n; return *this; }
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }
  private:
    int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void)
{
    {
        std::cout << std::endl;
        std::cout << "Complex object test" << std::endl;
        Array<Awesome> array_awesome(5);

        for (int i = 0; i < 5; i++)
            array_awesome[i] = Awesome(i);
        array_awesome.printElements();
    }
    {
        std::cout << "Pure type tests" << std::endl;
        std::cout << std::endl;
        Array<int> array_int;
        Array<float> array_float;
        Array<char> array_char;
    }
    {
        std::cout << std::endl;
        Array<int> array_int(10);

        array_int.printElements();
    }
    {
        std::cout << std::endl;
        Array<int> array_int(5);
        Array<float> array_float(10);

        for (int i = 0; i < 5; i++)
            array_int[i] = i + 1;
        for (int i = 0; i < 10; i++)
            array_float[i] = i * 0.5;
        array_int.printElements();
        array_float.printElements();
    }
    {
        std::cout << std::endl;
        Array<int> array_int(5);
        Array<int> array_int2(10);

        for (int i = 0; i < 5; i++)
            array_int[i] = i + 1;
        for (int i = 0; i < 10; i++)
            array_int2[i] = i * 2;

        std::cout << "array_int: ";
        array_int.printElements();
        std::cout << "array_int2: ";
        array_int2.printElements();

        array_int = array_int2;
        std::cout << "array_int: ";
        array_int.printElements();
    }
    {
        std::cout << std::endl;
        Array<int> array_int(5);

        for (int i = 0; i < 5; i++)
            array_int[i] = 0;
        array_int.printElements();
        array_int[1] = 5;
        array_int.printElements();
        try
        {
            std::cout << "array_int[10]: " << array_int[10];
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return (0);
}
