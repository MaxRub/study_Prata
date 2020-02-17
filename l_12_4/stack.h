#ifndef STACK_H
#define STACK_H
typedef unsigned long Item;

class Stack
{
private:
    enum {MAX_ = 10};
    Item * pitems_;
    int size_;
    int top_;
public:
    Stack(int n = 10);
    Stack(const Stack & st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
    Stack & operator=(const Stack & st);
};

#endif // STACK_H
