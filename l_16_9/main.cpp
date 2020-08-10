#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>
int const NUM = 10000000;
int main()
{
    using std::cout;
    using std::endl;
    using std::vector;
    using std::list;
    //a.
    vector<int> vi0(NUM);
    for(int i = 0; i < NUM; i++)
    {
        vi0[i] = std::rand() % 1000;
    }
    //b.
    vector<int> vi(NUM);
    list<int> li(NUM);

    vi = vi0;
    copy(vi0.begin(), vi0.end(), li.begin());
    //c.
    clock_t start_sort_vi = clock();
    sort(vi.begin(), vi.end());
    clock_t end_sort_vi = clock();
    cout << "Time for algorithm sort() from STL for vector with "
         << NUM << " elements: "
         << (double)(end_sort_vi - start_sort_vi) / CLOCKS_PER_SEC
         << endl;

    clock_t start_sort_li = clock();
    li.sort();
    clock_t end_sort_li = clock();
    cout << "Time for method list sort() with " << NUM << " elements: "
         << (double)(end_sort_li - start_sort_li) / CLOCKS_PER_SEC
         << endl;
    //d.
    copy(vi0.begin(), vi0.end(), li.begin());
    clock_t start = clock();
    copy(li.begin(), li.end(), vi.begin());
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), li.begin());
    clock_t end = clock();
    cout << "Time for copy contents of list to vector,"
         << " sort vector and copy results to list: "
         << (double)(end - start) / CLOCKS_PER_SEC
         << endl;

    cout << "Hello World!" << endl;
    return 0;
}
