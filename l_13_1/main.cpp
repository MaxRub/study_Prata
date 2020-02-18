#include <iostream>

using namespace std;
#include "classic.h"
void Bravo(const Cd & disk);
int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                         "Alfred Brendel", "Philips", 2, 57.17);
    Cd * pcd = &c1;
    //Direct use of objects
    cout << "Using object directly:\n";
    c1.Report();                    //using the method Cd
    c2.Report();                    //using the method Classic
    //Using a pointer to an object of type cd *
    cout << "Using type cd * pointer to objects:\n";
    pcd->Report();                  // using the method Cd for object cd
    pcd = &c2;
    pcd->Report();                  // using the method Classic for object classic
    //Calling a function with a Cd reference argument
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    //Testing assignment
    cout << "Testing assignment:\n";
    Classic copy;
    copy = c2;
    copy.Report();
    cout << "Hello World!" << endl;
    return 0;
}
void Bravo(const Cd & disk)
{
    disk.Report();
}
