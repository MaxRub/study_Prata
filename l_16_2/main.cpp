#include <iostream>
#include <string>
#include <cctype>
#include <iterator>
#include <algorithm>
bool isPalindrome(std::string & str);
int main()
{
    using std::string;
    using std::cout;
    using std::cin;
    using std::endl;
    string input;
    cout << "Enter the text (quit to quit): ";
    while(getline(cin, input) && input != "quit")
    {
        if(isPalindrome(input))
            cout << "It is palindrome!!!" << endl;
        else
            cout << "It is not!!" << endl;
    }
    cout << "Hello World!" << endl;
    return 0;
}
bool isPalindrome(std::string & str)
{
    using std::string;
    string temp;
    //make all letters lowercase
    for(int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);
    //we leave only letters and numbers
    for(int i = 0; i < str.size(); i++)
        if(isalnum(str[i]))
            temp += str[i];
    str = temp;
    //copy the range in reverse order to another range
    std::reverse_copy(str.begin(), str.end(), temp.begin());
    //std::cout << str << std::endl;
    //std::cout << temp << std::endl;
    if(str == temp)
        return true;
    else
        return false;
}
