#include <iostream>
#include "queue.h"
#include <cstdlib>
#include <ctime>
const int MIN_PER_HR = 60;
bool newcustomer(double x);

int main ()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    std::srand(std::time(0));
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    int hours = 100;
    long cyclelimit = MIN_PER_HR * hours;
    double perhour = 60;
    double min_per_cust;
    Item temp;
    long turnaways;
    long customers;
    long served;
    long sum_line;
    int wait_time;
    long line_wait;
    //int i = 60;
    do
    {
        perhour--;//++; //= i--;
        min_per_cust = MIN_PER_HR / perhour;
        Queue line;//(hours * perhour);
        turnaways = 0;
        customers = 0;
        served = 0;
        sum_line = 0;
        wait_time = 0;
        line_wait = 0;
        for(int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if(newcustomer(min_per_cust))
            {
                if(line.isfull())
                    turnaways++;
                else
                {
                    customers++;
                    temp.set(cycle);
                    line.enqueue(temp);
                }
            }
            if(wait_time <= 0 && !line.isempty())
            {
                line.dequeue(temp);
                wait_time = temp.ptime();
                line_wait += cycle - temp.when();
                //cout << cycle - temp.when() << endl;
                served++;
            }
            if(wait_time > 0)
                wait_time--;
            sum_line += line.queuecount();
        }
        if((double) line_wait / served <= 1.0)
        {
            cout << "\t line #: " << perhour << endl;
            cout << "customers accepted: " << customers << endl;
            cout << " customers served: " << served << endl;
            cout << " turnaways: " << turnaways << endl;
            cout << "avarage queue size: ";
            cout.precision(2);
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout << (double) sum_line / cyclelimit << endl;
            cout << " avarage wait time: "
                 << (double) line_wait / served << " minutes\n";
        }
        line.~Queue();
    }while((double) line_wait / served > 1.0);
    cout << "Done!\n";
    return  0;
}
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
