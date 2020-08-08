#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>         //for sort()
int reduce(long ar[], int n);
void ShowData(const long & L);
int main()
{
    using std::cout;
    using std::endl;
    using std::cin;
    long my_ar[14] = {1991, 1991, 1992, 1993, 1994, 1995, 1996,
                     1997, 1998, 2000, 2000, 1994, 2000, 1997};
    int result = reduce(my_ar, 14);
    cout << "The number of elements after data processing: " << result << endl;
    cout << "Hello World!" << endl;
    return 0;
}
int reduce(long ar[], int n)
{
    using std::vector;
    vector<long> lv;
    std::cout << "\tData:\n";
    for(int i = 0; i < n; i++)
    {
        lv.push_back(ar[i]);  //using the push_back() method
        ShowData(ar[i]);
    }
    std::cout << std::endl;

    sort(lv.begin(), lv.end());  //using the sort() function

    vector<long>::iterator pr;
    pr = unique(lv.begin(), lv.end());
    lv.erase(pr, lv.end());     //using the erase() method
    std::cout << "\tProcessed data:\n";
    for_each(lv.begin(), lv.end(), ShowData);
    std::cout << std::endl;

    int result = lv.size();
    return result;
}
void ShowData(const long & L)
{
    std::cout << L << " ";
}
