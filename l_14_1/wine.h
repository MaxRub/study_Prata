#ifndef WINE_H
#define WINE_H
#include <string>
#include <valarray>
#include "pair.h"
class Wine
{
private:
    typedef std::valarray<int> ArrayInt;
    typedef Pair<ArrayInt, ArrayInt> PairArray;
    std::string label_;
    PairArray info_;
    int years_;
 public:
    Wine(const char * l, int y, const int yr[], const int bot[]);
    Wine(const char * l, int y);
    ~Wine();
    void Show() const;
    void GetBottles();
    const std::string & Label() const { return label_; }
    int sum() const;

};

#endif // WINE_H
