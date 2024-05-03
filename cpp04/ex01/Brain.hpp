#ifndef __BRAIN_H__
#define __BRAIN_H__

#include <iostream>

class Brain
{
public:
    static const int NUM_IDEA = 100;
    Brain();
    Brain(const Brain &other);
    ~Brain();
    Brain &operator=(const Brain &other);
    const std::string& getIdea(const unsigned int i) const;
    void setIdea(const unsigned i, const std::string &idea);

protected:
private:
    std::string _ideas[NUM_IDEA];
};

#endif
