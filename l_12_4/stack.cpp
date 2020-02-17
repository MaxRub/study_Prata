#include "stack.h"
Stack::Stack(int n)
{
    pitems_ = new Item[MAX_];
    size_ = n;
    top_ = n - 1;
}
Stack::Stack(const Stack & st)
{
    pitems_ = new Item[MAX_];
    for (int i = 0; i < st.size_; i++)
        pitems_[i] = st.pitems_[i];
    size_ = st.size_;
    top_ = st.top_;
}
Stack::~Stack()
{
    delete [] pitems_;
}
bool Stack::isempty() const
{
    return  top_ == 0;
}
bool Stack::isfull() const
{
    return  top_ == MAX_;
}
bool Stack::push(const Item & item)
{
    if(top_ < MAX_)
    {
        pitems_[top_++] = item;
        size_++;
        return true;
    }
    else
        return false;
}
bool Stack::pop(Item & item)
{
    if(top_ > 0)
    {
        item = pitems_[--top_];
        size_--;
        return true;
    }
    else
        return false;
}
Stack & Stack::operator=(const Stack & st)
{
    if(this == & st)
        return *this;
    delete [] pitems_;
    pitems_ = new Item[MAX_];
    for (int i = 0; i < st.size_; i++)
        pitems_[i] = st.pitems_[i];
    size_ = st.size_;
    top_ = st.top_;
    return *this;
}
