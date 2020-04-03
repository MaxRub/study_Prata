#ifndef PERSON_H
#define PERSON_H
#include <string>
class Person
{
private:
    std::string first_name;
    std::string last_name;
protected:
    void Data() const;
    void Get();
public:
    Person() : first_name("no one"), last_name("nobody") {}
    Person(const std::string  & sf, const std::string & sl)
        : first_name(sf), last_name(sl) {}
    virtual ~Person();
    virtual void Show() const;
    virtual void Set();
};
//
class Gunslinger: virtual public Person
{
private:
    int notching;
    double ready_time;
protected:
    void Data() const;
    void Get();
public:
    Gunslinger() : Person(), notching(0), ready_time(1.0) {}
    Gunslinger(const std::string  & sf, const std::string & sl,
               int n, double rt) : Person(sf, sl), notching(n),
               ready_time(rt) {}
    Gunslinger(const Person & p, int n, double rt)
        : Person(p), notching(n), ready_time(rt) {}
    ~Gunslinger() {}
    double Drow() const { return ready_time; }
    virtual void Show() const;
    virtual void Set();
};
//
class PokerPlayer: virtual public Person
{
protected:
     void Data() const;
public:
    PokerPlayer() : Person() {}
    PokerPlayer(const std::string  & sf, const std::string & sl)
        : Person(sf, sl) {}
    PokerPlayer(const Person & p ) : Person(p) {}
    int Drow() const { return rand() % 52 + 1; }
    virtual void Show() const;
    virtual void Set();
    ~PokerPlayer() {}
};
class BadDude: public Gunslinger,  public PokerPlayer
{
public:
    BadDude() {}
    BadDude(const std::string  & sf, const std::string & sl,
            int n, double rt) : Person(sf, sl),
            Gunslinger(sf, sl, n, rt), PokerPlayer(sf, sl) {}
    BadDude(const Person & p, int n, double rt)
        : Person(p), Gunslinger(p, n, rt), PokerPlayer(p) {}
    BadDude(const Gunslinger & g ) : Person(g), Gunslinger(g),
        PokerPlayer(g) {}
    BadDude(const PokerPlayer & pp, int n, double rt)
        : Person(pp), Gunslinger(pp, n, rt), PokerPlayer(pp) {}
    double Gdrow() const { return Gunslinger::Drow(); }
    int CDrow() const { return PokerPlayer::Drow();}
    virtual void  Show() const;
    void  Set();
    ~BadDude() {}
};
#endif // PERSON_H
