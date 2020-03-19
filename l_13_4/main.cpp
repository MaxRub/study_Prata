//The test Port and VintagePort classes
#include <iostream>
#include "port.h"
#include "vintage.h"
using namespace std;
const int SIZE = 2;
int main()
{
    Port* collection[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        cout << "Enter " << i + 1
             << " exhibit brand in the collection:";
        char brand[30];
        cin.getline(brand, 30);
        cout << "Enter the number of bottles:";
        int bottles;
        cin >> bottles;
        cin.get();
        cout << "Enter 1 for Port object or  "
                "2 for  VintagePort object:";
        char kind;
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "Enter either 1 or 2: ";
        cin.get();
        if (kind == '1')
        {
            cout << "Enter " << i + 1
                 << " exhibit style in the collection:";
            char style[20];
            cin.getline(style, 20);
            collection[i] = new Port(brand,style,bottles);
        }
        else if (kind == '2')
        {
            cout << "Enter exhibit nickname:";
            char nickname[30];
            cin.getline(nickname, 30);
            int year;
            cout << "Enter year:";
            cin >> year;
            cin.get();
            collection[i] = new VintagePort(brand,bottles,nickname,year);
        }
    }
    for(int i = 0; i < SIZE; i++)
        collection[i]->Show();
    cout << "Hello World!" << endl;
    return 0;
}
