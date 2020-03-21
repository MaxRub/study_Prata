#include <iostream>
#include "wine.h"

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;
    cout << "Enter name of wine: ";    //enter label
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: "; //enter number of
                                //years of grape harvesting
    int yrs;
    cin >> yrs;
    Wine holding(lab, yrs); //save the name, years,
                            //create an array of yrs elements
    holding.GetBottles();   //invitation to enter the year
                            //and number of bottles
    holding.Show();         //output contained in the object
    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = { 48, 60, 72};
    //creation of a new object, initialization
    //using data from arrays y and b
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout << "Total bottles for " << more.Label()
         << ": " << more.sum() << endl;
    cout << "Hello World!" << endl;
    return 0;
}
