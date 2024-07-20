#pragma once

class JacobsthalGenerator
{
public:
    JacobsthalGenerator();
    JacobsthalGenerator(const JacobsthalGenerator &other);
    JacobsthalGenerator &operator=(const JacobsthalGenerator &other);
    ~JacobsthalGenerator();

    unsigned long next(void);
    void reset(void);

protected:
private:
    unsigned long _n;
    unsigned long _j0;
    unsigned long _j1;
};
