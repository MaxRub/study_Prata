#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char * argv[])
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::ifstream;
    using std::ofstream;

    if (argc == 1)
    {
        std::cerr << "Usage: " << argv[0] << " filename[s]\n";
        exit(EXIT_FAILURE);
    }
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    if(fin.is_open())
    {
        while(fin)
        {
            char ch;
            fin.get(ch);
            fout << ch;
        }
    }
    else
    {
        std::cerr << "Error in opening or reading " << argv[1] << ".\n";
        exit(EXIT_FAILURE);
    }
    fin.close();
    fout.close();
    cout << "Hello World!" << endl;
    return 0;
}
