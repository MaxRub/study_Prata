#ifndef CLASSIC_H
#define CLASSIC_H
//derived class
#include "cd.h"
class Classic : public Cd
{
private:
    char title_ [40];
public:
    Classic(char * s0 = nullptr, char * s1 = nullptr, char * s2 = nullptr, int n = 0, double x = 0.0);
    Classic(char * s0, const Cd &);
    //Classic();
    ~Classic();
    void Report() const;
    Classic & operator=(const Classic &);
};

#endif // CLASSIC_H
