#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <vector>
#include <fstream>
using std::string;

int main()
{
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;
    using std::vector;
    using std::ifstream;
    std::srand(std::time(0));
    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);
    ifstream fin;
    while(play == 'y')
    {
        vector<string> wordlist;
        fin.open("wordlist");
        if (fin.is_open() == false)
        {
            std::cerr << "Can't open file. Bye. \n";
            exit (EXIT_FAILURE);
        }
        string temp;
        while(fin >> temp)
            //read the words from the file one by one
        {
            wordlist.push_back(temp);
            //copy the words from the file
        }
        string target = wordlist[std::rand() % wordlist.size()];
            //use size() to determine the length of the word list
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secret word. It has " << length
             << " letters, and you guess\n"
             << "one letter at a time. You get " << guesses
             << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;
        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos
                || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. Try again.\n";
                continue;
            }
            int loc = target.find(letter);
            if(loc == string::npos)
            {
                cout << "Oh, bad quess!\n";
                --guesses;
                badchars += letter;
            }
            else
            {
                cout << "Good guess!\n";
                attempt[loc] = letter;;

                loc = target.find(letter, loc + 1);
                while (loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }
            cout << "Your world: " << attempt << endl;
            if (attempt != target)
            {
                if(badchars.length() > 0)
                cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left\n";
            }
        }
        if (guesses > 0)
            cout << "That's right!\n";
        else
            cout << "Sorry, the word is " << target << ".\n";
        cout << "Will you play another? <y/n> ";
        cin >> play;
        play = tolower(play);
    }
    fin.close();
    cout << "Hello World!" << endl;
    return 0;
}
