#include <iostream>
#include "port.h"
#include <cstring>
Port::Port(const char * br, const char * st, int b)
{
    brand_ = new char[strlen(br) + 1];
    strcpy(brand_, br);
    strcpy(style_, st);
    style_[19] = '\0';
    bottles_ = b;
}
Port::Port (const Port & p)
{
    brand_ = new char[strlen(p.brand_) + 1];
    strcpy(brand_, p.brand_);
    strcpy(style_, p.style_);
    style_[19] = '\0';
    bottles_ = p.bottles_;
}
Port & Port::operator=(const Port & p)
{
    if(this == &p)
        return *this;
    delete [] brand_;
    brand_ = new char[strlen(p.brand_) + 1];
    strcpy(brand_, p.brand_);
    strcpy(style_, p.style_);
    style_[19] = '\0';
    bottles_ = p.bottles_;
    return *this;
}
Port & Port::operator+=(int b)
{
    if(b > 0)
    {
        bottles_ += b;
        return *this;
    }
    cout << "The number cannot be negative!\n";
    return *this;
}
Port & Port::operator-=(int b)
{
    if(b <= bottles_)
    {
        bottles_ -= b;
        return *this;
    }
    cout << "The number cannot be bigger!\n";
    return *this;
}
 void Port::Show() const
{
     cout << "Brand: " << brand_ << endl;
     cout << "Kind: " << style_ << endl;
     cout << "Bottles: " << bottles_ << endl;
}
ostream & operator<<(ostream & os, const Port & p)
{
    os << p.brand_ << ", " << p.style_ << ", " << p.bottles_;
    return os;
}
