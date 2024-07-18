#pragma once

class JacobsthalGenerator
{
public:
    JacobsthalGenerator();
    JacobsthalGenerator(const JacobsthalGenerator &other);
    JacobsthalGenerator &operator=(const JacobsthalGenerator &other);
    ~JacobsthalGenerator();

    int next(void);
    void reset(void);

protected:
private:
    int _n;
    int _j0;
    int _j1;
};
