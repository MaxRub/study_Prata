#include <iostream>
#include "cd.h"
#include <cstring>
Cd::Cd(char *s1, char * s2, int n,double x)
{
    std::strcpy(performers_, s1);
    performers_[std::strlen(s1) + 1] = '\0';
    std::strcpy(label_, s2);
    label_[std::strlen(s2) + 1] = '\0';
    selections_ = n;
    playtime_ = x;
}
Cd::Cd(const Cd & d)
{
    std::strcpy(performers_, d.performers_);
    performers_[std::strlen(d.performers_) + 1] = '\0';
    std::strcpy(label_, d.label_);
    label_[std::strlen(d.label_) + 1] = '\0';
    selections_ = d.selections_;
    playtime_ = d.playtime_;
}
Cd::Cd()
{
    performers_[0] = '\0';
    label_[0] = '\0';
    selections_ = 0;
    playtime_ = 0.0;
}
Cd::~Cd()
{

}
void Cd::Report() const
{
    using std::cout;
    using std::endl;
    cout << "Performers: " << performers_ << endl;
    cout << "Label: " << label_ << endl;
    cout << "Selections: " << selections_ << endl;
    cout << "Playtime: " << playtime_ << endl;
}
Cd & Cd::operator=(const Cd & d)
{
    if (this == & d)
        return *this;
    std::strcpy(performers_, d.performers_);
    performers_[std::strlen(d.performers_) + 1] = '\0';
    std::strcpy(label_, d.label_);
    label_[std::strlen(d.label_) + 1] = '\0';
    selections_ = d.selections_;
    playtime_ = d.playtime_;
    return  *this;
}
