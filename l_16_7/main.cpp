#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> Lotto(int Nummers, int n);
void ShowData (const int & n);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::vector;

    vector<int> winners;
    winners = Lotto(51, 6);

    cout << "Winning combination:\t";
    for_each(winners.begin(), winners.end(), ShowData);
    cout << endl;

    cout << "Hello World!" << endl;
    return 0;
}
std::vector<int> Lotto(int Nummers, int n)
{
    using std::cout;
    using std::endl;
    using std::vector;
    //create a vector with values from 1 to Numbers
    vector<int> temp;
    for(int i = 1; i <= Nummers; i++)
        temp.push_back(i);
    //mix the contents of the vector
    random_shuffle(temp.begin(), temp.end());
    //leave only n values
    temp.erase(temp.begin() + n, temp.end());
    //using sort()
    sort(temp.begin(), temp.end());

    return temp;
}
void ShowData (const int & n)
{
    std::cout << n << " ";
}
