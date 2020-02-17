#include <cstring>
#include "string2.h"
#include <cctype>
using std::cin;
using std::cout;

int String::num_string_ = 0;

int String::HowMany()
{
     return num_string_;
}
String::String(const char * s)
{
    len_ = std::strlen(s);
    str_ = new char[len_ + 1];
    std::strcpy(str_,s);
    num_string_++;
}
String::String()
{
    len_ = 4;
    str_ = new char[1];
    str_[0] = '\0';
    num_string_++;
}
String::String(const String & st)
{
    num_string_++;
    len_ = st.len_;
    str_ = new char[len_ + 1];
    std::strcpy(str_,st.str_);
}
String::~String()
{
    --num_string_;
    delete [] str_;
}
//
String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str_;
    len_ = st.len_;
    str_ = new char[len_ + 1];
    std::strcpy(str_, st.str_);
    return  *this;
}
String & String::operator=(const char * s)
{
    delete [] str_;
    len_ = std::strlen(s);
    str_ = new char[len_ + 1];
    std::strcpy(str_, s);
    return  *this;
}
char & String::operator[](int i)
{
    return str_[i];
}
const char & String::operator[](int i) const
{
    return str_[i];
}
//
bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str_, st2.str_) < 0);
}
bool operator>(const String &st1, const String &st2)
{
    return st2.str_< st1.str_;
}
bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str_, st2.str_) == 0);
}
ostream & operator<<(ostream & os, const String & st)
{
    os << st.str_;
    return os;
}
istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM_];
    is.get(temp,String::CINLIM_);
    if(is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}
void String::stringlow()
{
    for(int i = 0; i < len_; i++)
    {
        char temp;
        temp = tolower(str_[i]);
        str_[i] = temp;
    }
}
void String::stringup()
{
    for(int i = 0; i < len_; i++)
    {
        char temp;
        temp = toupper(str_[i]);
        str_[i] = temp;
    }
}
int String::has(const char ch)const
{
    int count = 0;
    for(int i = 0; i <= len_; i++)
    {
        if(str_[i] == ch)
        {
            count++;
            continue;
        }
        else
            continue;
    }
    return count;
}
String operator+(const char * ch, const String &st2)
{
    String temp;
    delete [] temp.str_;
    temp.len_ = strlen(ch) + st2.len_;
    temp.str_ = new char[temp.len_ + 1];
    strcat(temp.str_,ch);
    strcat(temp.str_,st2.str_);
    return temp;
}
String operator+(const String &st1, const String &st2)
{
    String temp;
    delete [] temp.str_;
    temp.len_ = st1.len_ + st2.len_;
    temp.str_ = new char[temp.len_ + 1];
    strcat(temp.str_,st1.str_);
    strcat(temp.str_,st2.str_);
    return temp;
}
