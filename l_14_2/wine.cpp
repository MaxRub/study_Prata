#include <iostream>
#include "wine.h"
Wine::Wine(const char * l, int y, const int yr[], const int bot[])
    : PairArray(ArrayInt(yr,y), ArrayInt(bot, y)), std::string(l),
      years_(y)
{

}
Wine::Wine(const char * l, int y): PairArray(ArrayInt(y),ArrayInt(y)),
                                   std::string(l), years_(y)
{

}
Wine::~Wine() {}
void Wine::Show() const
{
    std::cout << "Wine: " << Label() << std::endl
              << "\tYear\tBottles\n";
    for (int i = 0; i < years_; i++)
    {
        std::cout << "\t" << PairArray::first()[i] << "\t"
                  << PairArray::second()[i] << std::endl;
    }
}
void Wine::GetBottles()
{
    std::cout << "Enter " << Label() << " data for " << years_ <<
                 " year(s) :\n";
    for (int i = 0; i < years_; i++)
    {
        std::cout << "Enter year: ";
        int  temp_y;
        std::cin >> temp_y;
        std::cout << "Enter bottles for that year: ";
        int temp_b;
        std::cin >> temp_b;
        PairArray::first()[i] = temp_y;
        PairArray::second()[i] = temp_b;
    }
}
const std::string & Wine::Label() const
{
    return (const std::string &) * this;
}
int Wine::sum() const
{
    return PairArray::second().sum();
    //valarray class method sum()
}
