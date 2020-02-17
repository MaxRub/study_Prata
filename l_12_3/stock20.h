#ifndef STOCK20_H
#define STOCK20_H
#include<iostream>
class Stock
{
private:
    int len_;
    char * company_;
    int shares_;
    double share_val_;
    double total_val_;
    void set_tot_() {total_val_ = shares_ * share_val_;}
public:
    Stock();
    Stock(const char * name, long n = 0, double pr = 0.0);
    ~Stock();
    void buy(long num,double price);
    void sell(long num, double price);
    void update(double price);
    friend std::ostream & operator<<(std::ostream & os, const Stock & S);
    const Stock & topval(const Stock & s)const;
};

#endif // STOCK20_H
