#include <iostream>
#include "cd01.h"
#include <cstring>
Cd::Cd(char *s1, char * s2, int n,double x)
{
    performers_ = new char [std::strlen(s1) + 1];
    std::strcpy(performers_, s1);
    label_ = new char[std::strlen(s2) + 1];
    std::strcpy(label_, s2);
    selections_ = n;
    playtime_ = x;
}
Cd::Cd(const Cd & d)
{
    performers_ = new char[std::strlen(d.performers_) + 1];
    std::strcpy(performers_, d.performers_);
    label_ = new char[std::strlen(d.label_) + 1];
    std::strcpy(label_, d.label_);
    selections_ = d.selections_;
    playtime_ = d.playtime_;
}
Cd::Cd()
{
    performers_ = nullptr;
    label_ = nullptr;
    selections_ = 0;
    playtime_ = 0.0;
}
Cd::~Cd()
{
    delete [] performers_;
    delete [] label_;
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
    delete [] performers_;
    performers_ = new char[std::strlen(d.performers_) + 1];
    std::strcpy(performers_, d.performers_);
    delete [] label_;
    label_ = new char[std::strlen(d.label_) + 1];
    std::strcpy(label_, d.label_);
    selections_ = d.selections_;
    playtime_ = d.playtime_;
    return  *this;
}
