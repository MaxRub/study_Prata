#include <iostream>
#include <string>
#include <cctype>
bool isPalindrom(std::string & str);
bool checking(std::string & str);
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;
    cout << "Enter the text (quit to quit): ";
    string input;
    while(getline(cin, input) && input != "quit")
    {
        if(!checking(input))
                continue;
        else if (isPalindrom(input))
            cout << "Ok!!! It is Palindrom!!!" << endl;
        else
            cout << "It is not!" << endl;
    }
    cout << "Hello World!" << endl;
    return 0;
}
bool checking(std::string & str)
{
    for(int i =0; i < str.size(); i++)
    {
        if(isupper(str[i]) || ispunct(str[i]) || isspace(str[i]))
        {
            std::cout << str[i] << " Error!!!" << std::endl;
            std::cout << "Enter the text (quit to quit): ";
            return false;
        }
    }
    return true;
}
bool isPalindrom(std::string & str)
{
    using std::string;
    int i, j;
    string temp = str;
    for(i = 0, j = str.size() - 1; i < j; i++, j--)
    {
        str[i] = str[j];
    }
    if(temp == str)
        return true;
    else
        return false;
}
