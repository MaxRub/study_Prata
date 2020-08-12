#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
struct Review
{
    std::string title;
    int rating;
    double price;
};
bool operator<(const std::shared_ptr<Review> & r1,
               const std::shared_ptr<Review> & r2);
bool worseThen(const std::shared_ptr<Review> & r1,
               const std::shared_ptr<Review> & r2);
bool worsePrice(const std::shared_ptr<Review> & r1,
               const std::shared_ptr<Review> & r2);
bool FillReview(std::shared_ptr<Review> && rr,     //rvalue
                std::vector<std::shared_ptr<Review>> & vsp);
void ShowReview(const std::shared_ptr<Review> & rr);
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;
    using std::vector;
    using std::shared_ptr;

    vector<shared_ptr<Review>> books;

    while (FillReview(shared_ptr<Review>(new Review), books))
        continue;

    if (books.size() > 0)
    {
        vector<shared_ptr<Review>> books_sort_title(books);
        vector<shared_ptr<Review>> books_sort_rating(books);
        vector<shared_ptr<Review>> books_sort_price(books);

        sort(books_sort_title.begin(), books_sort_title.end());
        sort(books_sort_rating.begin(), books_sort_rating.end(),
             worseThen);
        sort(books_sort_price.begin(), books_sort_price.end(),
             worsePrice);

        cout << "Thank you. You entered the following "
             << books.size() << " ratings!\n"
             << "Display boks:\na. initial order.\t"
             << "b. in alphabetical order.\n"
             << "c. in ascending order of rating.\t"
             << "d. in ascending order of price.\n"
             << "e. in descending order of price.\t"
             << "q. quit.\n";

        char choice;
        while(cin >> choice && choice != 'q')
        {
            switch (choice)
            {
            case 'a':
            case 'A': cout << "Rating\t Book\n";
                      for_each(books.begin(), books.end(),
                               ShowReview);
                      break;
            case 'b':
            case 'B': cout << "Sorting by title:\nRating\tBook\n";
                      for_each(books_sort_title.begin(),
                      books_sort_title.end(), ShowReview);
                      break;
            case 'c':
            case 'C': cout << "Sorting by rating:\nRating\tBook\n";
                      for_each(books_sort_rating.begin(),
                      books_sort_rating.end(), ShowReview);
                      break;
            case 'd':
            case 'D': cout << "Sorting by price up:\nRating\tBook\n";
                      for_each(books_sort_price.begin(),
                      books_sort_price.end(), ShowReview);
                      break;
            case 'e':
            case 'E': cout << "Sorting by price down:\nRating\tBook\n";
                      for_each(books_sort_price.rbegin(),
                      books_sort_price.rend(), ShowReview);
                      break;
            default: cout << "That's not a choice.\n";
            }
            cout << "Display boks:\na. initial order.\t"
                 << "b. in alphabetical order.\n"
                 << "c. in ascending order of rating.\t"
                 << "d. in ascending order of price.\n"
                 << "e. in descending order of price.\t"
                 << "q. quit.\n";
        }
    }
    else
        cout << "No entries. ";
    cout << "Hello World!" << endl;
    return 0;
}
bool operator<(const std::shared_ptr<Review> & r1,
               const std::shared_ptr<Review> & r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else if (r1->title == r2->title && r1->rating == r2->rating
             && r1->price < r2->price)
        return true;
    else
        return false;
}
bool worseThen(const std::shared_ptr<Review> & r1,
               const std::shared_ptr<Review> & r2)
{
    if (r1->rating < r2->rating)
        return true;
    else if (r1->rating == r2->rating && r1->price < r2->price)
        return true;
    else
        return false;
}
bool worsePrice(const std::shared_ptr<Review> & r1,
               const std::shared_ptr<Review> & r2)
{
    if (r1->price < r2->price)
        return true;
    else
        return false;
}
bool FillReview(std::shared_ptr<Review> && rr,
                std::vector<std::shared_ptr<Review>> & vsp)
{
    using std::cout;
    using std::cin;

    cout << "Enter book title (quit to quit): ";
    std::getline(cin, rr->title);
    if (rr->title == "quit")
        return false;
    cout << "Enter book rating: ";
    cin >> rr->rating;
    if (!cin)
        return false;
    cout << "Enter book price: ";
    cin >> rr->price;
    if (!cin)
        return false;
    while(cin.get() != '\n')
        continue;
    vsp.push_back(rr);      //initialization data for vector
    return true;
}
void ShowReview(const std::shared_ptr<Review> & rr)
{
    std::cout << rr->rating << "\t" << rr->title
              << "\t" << rr->price << std::endl;
}
