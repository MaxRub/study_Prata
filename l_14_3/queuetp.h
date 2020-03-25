#ifndef QUEUETP_H
#define QUEUETP_H
template <class Type>
class QueueTp
{
private:
    //Node - nested structure local to this class
    struct Node {Type item; struct Node * next; };
    enum { Q_SIZE = 10};
    //closed class members
    Node * front;       //pointer to the beginning
    Node * rear;        //pointer to the end
    int items;          //the current number of items
    const int qsize;    //the maximum number of items
    //warning ad to prevent open copy
    QueueTp(const QueueTp & q) : qsize(0) {}
    QueueTp & operator=(const QueueTp & q) { return *this; }
public:
    QueueTp(int qs = Q_SIZE); //create queue with maximum size
    ~QueueTp();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Type & item);  //adding items to the end
    bool dequeue(Type & item);        //deleting items from
                                      //the beginning
};
template <class Type>
QueueTp<Type>::QueueTp(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}
template <class Type>
QueueTp<Type>::~QueueTp()
{
    Node * temp;
    while (front != nullptr)  //until the queue is empty
    {
        temp = front;         //savingthe address of the
                              //starting element
        front = front->next;  //moving the pointer to the
                              //next element
        delete temp;          //deleting the previous starting
                              //element
    }
}
template <class Type>
bool QueueTp<Type>::isempty() const
{
    return items == 0;
}
template <class Type>
bool QueueTp<Type>::isfull() const
{
    return items == qsize;
}
template <class Type>
int QueueTp<Type>::queuecount() const
{
    return items;
}
template <class Type>
bool QueueTp<Type>::enqueue(const Type & item)
{
    if (isfull())
        return false;
    Node * add = new Node;      //creating a node
    add->item = item;           //pointing to nodes
    add->next = nullptr;
    items++;
    if (front == nullptr)       //if the queue is empty
        front = add;            //element is brought to the
                                //beginning
    else
        rear->next = add;       //element is brought to the end
    rear = add;                 //the end pointer points
                                //to a new element
    return true;
}
template <class Type>
bool QueueTp<Type>::dequeue(Type & item)
{
    if (front == nullptr)
        return false;
    item = front->item;         //the first item in the
                                //queue is entered in the item
    items--;
    Node * temp = front;        //saving the location
                                //of the first item
    front = front->next;        //move the start pointer
                                //to the next item
    delete temp;                //delete the previous first item
    if (items == 0)
        rear = nullptr;
    return true;
}
#endif // QUEUETP_H
