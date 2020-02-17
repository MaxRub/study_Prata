#ifndef COW_H
#define COW_H
class Cow
{
private:
    char name_[20];
    char * hobby_;
    double weight_;
public:
    Cow();
    Cow(const char * nm, const char * ho, double wt);
    Cow(const Cow & c);
    ~Cow();
    Cow & operator=(const Cow & c);
    void  ShowCow() const;
};

#endif // COW_H
