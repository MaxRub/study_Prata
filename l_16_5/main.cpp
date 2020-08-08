#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
template <typename L>
void ShowData(L l, int n)
{
    std::cout << "\tData:\n";
    for(int i = 0; i < n; i++)
        std::cout << l[i] << " ";
    std::cout<< std::endl;
}

template <typename T>
int reduce(T ar[], int n)
{
    using std::vector;
    vector<T> lv;
    for(int i = 0; i < n; i++)
    {
        lv.push_back(ar[i]);  //using the push_back() method
    }
    sort(lv.begin(), lv.end());  //using the sort() function
    auto pr = unique(lv.begin(), lv.end());
    lv.erase(pr, lv.end());     //using the erase() method
    ShowData(lv, lv.size());
    int result = lv.size();
    return result;
}

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;

    int result;
    //long array
    long arrL[10] {123, 456, 789, 987, 654, 123, 147, 258, 654, 987};
    ShowData(arrL, 10);
    result = reduce(arrL, 10);
    cout << "Array long: " << result << endl;
    //string array
    string arrS[13] {"123", "456", "789", "987", "654",
                     "123", "147", "258", "654", "987",
                     "Bob", "bad", "Bob"};
    ShowData(arrS, 13);
    result = reduce(arrS, 13);
    cout << "Array string: " << result << endl;

    cout << "Hello World!" << endl;
    return 0;
}
