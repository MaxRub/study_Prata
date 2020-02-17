#include <iostream>
#include "cow.h"

int main()
{
    using namespace std;
    Cow A;
    Cow B("Maxim","Super", 99);
    Cow C(B);
    B.ShowCow();
    A = B;
    A.ShowCow();
    C.ShowCow();
    Cow * pC = new Cow;
    *pC = A;
    pC->ShowCow();
    delete pC;
    cout << "Hello World!" << endl;
    return 0;
}
