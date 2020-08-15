#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    char ch;
    int ct = 0;

    cout << "Enter text line: ";
    while(cin.get(ch) && cin.peek() != '$')
        ct++;
    cout << ch << " last input character." << endl;
    cout << "You entered " << ct << " characters!" << endl;
    cout << "Hello World!" << endl;
    return 0;
}
