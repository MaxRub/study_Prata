#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>
class Store
{
private:
    std::ofstream & os;
public:
    Store(std::ofstream & of ): os(of){}
    void operator()(const std::string & s)
    {
        unsigned len = s.size();
        os.write((char *) &len, sizeof (std::size_t));
        os.write(s.data(), len);
    }
};
void ShowStr(const std::string & s);
void GetStrs(std::ifstream & fi, std::vector<std::string> & vs);
int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    //save in file
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    //restore the contents of the file
    vector<string> vistr;
    ifstream fin("strings.data", ios_base::in | ios_base::binary);
    if(!fin.is_open())
    {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);
    cout << "Hello World!" << endl;
    return 0;
}
void ShowStr(const std::string & s)
{
    std::cout << s << std::endl;
}
void GetStrs(std::ifstream & fi, std::vector<std::string> & vs)
{
    std::string temp;
    while(fi.peek() &&!fi.eof())
    {
        char ch;
        unsigned len;
        fi.read((char *) &len, sizeof (std::size_t));
        for (unsigned i = 1; i <= len; i++)
        {
            fi.read((char *) &ch, sizeof ch);
            temp.push_back(ch);
        }
        vs.push_back(temp);
    }
}
