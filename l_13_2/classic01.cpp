#include <iostream>
#include "classic01.h"
#include <cstring>
Classic::Classic(char * s0, char * s1, char * s2, int n, double x): Cd(s1, s2, n, x)
{
    title_ = new char[std::strlen(s0) + 1];
    std::strcpy(title_, s0);
}
Classic::Classic(char * s0, const Cd & d): Cd(d)
{
    title_ = new char[std::strlen(s0) + 1];
    std::strcpy(title_, s0);
}
Classic::Classic(): Cd()
{
    title_ = nullptr;
}
Classic::~Classic()
{
    delete [] title_;
}
void Classic::Report() const
{
    std::cout << "\tTitle: " << title_ << std::endl;
    Cd::Report();

}
Classic & Classic::operator=(const Classic & rc)
{
    if (this == & rc)
        return *this;
    Cd::operator=(rc);
    delete [] title_;
    title_ = new char[std::strlen(rc.title_) + 1];
    std::strcpy(title_, rc.title_);
    return  *this;
}
