#ifndef PAIR_H
#define PAIR_H
template <class T1, class T2>
class Pair
{
private:
    T1 a_;
    T2 b_;
public:
    T1 & first();
    T2 & second();
    T1 first() const { return a_; }
    T2 second() const { return b_; }
    Pair(const T1 & aval, const T2 & bval) : a_(aval), b_(bval) {}
    Pair() {}
};
template <class T1, class T2>
T1 & Pair<T1,T2>::first()
{
    return a_;
}
template <class T1, class T2>
T2 & Pair<T1,T2>::second()
{
    return b_;
}
#endif // PAIR_H
