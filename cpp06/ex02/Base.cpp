#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/*
Notes: Casting in C++
    - static_cast: Compile-time cast. It does not check the validity of the cast.
        - basic type convert, e.g. int to float: static_cast<float>(int)
        - upcast: static_cast<Base*>(Derived*)
        - downcast: static_cast<Derived*>(Base*)
        - void pointer: static_cast<void*>(int*)
    - const_cast: Used to add or remove const-ness from a variable.
        - add const: const_cast<const int*>(int*)
        - add volatile: const_cast<volatile int*>(int*)
        - remove const: const_cast<int*>(const int*)
        - remove volatile: const_cast<int*>(volatile int*)
    - reinterpret_cast: Converts a pointer to any other type of pointer.
        - Pointer Type Conversion: reinterpret_cast<int*>(char*)
        - Pointer and Integer Conversion: reinterpret_cast<uintptr_t>(pointer)
        - Pointer to Function Conversion: reinterpret_cast<void(*)()>(function_pointer)
        - Reference Type Conversion: reinterpret_cast<int&>(char&)
    - dynamic_cast: Run-time cast. It checks the validity of the cast.
        - downcast: dynamic_cast<Derived*>(Base*)
        - upcast: dynamic_cast<Base*>(Derived*)
        - only works with pointers and references
        - only works with polymorphic classes (classes with at least one virtual function)
        - returns nullptr if the cast is not valid
*/
Base *generate(void)
{
    int i = std::rand() % MAX_TYPE_NUM;

    if (i == TYPE_A)
        return (new A());
    else if (i == TYPE_B)
        return (new B());
    else
        return (new C());
}

void identify(Base *p)
{
    A *a = dynamic_cast<A *>(p);
    B *b = dynamic_cast<B *>(p);
    C *c = dynamic_cast<C *>(p);

    if (a)
        std::cout << "A" << std::endl;
    else if (b)
        std::cout << "B" << std::endl;
    else if (c)
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}
void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e)
    {
        try
        {
            B &b = dynamic_cast<B &>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch (std::exception &e)
        {
            try
            {
                C &c = dynamic_cast<C &>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}
