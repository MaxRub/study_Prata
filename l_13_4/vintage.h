#ifndef VINTAGE_H
#define VINTAGE_H
#include "port.h"
class VintagePort: public Port
{
private:
    char * nickname_;
    int year_;
public:
    VintagePort();
    VintagePort(const char * br, int b, const char * nn, int y);
    VintagePort(const VintagePort & vp);
    ~VintagePort() {delete [] nickname_;}
    VintagePort & operator=(const VintagePort & vp);
    void Show() const;
    friend ostream & operator<<(ostream & os, const VintagePort & vp);
};

#endif // VINTAGE_H
