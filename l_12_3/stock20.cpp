#include <iostream>
#include "stock20.h"
#include <cstring>
Stock::Stock()
{
    len_ = 0;
    company_ = nullptr;
    shares_ = 0.0;
    share_val_ = 0.0;
}
Stock::Stock(const char * name, long n, double pr)
{
    len_ = strlen(name);
    company_ = new char[len_ + 1];
    std::strcpy(company_, name);
    if(n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                  << company_ << " shares set to 0.\n";
        shares_ = 0;
    }
    else
        shares_ = n;
    share_val_ = pr;
    set_tot_();
}
Stock::~Stock()
{
    delete [] company_;
}
void Stock::buy(long num,double price)
{
    if(num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares_ += num;
        share_val_ = price;
        set_tot_();
    }
}
void Stock::sell(long num, double price)
{
    using std::cout;
    if(num < 0)
    {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if(num > shares_)
    {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares_ -= num;
        share_val_ = price;
        set_tot_();
    }
}
void Stock::update(double price)
{
    share_val_ = price;
    set_tot_();
}
std::ostream & operator<<(std::ostream & os, const Stock & S)
{
    using std::ios_base;
    ios_base::fmtflags orig =
            os.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = os.precision(3);
    os << "Company: " << S.company_
       << " Shares: " << S.shares_ << '\n';
    os << " Share Price: $" << S.share_val_;

    os.precision(2);
    os << " Total Worth: $" << S.total_val_ << '\n';

    os.setf(orig, ios_base::floatfield);
    os.precision(prec);
}
const Stock & Stock::topval(const Stock & s) const
{
    if(s.total_val_ > total_val_)
        return s;
    else
        return *this;
}
