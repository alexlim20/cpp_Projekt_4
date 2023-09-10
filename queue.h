class QueueElement;
class Queue
{
public:
    QueueElement* FirstElement;
    QueueElement* LastElement;
    int count;
    Queue();
    Queue(QueueElement* IntitialElement);
    QueueElement* getFirstElement();
    QueueElement* getLastElement();
    void push(QueueElement* Newitem);
    void pop();
    void insert(QueueElement* Newitem, unsigned Position);
    bool isEmpty();
    void clear();
    unsigned size();
    void print();

    ~Queue();
};
