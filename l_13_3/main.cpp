#include <iostream>
#include "abc.h"
using namespace std;
const int LABELS = 3;
int main()
{
    abcDMA * p_albom[LABELS];
    int temp_r;
    char temp_l[40];
    char kind;
    for (int i = 0; i < LABELS; i++)
    {
        cout << "Enter label`s name:";
        cin.getline(temp_l, 40);
        cout << "Enter reting of label:";
        cin >> temp_r;
        cout << "Enter 1 for baseDMA object or  "
                "2 for  lacksDMA object and "
                "3 for hasDMA object: ";
        while (cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
            cout << "Enter either 1, 2 or 3: ";
        if (kind == '1')
            p_albom[i] = new baseDMA(temp_l, temp_r);

        else if(kind == '2')
        {
            char temp_c[40];
            cin.get();          //discard newline character
            cout << "Enter color:";
            cin.getline(temp_c, 40);
            p_albom[i] = new lacksDMA(temp_c, temp_l, temp_r);
        }
        else
        {
            char temp_s[40];
            cin.get();          //discard newline character
            cout << "Enter the style:";
            cin.getline(temp_s, 40);
            p_albom[i] = new hasDMA(temp_s, temp_l, temp_r);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;
    for (int i = 0; i < LABELS; i++)
    {
        p_albom[i]->View();
    }
    for (int i = 0; i < LABELS; i++)
    {
        delete p_albom[i];
    }
    cout << "Hello World!" << endl;
    return 0;
}
