#ifndef CLASSIC_H
#define CLASSIC_H
//derived class
#include "cd.h"
class Classic : public Cd
{
private:
    char title_ [40];
public:
    Classic(char * s0, char * s1, char * s2, int n, double x);
    Classic(char * s0, const Cd &);
    Classic();
    ~Classic();
    void Report() const;
    Classic & operator=(const Classic &);
};

#endif // CLASSIC_H
