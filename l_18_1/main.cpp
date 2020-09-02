#include <iostream>
#include <initializer_list>
template <typename T>
T average_list(std::initializer_list<T> il);

int main()
{
    using namespace std;
    //typename double
    auto q = average_list({15.4, 10.7, 9.0});
    cout << q << endl;

    //typename int
    cout << average_list({20, 30, 19, 17, 45, 38}) << endl;

    //typename double
    auto ad = average_list<double>({'A', 70 , 65.33});
    cout << ad << endl;
    cout << "Hello World!" << endl;
    return 0;
}
template <typename T>
T average_list(std::initializer_list<T> il)
{
    T average = 0;
    T total = 0;
    for(auto pt = il.begin(); pt != il.end(); ++pt)
    {
        total += *pt;
    }
    average = total / il.size();
    return average;
}
