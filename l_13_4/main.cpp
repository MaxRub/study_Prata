#include <iostream>
#include "port.h"
#include "vintage.h"
using namespace std;

int main()
{
    VintagePort A,C;
    Port B("Gallo", "tawny", 20);
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    A.Show();
    B.Show();
    cout << endl;
    A += 10;
    A.Show();
    cout << "Hello World!" << endl;
    return 0;
}
