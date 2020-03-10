#include <iostream>
#include "vintage.h"
#include <cstring>

VintagePort::VintagePort(): Port("none", "vintage", 0),nickname_("none")
{
    year_ = 0;
}
VintagePort::VintagePort(const char * br, int b, const char * nn, int y): Port(br,"vintage",b)
{
    nickname_ = new char[strlen(nn) + 1];
    strcpy(nickname_, nn);
    year_ = y;
}
VintagePort::VintagePort(const VintagePort & vp): Port (vp)
{
    nickname_ = new char[strlen(vp.nickname_) + 1];
    strcpy(nickname_, vp.nickname_);
    year_ = vp.year_;
}
VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if (this == &vp)
        return *this;
    Port::operator=(vp);
    delete [] nickname_;
    nickname_ = new char[strlen(vp.nickname_) + 1];
    strcpy(nickname_, vp.nickname_);
    year_ = vp.year_;
    return *this;
}
void VintagePort::Show() const
{
    cout << "The nickname: " << nickname_ << endl;
    cout << "Year: " << year_<< endl;
    Port::Show();
}
ostream & operator<<(ostream & os, const VintagePort & vp)
{
    os << (Port &) vp << ", " << vp.nickname_ << ", " << vp.year_;
    return os;
}
