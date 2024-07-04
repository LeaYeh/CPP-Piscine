#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>

#define MAX_TYPE_NUM 3

enum TypeIndex
{
    TYPE_A = 0,
    TYPE_B,
    TYPE_C
};

class Base
{
public:
    virtual ~Base() {};
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);
