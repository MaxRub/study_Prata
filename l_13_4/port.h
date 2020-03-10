#ifndef PORT_H
#define PORT_H
#include <iostream>
using namespace std;
class Port
{
private:
    char * brand_;
    char style_[20];
    int bottles_;
public:
    Port(const char * br = "none", const char * st = "none", int b = 0);
    Port (const Port & p);
    virtual ~Port () {delete [] brand_;}
    Port & operator=(const Port & p);
    Port & operator+=(int b);
    Port & operator-=(int b);
    int BottleCount () const {return  bottles_;}
    virtual void Show() const;
    friend ostream & operator<<(ostream & os, const Port & p);
};

#endif // PORT_H
