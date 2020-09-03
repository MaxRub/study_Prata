#include <iostream>
#include "cpmv.h"
int main()
{
    using std::cout;
    using std::endl;
    Cpmv one("qaz ","wsx");
    Cpmv two = one + one;           //move constructor
    cout << "\tobject one:\n";
    one.Display();
    cout << "\tobject two:\n";
    two.Display();
    Cpmv three, four;
    cout << "\tthree = one\n";
    three = one;
    cout << "\tnow object three:\n";
    three.Display();
    cout << "\tand object one:\n";
    one.Display();
    cout << "\tfour = one + two\n";
    four = one + two;
    cout << "\tnow object four:\n";
    four.Display();
    Cpmv five("edc","rfv");
    cout << "\tobject five:\n";
    five.Display();
    Cpmv six(five + four);          //operator+(), move constructor
    cout << "\tobject six:\n";
    six.Display();
    cout << "Hello World!" << endl;
    return 0;
}
