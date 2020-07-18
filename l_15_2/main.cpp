#include <iostream>
#include <cmath>
//Prototype functs
double hmean(double a, double b) throw (std::logic_error);
double gmean(double a, double b) throw (std::logic_error);
int main()
{
    using std::cout;
    using std::endl;
    using std::cin;
    double x, y, z;
    cout << "Enter two numbers: ";
    while ( cin >> x >> y)
    {
        try {
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                 << " is " << z << endl;
            z = gmean(x,y);
            cout << "Geometric mean of " << x << " and " << y
                 << " is " << z << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }
        catch (std::invalid_argument & le)
        {
            cout << le.what() << endl;
            cout << "Try again.\n";
            continue;
        }
        catch (std::domain_error & de)
        {
            cout << de.what() << endl;
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout << "Hello World!" << endl;
    return 0;
}
double hmean(double a, double b) throw(std::logic_error)
{
    if (a == -b)
        throw std::invalid_argument("Error in hmean(): values are equal");
        //function was passed an unexpected value
    return 2.0 * a * b / (a + b);
}
double gmean(double a, double b) throw(std::logic_error)
{
    if (a < 0 || b < 0)
        throw std::domain_error("gmean() arguments should be >= 0");
        //arguments to be outside the zone of definition
    return  std::sqrt(a * b);
}
