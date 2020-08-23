#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <emp.h>
const int MAX = 10;
void Menu();
inline void eatline() {while (std::cin.get() != '\n') continue; }
int main()
{
    using namespace std;
    abstr_emp * pc[MAX];
    int i = 0;

    //display the original content
    ifstream fin("datalist");
    if(fin.is_open())
    {
        int classtype;
        char ch;
        while((fin >> classtype).get(ch))
        {
            switch (classtype)
            {
            case employee::Employee : pc[i] = new employee;
                pc[i++]->getall(fin);
                break;
            case employee::Manager : pc[i] = new manager;
                pc[i++]->getall(fin);
                break;
            case employee::Fink : pc[i] = new fink;
                pc[i++]->getall(fin);
                break;
            case employee::Highfink : pc[i] = new highfink;
                pc[i++]->getall(fin);
                break;
            default: std::cout << "Unknown";
                break;
            }
        }
        fin.close();
    }
    int index = i;
    for (i = 0; i < index; i++)
        pc[i]->ShowAll();

    //add data at the and of the file
    if (i < MAX)
    {
        ofstream fout("datalist", ios::out | ios::app);
        if(!fout.is_open())
        {
            cerr << "Can't open \"datalist\" for output.\n";
            exit(EXIT_FAILURE);
        }
        char choice;
        Menu();
        while(cin.get(choice) && choice != 'q' && i < MAX)
        {
            switch (choice)
            {
            case 'E':
            case 'e': pc[i] = new employee;
                pc[i]->SetAll();
                pc[i++]->writeall(fout);
                eatline();
                break;
            case 'M':
            case 'm': pc[i] = new manager;
                pc[i]->SetAll();
                pc[i++]->writeall(fout);
                eatline();
                break;
            case 'F':
            case 'f': pc[i] = new fink;
                pc[i]->SetAll();
                pc[i++]->writeall(fout);
                eatline();
                break;
            case 'H':
            case 'h': pc[i] = new highfink;
                pc[i]->SetAll();
                pc[i++]->writeall(fout);
                eatline();
                break;
            default: std::cout << "Unknown\n";
                eatline();
                break;
            }
            if(i < MAX)
                Menu();
            else
                std::cout << "The array is full." << endl;
        }
        fout.close();
        //display modified content
        index = i;
        for (i = 0; i < index; i++)
        {
            pc[i]->ShowAll();
        }
    }
    else
        std::cout << "The array is full." << endl;
    cout << "Hello World!" << endl;
    return 0;
}
void Menu()
{
    std::cout << "Create a new record.\n"
              << "e. employee" << "\tm. manager\n"
              << "f. finf" << "\t\th. highfink\n"
              << "q. quit\n";
    std::cout << "Enter your choice: ";
}
