//In this exercise in coments /*code*/ variant whith two
//class of execepted bad_hmean and bad_gmean
#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>
/*
class bad_hmean: public std::invalid_argument
{
private:
    double v1;
    double v2;
public:
    bad_hmean(double a = 0, double b = 0,
        const std::string & s = ", hmean()")
        : std::invalid_argument(s), v1(a), v2(b) {};
    void mesg(); //
};
inline void bad_hmean::mesg()
{
    std::cout << v1 << ", " << v2 << what() << std::endl;
}
class bad_gmean: public std::domain_error
{
public:
    double v1;
    double v2;
    bad_gmean(double a = 0, double b = 0,
        const std::string & s = ", gmean()")
        : std::domain_error(s), v1(a), v2(b) {};
    void mesg();
};
inline void bad_gmean::mesg()
{
    std::cout << v1 << ", " << v2 << what() << std::endl;
}
*/
class bad_one: public std::logic_error
{
private:
    double v1;
    double v2;
public:
    bad_one(const std::string & s, double a = 0, double b = 0)
        : std::logic_error(s), v1(a), v2(b) {}
    void mesg();
};
inline void bad_one::mesg()
{
    std::cout << v1 << ", " << v2 << what() << std::endl;
};

//Prototype functs
double hmean(double a, double b);
double gmean(double a, double b);
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
        catch (std::logic_error & le)
        {
            //we andefin object type with dynamic_cast using
            //the address of the object that is referenced by the link
            /*
            if(bad_hmean * bh = dynamic_cast<bad_hmean * >(&le))
                bh->mesg();
            else if(bad_gmean * bg = dynamic_cast<bad_gmean * >(&le))
                bg->mesg();
            */
            bad_one * bo = dynamic_cast<bad_one * >(&le);
            bo->mesg();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout << "Hello World!" << endl;
    return 0;
}
double hmean(double a, double b)
{
    if (a == -b)
        /*
        throw bad_hmean(a, b);
        //function was passed an unexpected value
        */
        throw bad_one(", hmean()", a, b);
    return 2.0 * a * b / (a + b);
}
double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        /*
        throw bad_gmean(a, b);
        //arguments to be outside the zone of definition
        */
        throw bad_one(", gmean()", a, b);
    return  std::sqrt(a * b);
}
