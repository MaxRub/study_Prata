#include <iostream>
#include "worker.h"
#include "queuetp.h"
#include <cstring>
const int SIZE = 5;
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::strchr;
    QueueTp<Worker *> lolas(SIZE);
    Worker * pw;
    while (!lolas.isfull())
    {
        char choice;
        cout << "Enter the employee category: \n"
             << "w: waiter s: singer "
             << "t: singing waiter q: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == nullptr)
        {
            cout << "Please enter a w, s, t or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'w': pw = new Waiter;
            break;
        case 's': pw = new Singer;
            break;
        case 't': pw = new SingerWaiter;
            break;
        }
        cin.get();
        pw->Set();
        lolas.enqueue(pw);
    }
    cout << "\nHere is your staff:\n";
    while (!lolas.isempty())
    {
        cout << endl;
        lolas.dequeue(pw);
        pw->Show();
        delete pw;
    }
    cout << "Hello World!" << endl;
    return 0;
}
