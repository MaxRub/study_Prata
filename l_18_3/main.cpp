#include <iostream>
template <typename T>
long double sum_values(const T& value)
{
    return (long double) value;
}
template <typename T, typename... Args>
long double sum_values(const T& value, const Args&... args)
{
    long double total = sum_values(args...);
    return value + total;
}
int main()
{
    char ch = 'f';
    double d = 231.009804;
    long double Sum = sum_values(13, d, -91.0, ch);
    std::cout << "Sum: " << Sum << std::endl;
    Sum = sum_values(d, ch);
    std::cout << "Sum: " << Sum << std::endl;
    std::cout << "Hello World!" << std::endl;
    return 0;
}
