#ifndef WINE_H
#define WINE_H
#include <string>
#include <valarray>
#include "pair.h"
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine: private PairArray, private std::string
{
private:
    int years_;
 public:
    Wine(const char * l, int y, const int yr[], const int bot[]);
    Wine(const char * l, int y);
    ~Wine();
    void Show() const;
    void GetBottles();
    const std::string & Label() const;
    int sum() const;

};

#endif // WINE_H
