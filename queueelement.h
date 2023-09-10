#ifndef PROTECTOR_STRING
#define PROTECTOR_STRING
const unsigned LABELSIZE = 42;

class QueueElement
{
public:
    QueueElement* Previous;
    QueueElement* Next;
    char Label[LABELSIZE];
    int X;
    int Y;
    int Z;

    QueueElement();
    QueueElement(const char* Label, int X, int Y, int Z);
    QueueElement(const char* Label, int X, int Y, int Z, QueueElement* Previous, QueueElement* Next);
    void print();
    QueueElement* getNext();
    QueueElement* getPrevious();

};

#endif

