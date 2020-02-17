#ifndef QUEUE_H
#define QUEUE_H
class Customer
{
private:
    long arrive_;
    int processtime_;
public:
    Customer() { arrive_ = processtime_ = 0;}
    void set(long when);
    long when() const { return  arrive_;}
    int ptime() const { return processtime_;}
};
typedef Customer Item;
class Queue
{
private:
    struct Node { Item item; struct Node * next;};
    enum {Q_SIZE = 10};

    Node * front_;
    Node * rear_;
    int items_;
    const int q_size_;
    Queue(const Queue & q) : q_size_(0){}
    Queue & operator=(const Queue & q) {return *this;}
public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item & item);
    bool dequeue(Item &item);
};

#endif // QUEUE_H
