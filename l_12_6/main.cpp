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
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line1(qs), line2(qs);
    cout << "Enter the simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;
    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;
    Item temp;
    long turnaways = 0, turnaways1(0), turnaways2(0);
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time1(0), wait_time2(0);
    long line_wait(0);
    for(int cycle = 0;cycle < cyclelimit;cycle++)
    {
        if(newcustomer(min_per_cust))
        {
            if(line1.isfull())
                turnaways1++;
            else if(line2.isfull())
                turnaways2++;
            else
            {
                customers++;
                temp.set(cycle);
                if(line1.queuecount() <= line2.queuecount())
                {
                    line1.enqueue(temp);
                    //cout << "!! 1 !!\n";
                }
                else
                {
                    line2.enqueue(temp);
                    //cout << "\t!! 2 !!\n";
                }
            }
        }
        if(wait_time1 <= 0 && !line1.isempty())
        {
            line1.dequeue(temp);
            wait_time1 = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if(wait_time2 <= 0 && !line2.isempty())
        {
            line2.dequeue(temp);
            wait_time2 = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if(wait_time1 > 0)
            wait_time1--;
        if(wait_time2 > 0)
            wait_time2--;
        sum_line += line1.queuecount();
        sum_line += line2.queuecount();
    }
    turnaways = turnaways1 - turnaways2;
    if(customers > 0)
    {
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
    else
        cout << "No customers!\n";
    line1.~Queue();
    line2.~Queue();
    //
    //
    //
    do
    {
        perhour--;
        min_per_cust = MIN_PER_HR / perhour;
        Queue line1(qs), line2(qs);
        turnaways = turnaways1 = turnaways2 = 0;
        customers = 0;
        served = 0;
        sum_line = 0;
        wait_time1 = wait_time2 = 0;
        line_wait = 0;
        for(int cycle = 0;cycle < cyclelimit;cycle++)
        {
           /* turnaways = turnaways1 = turnaways2 = 0;
            customers = 0;
            served = 0;
            sum_line = 0;
            wait_time1 = wait_time2 = 0;
            line_wait = 0;*/
            if(newcustomer(min_per_cust))
            {
                if(line1.isfull())
                    turnaways1++;
                else if(line2.isfull())
                    turnaways2++;
                else
                {
                    customers++;
                    temp.set(cycle);
                    if(line1.queuecount() <= line2.queuecount())
                    {
                        line1.enqueue(temp);
                        //cout << "!! 1 !!\n";
                    }
                    else
                    {
                        line2.enqueue(temp);
                        //cout << "\t!! 2 !!\n";
                    }
                }
            }
            if(wait_time1 <= 0 && !line1.isempty())
            {
                line1.dequeue(temp);
                wait_time1 = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if(wait_time2 <= 0 && !line2.isempty())
            {
                line2.dequeue(temp);
                wait_time2 = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if(wait_time1 > 0)
                wait_time1--;
            if(wait_time2 > 0)
                wait_time2--;
            sum_line += line1.queuecount();
            sum_line += line2.queuecount();
        }
        turnaways = turnaways1 - turnaways2;
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
        line1.~Queue();
        line2.~Queue();
    }while((double) line_wait / served > 1.0 && (perhour > 0));
    cout << "Done!\n";
    return  0;
}
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
