#include <iostream>
#include "classic.h"
#include <cstring>
Classic::Classic(char * s0, char * s1, char * s2, int n, double x): Cd(s1, s2, n, x)
{
    std::strcpy(title_, s0);
    title_ [std::strlen(s0) + 1] = '\0';
}
Classic::Classic(char * s0, const Cd & d): Cd(d)
{
    std::strcpy(title_, s0);
    title_ [std::strlen(s0) + 1] = '\0';
}
/*Classic::Classic(): Cd()
{
    title_[0] = '\0';
}*/
Classic::~Classic()
{

}
void Classic::Report() const
{
    std::cout << "Title: " << title_ << std::endl;
    Cd::Report();

}
Classic & Classic::operator=(const Classic & rc)
{
    if (this == & rc)
        return *this;
    Cd::operator=(rc);
    std::strcpy(title_, rc.title_);
    title_[std::strlen(rc.title_) + 1] = '\0';
    return  *this;
}
