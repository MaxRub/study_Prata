#include "queue.h"
#include <cstdlib>

Queue::Queue(int qs) : q_size_(qs)
{
    front_ = rear_ = nullptr;
    items_ = 0;
}
Queue::~Queue()
{
    Node * temp;
    while (front_ != nullptr)
    {
        temp = front_;
        front_ = front_->next;
        delete temp;
    }
}
bool Queue::isempty() const
{
    return  items_ == 0;
}
bool Queue::isfull() const
{
    return items_ == q_size_;
}
int Queue::queuecount() const
{
    return items_;
}
bool Queue::enqueue(const Item & item)
{
    if(isfull())
        return false;
    Node * add = new Node;
    add->item = item;
    add->next = nullptr;
    items_++;
    if(front_ == nullptr)
        front_ = add;
    else
        rear_->next = add;
    rear_ = add;
    return true;
}
bool Queue::dequeue(Item &item)
{
    if(front_ == nullptr)
        return  false;
    item = front_->item;
    items_--;
    Node * temp = front_;
    front_ = front_->next;
    delete temp;
    if(items_ == 0)
        rear_ = nullptr;
    return true;
}
void Customer::set(long when)
{
    processtime_ = std::rand() % 3 + 1;
    arrive_ = when;
}
