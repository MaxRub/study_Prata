#include <iostream>
#include <fstream>

int main(int argc, char * argv[])
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;
    using std::ofstream;
    //exit in the absence of an argument
    if (argc == 1)
    {
        std::cerr << "Usage: " << argv[0] << " filename[s]\n";
        exit(EXIT_FAILURE);
    }
    ofstream fout;
    char ch;

    fout.open(argv[1]);     //opening stream and connecting to argv[1]
    if (fout.is_open())
    {
        cout << "Enter text <Ctrl-D to quit>: ";
        while(cin.get(ch) && ch != EOF)     //<Ctrl-D>
            fout << ch;
    }
    else
        cout << "Could not open file for output.\n";
    fout.close();
    cout << "Hello World!" << endl;
    return 0;
}
