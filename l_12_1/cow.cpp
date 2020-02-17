#include "cow.h"
#include <iostream>
#include <cstring>
Cow::Cow()
{
    name_[0] = '\0';
    hobby_ = nullptr;
    weight_ = 0;
}
Cow::Cow(const char * nm, const char * ho, double wt)
{
    strcpy(name_,nm);
    hobby_ = new char [strlen(ho) + 1];
    strcpy(hobby_,ho);
    weight_ = wt;
}
Cow::Cow(const Cow & c)
{
    strcpy(name_,c.name_);
    hobby_ = new char [strlen(c.hobby_) + 1];
    strcpy(hobby_,c.hobby_);
    weight_ = c.weight_;
}
Cow::~Cow()
{
    delete [] hobby_;
}
Cow & Cow::operator=(const Cow & c)
{
    if(this == & c)
        return *this;
    strcpy(this->name_,c.name_);
    delete [] hobby_;
    hobby_ = new char [strlen(c.hobby_) + 1];
    strcpy(hobby_, c.hobby_);
    weight_ = c.weight_;
    return *this;
}
void  Cow::ShowCow() const
{
    using std::cout;
    using std::endl;
    cout << name_ << endl << hobby_ << endl << weight_ << endl;
}
