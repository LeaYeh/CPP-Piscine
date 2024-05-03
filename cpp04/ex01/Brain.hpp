#ifndef __BRAIN_H__
#define __BRAIN_H__

#include <iostream>

class Brain
{
public:
    Brain();
    Brain(const Brain &other);
    ~Brain();
    Brain &operator=(const Brain &other);

protected:
private:
    static const int _NUM_IDEA = 100;
    std::string _ideas[_NUM_IDEA];
};

#endif
