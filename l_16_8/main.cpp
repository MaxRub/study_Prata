#include <iostream>
#include <list>
#include <algorithm>
#include <string>
void ShowData (const std::string & s);
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::list;
    using std::string;

    list<string> Meth_list;
    list<string> Pet_list;
    string friends;

    //Meth friends list
    cout << "Meth, please, enter your friends list <quit to quit>: ";
    while(getline(cin, friends) && friends != "quit")
        Meth_list.push_back(friends);
    Meth_list.sort();
    cout << "\tMeth friends list:\n";
    for_each(Meth_list.begin(), Meth_list.end(), ShowData);

    //Pet friends list
    cout << "\nPet, please, enter your friends list <quit to quit>: ";
    while(getline(cin, friends) && friends != "quit")
        Pet_list.push_back(friends);
    Pet_list.sort();
    cout << "\tPet friends list:\n";
    for_each(Pet_list.begin(), Pet_list.end(), ShowData);

    //merge lists and delete duplicates
    list<string> union_list;
    union_list.insert(union_list.begin(), Meth_list.begin(), Meth_list.end());
    union_list.insert(union_list.end(), Pet_list.begin(), Pet_list.end());
    union_list.sort();
    union_list.unique();

    cout << "\tFriends list:\n";
    for_each(union_list.begin(), union_list.end(), ShowData);

    cout << "Hello World!" << endl;
    return 0;
}
void ShowData (const std::string & s)
{
    std::cout << s << "\n";
}
