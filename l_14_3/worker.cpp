#include <iostream>
#include "worker.h"
using std::cout;
using std::cin;
using std::endl;
//Worker
Worker::~Worker() {}
void Worker::Data() const
{
    cout << "Name: " << fullname_ << endl;  //first and last name
    cout << "Employee ID: " << id_ << endl; //identification
}
void Worker::Get()
{
    getline(cin,fullname_);
    cout << "Enter worker`s ID: ";     //input of worker ID
    cin >> id_;
    while (cin.get() != '\n')
        continue;
}
//Waiter
void Waiter::Set()
{
    cout << "Enter waiter`s name: ";    //input of worker name
    Worker::Get();
    Get();
}
void Waiter::Show() const
{
    cout << "Category: waiter\n";
    Worker::Data();
    Data();
}
//protected method
void Waiter::Data() const
{
    cout << "Panache rating: " << panache << endl;
}
void Waiter::Get()
{
    cout << "Enter waiter`s panache rating: ";
            //enter the waiter`s elegance index
    cin >> panache;
    while (cin.get() != '\n')
        continue;
}
//Singer
char * Singer::pv[Singer::Vtypes] = {"other", "alto",
                                    "contralto", "soprano",
                                     "bass", "baritone", "tenor"};
void Singer::Set()
{
    cout << "Enter singer`s name: ";
    Worker::Get();
    Get();
}
void Singer::Show() const
{
    cout << "Category: singer\n";
    Worker::Data();
    Data();
}
//protected method
void Singer::Data() const
{
    cout << "Vocal range: " << pv[voice] << endl;
}
void Singer::Get()
{
    cout << "Enter number for singer`s vocal range:\n";
    int i;
    for (i = 0; i < Vtypes; i++)
    {
        cout << i << ": " << pv[i] << " ";
        if ( i % 4 == 3)
            cout << endl;
    }
    if (i % 4 != 0)
        cout << '\n';
    cin >> voice;
    while (cin.get() != '\n')
        continue;
}
//SingerWaiter
void SingerWaiter::Data() const
{
    Singer::Data();
    Waiter::Data();
}
void SingerWaiter::Get()
{
    Waiter::Get();
    Singer::Get();
}
void SingerWaiter::Set()
{
    cout << "Enter singer waiter`s name: ";
    Worker::Get();
    Get();
}
void SingerWaiter::Show() const
{
    cout << "Category: singing waiter\n";
    Worker::Data();
    Data();
}
