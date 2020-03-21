#include <iostream>
#include "wine.h"
Wine::Wine(const char * l, int y, const int yr[],
           const int bot[]): label_(l), years_(y)
{
    info_.first().resize(years_);
    info_.second().resize(years_);
    for (int i = 0; i < years_; i++)
    {
        info_.first()[i] = yr[i];
        info_.second()[i] = bot[i];
    }
}
Wine::Wine(const char * l, int y): label_(l), years_(y)
{

}
Wine::~Wine() {}
void Wine::Show() const
{
    std::cout << "Wine: " << label_ << std::endl
              << "\tYear\tBottles\n";
    for (int i = 0; i < years_; i++)
    {
        std::cout << "\t" << info_.first()[i] << "\t"
                  << info_.second()[i] << std::endl;
    }
}
void Wine::GetBottles()
{
    std::cout << "Enter " << label_ << " data for " << years_ <<
                 " year(s) :\n";
    info_.first().resize(years_);
    info_.second().resize(years_);
    for (int i = 0; i < years_; i++)
    {
        std::cout << "Enter year: ";
        int  temp_y;
        std::cin >> temp_y;
        std::cout << "Enter bottles for that year: ";
        int temp_b;
        std::cin >> temp_b;
        info_.first()[i] = temp_y;
        info_.second()[i] = temp_b;
    }
}
int Wine::sum() const
{
    int temp = 0;
    for (int i = 0; i < years_; i++)
    {
        temp += info_.second()[i];
    }
    return temp;
}
