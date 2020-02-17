#ifndef STRING2_H
#define STRING2_H
#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
    char * str_;
    int len_;
    static int num_string_;
    static const int CINLIM_ = 80;
public:
    String(const char * s);
    String();
    String(const String &);
    ~String();
    int length() const {return len_;}
    //
    void stringlow();
    void stringup();
    int has(const char ch)const;
    //
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;
    //
    friend String operator+(const char * ch, const String &st2);
    friend String operator+(const String &st1, const String &st2);
    //
    friend bool operator<(const String &st1, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st1, const String &st2);
    friend ostream & operator<<(ostream & os, const String & st);
    friend istream & operator>>(istream & is, String & st);
    //
    static int HowMany();
};

#endif // STRING2_H
