#ifndef CD01_H
#define CD01_H
//Base class
class Cd {                      //present a cd
private:
    char * performers_;
    char * label_;
    int selections_;             //number of collections
    double playtime_;            //playback time in minutes
public:
    Cd(char * s1, char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd();
    virtual void Report() const;        //output all CD data
    Cd & operator=(const Cd & d);
};
#endif // CD01_H
