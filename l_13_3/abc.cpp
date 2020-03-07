#include "abc.h"
#include <cstring>
abcDMA::abcDMA(const char * l, int r)
{
    label_ = new  char[strlen(l)+1];
    strcpy(label_, l);
    rating_ = r;
}
abcDMA::abcDMA(const abcDMA & rs)
{
    label_ = new  char[strlen(rs.label_)+1];
    strcpy(label_, rs.label_);
    rating_ = rs.rating_;
}
abcDMA:: ~abcDMA()
{
    delete [] label_;
}
abcDMA & abcDMA::operator=(const abcDMA & rs)
{
    if(this == &rs)
        return *this;
    delete [] label_;
    label_ = new  char[strlen(rs.label_)+1];
    strcpy(label_, rs.label_);
    rating_ = rs.rating_;
    return *this;
}
std::ostream &  operator<<(std::ostream & os,
                                  const abcDMA & rs)
{
    os << "Label: " << rs.label_ << std::endl;
    os << "Rating: " << rs.rating_<< std::endl;
    return os;
}
void abcDMA::View() const
{
    std::cout << "Label: " << label_ << std::endl;
    std::cout << "Rating: " << rating_ << std::endl;
}
//baseDMA methods
baseDMA::baseDMA(const char * l, int r): abcDMA(l,r)
{

}
baseDMA::baseDMA(const baseDMA & rs): abcDMA(rs)
{

}
baseDMA::~baseDMA()
{

}
baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    abcDMA::operator=(rs);
    return *this;
}
std::ostream &  operator<<(std::ostream & os,
                                  const baseDMA & rs)
{
    os << (const abcDMA &)rs;
    return os;
}
void baseDMA::View() const
{
    using std::cout;
    using std::endl;
    cout << "\tObject baseDMA:" << endl;
    abcDMA::View();
}
//lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r):abcDMA(l, r)
{
    strncpy(color_, c, 39);
    color_[39] = '\0';
}
std::ostream &  operator<<(std::ostream & os,
                                  const lacksDMA & rs)
{
    os << (const abcDMA &) rs;
    os << "Color: " << rs.color_ << std::endl;
    return os;
}
void lacksDMA::View() const
{
    using std::cout;
    using std::endl;
    cout << "\tObject lacksDMA:" << endl;
    cout << "Color: " << color_ << std::endl;
    abcDMA::View();
}
//hasDMA methods
hasDMA::hasDMA(const char * s, const char * l,
         int r):abcDMA(l, r)
{
    style_ = new char[std::strlen(s) + 1];
    std::strcpy(style_, s);
}
hasDMA::hasDMA(const hasDMA & hs):abcDMA(hs)
{
    style_ = new char[std::strlen(hs.style_) + 1];
    std::strcpy(style_, hs.style_);
}
hasDMA::~hasDMA()
{
    delete [] style_;
}
hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    abcDMA::operator=(hs);
    delete [] style_;
    style_ = new char[std::strlen(hs.style_) + 1];
    std::strcpy(style_, hs.style_);
    return *this;
}
std::ostream &  operator<<(std::ostream & os,
                                  const hasDMA & hs)
{
    os << (const abcDMA &) hs;
    os << "Style: " << hs.style_ << std::endl;
    return os;
}
void hasDMA::View() const
{
    using std::cout;
    using std::endl;
    cout << "\tObject hasDMA:" << endl;
    cout << "Style: " << style_ << std::endl;
    abcDMA::View();
}
