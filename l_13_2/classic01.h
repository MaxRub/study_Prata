#ifndef CLASSIC01_H
#define CLASSIC01_H
//derived class
#include "cd01.h"
class Classic : public Cd
{
private:
    char * title_;
public:
    Classic(char * s0, char * s1, char * s2, int n, double x);
    Classic(char * s0, const Cd &);
    Classic();
    ~Classic();
    void Report() const;
    Classic & operator=(const Classic &);
};
#endif // CLASSIC01_H
