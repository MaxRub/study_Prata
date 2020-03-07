#ifndef ABC_H
#define ABC_H
#include <iostream>
//Abstract base class
class abcDMA
{
private:
    char * label_;
    int rating_;
public:
    abcDMA(const char * l = nullptr, int r = 0);
    abcDMA(const abcDMA & rs);
    virtual ~abcDMA();
    abcDMA & operator=(const abcDMA & rs);
    friend std::ostream &  operator<<(std::ostream & os,
                                      const abcDMA & rs);
    virtual void View() const = 0;      //pure virtual function
};
//Base class that uses dynamic memory allocation
class baseDMA: public abcDMA
{
public:
    baseDMA(const char * l = nullptr, int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream &  operator<<(std::ostream & os,
                                      const baseDMA & rs);
    virtual void View() const;
};
//Class without dynamic memory allocation
//No destructor needed
//An implicit copy constructor is used
//An implicit assidnment operation is used
class lacksDMA: public abcDMA
{
private:
    enum {COL_LEN = 40};
    char color_[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = nullptr,
             int r = 0);
    friend std::ostream &  operator<<(std::ostream & os,
                                      const lacksDMA & rs);
    virtual void View() const;
};
//Class with dynamic memory allocation
class hasDMA: public abcDMA
{
private:
    char * style_;
public:
    hasDMA(const char * s = "none", const char * l = nullptr,
             int r = 0);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & hs);
    friend std::ostream &  operator<<(std::ostream & os,
                                      const hasDMA & rs);
    virtual void View() const;
};

#endif // ABC_H
