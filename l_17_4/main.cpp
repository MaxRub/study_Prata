#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main(int argc, char * argv[])
{
    if (argc < 4)
    {
        std::cerr << "Usage: " << argv[0] << " filename[s]\n";
        exit(EXIT_FAILURE);
    }

    std::ifstream fin_1(argv[1]);
    if(!fin_1.is_open())
    {
        std::cerr << "Could not open " << argv[1] << " for input.\n";
        exit(EXIT_FAILURE);
    }
    std::ifstream fin_2(argv[2]);
    if(!fin_2.is_open())
    {
        std::cerr << "Could not open " << argv[2] << " for input.\n";
        exit(EXIT_FAILURE);
    }
    std::ofstream fout(argv[3]);
    if(!fout.is_open())
    {
        std::cerr << "Could not open " << argv[3] << " for output.\n";
        exit(EXIT_FAILURE);
    }
    std::string temp_1, temp_2;

    while(!fin_1.eof() || !fin_2.eof()) //using ||, not &&
    {
        getline(fin_1, temp_1);
        getline(fin_2, temp_2);
        fout << temp_1 << ' ' << temp_2 << std::endl;
        //fout works the same way cout
    }
    fin_1.close();
    fin_2.close();
    fout.close();
    std::cout << "Hello World!" << std::endl;
    return 0;
}
