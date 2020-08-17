#include <iostream>
#include <fstream>
#include <string>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;
    using std::ofstream;

    ofstream fout;
    string file_name;
    char ch;

    cout << "Please, enter the file name: ";
    cin >> file_name;
    fout.open(file_name.c_str());
    if (fout.is_open())
    {
        cout << "Enter text: ";
        while(cin.get(ch) && ch != EOF)     //<Ctrl-D>
            fout << ch;
    }
    else
        cout << "Could not open file for output.\n";
    fout.close();
    cout << "Hello World!" << endl;
    return 0;
}
