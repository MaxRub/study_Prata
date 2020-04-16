#include <iostream>
#include "tv.h"
bool Tv::vollup()
{
    if(volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}
bool Tv::voldown()
{
    if(volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}
void Tv::chanup()
{
    if(channel < maxchannel)
        channel++;
    else
        channel = 1;
}
void Tv::chandown()
{
    if(channel > 1)
        channel--;
    else
        channel = maxchannel;
}
void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off? "Off" : "On") << endl;
                                                // On or Off
    if(state == On)
    {
        cout << "Volume srtting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
             << (mode == Antenna? "antenna" : "cable") << endl;
        cout << "Input = "
             << (input == TV? "TV" : "DVD") << endl;
    }
}
bool Tv::set_regim(Remote & rr)
{
    if(state == On)
    {
        rr.regime = (rr.regime == rr.Normal)? rr.Interactive : rr.Normal;
        return true;
    }
    else
        return false;
}
void Remote::show_regim()
{
    std::cout << "Remote regim = "
              << (regime == Normal ? "Normal" : "Interactive")
              << std::endl;
}
