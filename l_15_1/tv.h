#ifndef TV_H
#define TV_H
class Remote;
class Tv
{
    friend class Remote;
public:
    enum {Off, On};
    enum {MinVal, MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};

    Tv(int s = Off, int mc = 125) : state(s), volume(5),
        maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() {state = (state == On)? Off : On; }
    bool ison() const {return state == On;}
    bool vollup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() {mode = (mode == Antenna)? Cable : Antenna; }
    void set_input() {input = (input == TV)? DVD : TV; }
    void settings() const;      //display all settings
    bool set_regim(Remote & rr);
private:
    int state;                  //On or Off
    int volume;                 //discrete volume levels
    int maxchannel;             //maximum number of channels
    int channel;                //current channel
    int mode;                   //terrestrial or cable television
    int input;                  //TV or DVD
};

class Remote
{
    friend class Tv;
private:
    int mode;                   //control TV or DVD
    int regime;                 //remote control mode
public:
    enum {Normal, Interactive};
    Remote(int m = Tv::TV) : mode(m), regime(Normal) {}
    void show_regim();
    bool volup(Tv & t) {return t.vollup(); }
    bool voldown(Tv & t) {return t.voldown(); }
    void onoff(Tv & t) { t.onoff(); }
    void chanup(Tv & t) { t.chanup(); }
    void chandown(Tv & t) { t.chandown(); }
    void set_chan(Tv & t, int c) { t.channel = c; }
    void set_mode(Tv & t) { t.set_mode(); }
    void set_input(Tv & t) { t.set_input(); }
};
#endif // TV_H
