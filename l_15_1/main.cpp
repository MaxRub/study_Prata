#include <iostream>
#include "tv.h"

int main()
{
    using std::cout;
    using std::endl;
    Tv s42;
    cout << "Initial setting for 42\" TV:\n";
    s42.settings();
    Remote grey;
    s42.set_regim(grey);
    grey.show_regim();

    s42.onoff();
    s42.chanup();
    cout << "\nAdjusted settings for 42\" TV:\n";
    s42.settings();
    s42.set_regim(grey);
    grey.show_regim();
    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    cout << "\n42\" settings after using remote:\n";
    s42.settings();
    s42.set_regim(grey);
    grey.show_regim();
    cout << "Hello World!" << endl;
    return 0;
}
