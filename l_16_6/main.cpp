#include <iostream>
#include <queue>
#include <cstdlib>      //for rand() and srand()
#include <ctime>        //for time()
class Customer
{
private:
    long arrive;        //the moment when the client appeared
    int processtime;    //customer service time
public:
    Customer() { arrive = processtime = 0; }
    void set (long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};
void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}

const int MIN_PER_HR = 60;

bool newcustomer(double x);    //is there a new customer

int main()
{
    using std::cout;
    using std::endl;
    using std::cin;
    using std::ios_base;
    using std::queue;

    //preparation
    std::srand(std::time(0));
    cout <<"Case Study: Dank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    unsigned qs;
    cin >> qs;
    queue<Customer> line;
    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;

    //the emulation will run one cycle per minute
    long cyclelimit = MIN_PER_HR * hours;
    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;    //the average time between the appearance
    min_per_cust = MIN_PER_HR/perhour;
    Customer temp;          //data of new client
    long turnaways = 0;     //non-admission in full
    long customers = 0;     //added to the queue
    long served = 0;        //serviced during emulation
    long sum_line = 0;      //the total length of the queue
    int wait_time = 0;      //time to release the ATM
    long line_wait = 0;     //total time in the queue

    //start modeling
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))      //is the customer
        {
            if(line.size() == qs)       //
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);        //cycle - arrival time
                line.push(temp);        //adding a newbie to the queue
            }
        }
        if (wait_time <=0 && !line.empty())
        {
            temp = line.front();        //next customer service
            wait_time = temp.ptime();   //during wait_time minutes
            line_wait += cycle - temp.when();
            served++;
            line.pop();
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.size();
    }

    //output of the results
    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "    turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait time: "
             << (double) line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";

    cout << "Hello World!" << endl;
    return 0;
}
//  x = average time, in minutes, between customers
//  return true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
