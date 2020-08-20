#include <iostream>
#include <fstream>
#include <string>
#include <list>         //sort()
#include <iterator>     //back_inserter()
#include <algorithm>    //unique(), copy() and for_each()
#include <cstdlib>      //exit()
void ShowData (const std::string & s);
int main()
{
    using std::cout;
    using std::endl;
    using std::string;
    using std::list;
    using std::ofstream;
    using std::ifstream;

    //connecting program with files
    ifstream fin_mat("mat.dat");
    ifstream fin_pat("pat.dat");
    ofstream fout_mat_pat("matnpat.dat");

    string temp;
    list<string> mat_ls;
    list<string> pat_ls;
    list<string> mat_pat_ls;

    //mat.dat input
    if(fin_mat.is_open())
    {
        while(!fin_mat.eof())
        {
            getline(fin_mat, temp);
            mat_ls.push_back(temp);
        }
    }
    else
    {
        std::cerr << "Could not open file \"mat.dat\" for input.\n";
        exit(EXIT_FAILURE);
    }

    //pat.dat input
    if(fin_pat.is_open())
    {
        while(!fin_pat.eof())
        {
            getline(fin_pat, temp);
            pat_ls.push_back(temp);
        }
    }
    else
    {
        std::cerr << "Could not open file \"pat.dat\" for input.\n";
        exit(EXIT_FAILURE);
    }

    //data processing
    mat_ls.sort();
    cout << "\tMat has " << mat_ls.size() << " friends. His list:";
    for_each(mat_ls.begin(), mat_ls.end(), ShowData);

    pat_ls.sort();
    cout << "\tPat has " << pat_ls.size() << " friends. His list:";
    for_each(pat_ls.begin(), pat_ls.end(), ShowData);

    copy(mat_ls.begin(), mat_ls.end(), back_inserter(mat_pat_ls));
    copy(pat_ls.begin(), pat_ls.end(), back_inserter(mat_pat_ls));

    mat_pat_ls.sort();
    list<string>::iterator it = unique(mat_pat_ls.begin(),
                                       mat_pat_ls.end());
    mat_pat_ls.erase(it ,mat_pat_ls.end());

    if (fout_mat_pat.is_open())
    {
        fout_mat_pat << "\tMat and Pat have "
                     << mat_pat_ls.size() << " friends:";
        for (it = mat_pat_ls.begin();
             it != mat_pat_ls.end(); ++it)
            fout_mat_pat << *it << endl;
    }
    else
    {
        std::cerr << "Could not open file \"matnpat.dat\" for output.\n";
        exit(EXIT_FAILURE);
    }

    cout << "\tMat and Pat have " << mat_pat_ls.size() << " friends.\n";

    fin_mat.close();
    fin_pat.close();
    fout_mat_pat.close();
    cout << "Hello World!" << endl;
    return 0;
}
void ShowData (const std::string & s)
{
    std::cout << s << "\n";
}
