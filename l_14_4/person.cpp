#include <iostream>
#include "person.h"
using std::cout;
using std::cin;
using std::endl;
//Person methods
Person::~Person()
{

}
void Person::Show() const
{
    std::cout << "\tPerson:" << std::endl;
    Data();
}
void Person::Set()
{
    cout << "Enter person`s first name: ";
    Get();
}
//protected method
void Person::Data() const
{
    cout << "First name: " << first_name << endl;
    cout << "Last name: " << last_name << endl;
}
void Person::Get()
{
    getline(cin, first_name);
    cout << ", end last name: ";
    getline(cin, last_name);
}
//Gunslinger method
void Gunslinger::Set()
{
    cout << "Enter gunslinger`s first name: ";
    Person::Get();
    Get();
}
void Gunslinger::Show() const
{
    cout << "\tGunslinger\n";
    Person::Data();
    Data();
}
//protected method
void Gunslinger::Data() const
{
    cout << "Time is needed for the sniper to go into\n"
            "combat readiness: " << Drow() << endl;
    cout << "Number of notches on the rifle: " << notching << endl;
}
void Gunslinger::Get()
{
    cout << "Enter the time is needed for the sniper to go into\n"
            "combat readiness: ";
    cin >> ready_time;
    cin.get();
    cout << "Enter the number of notches on the rifle: ";
    cin >> notching;
    while (cin.get() != '\n')
        continue;
}
//PokerPlayer method
void PokerPlayer::Set()
{
    cout << " Enter poker player`s first name: ";
    Person::Get();
}
void PokerPlayer::Show() const
{
    cout << "\tPoker Player\n";
    Person::Data();
    Data();
}
//protected method
void PokerPlayer::Data() const
{
    cout << "Game card: " << Drow() << endl;
}
//BadDude method
void BadDude::Show() const
{
    cout << "\tBadDude\n";
    Person::Data();
    Gunslinger::Data();
    PokerPlayer::Data();
}
void BadDude::Set()
{
    cout << "Enter baddud`s first name: ";
    Person::Get();
    Gunslinger::Get();
}
