#include "queue.h"
#include "queueelement.h"
#include <iostream>

Queue::Queue() : FirstElement(nullptr), LastElement(nullptr), count(0) {}

Queue::Queue(QueueElement* InitialElement) :FirstElement(InitialElement), LastElement(nullptr){}

QueueElement* Queue::getFirstElement()
{
    return FirstElement;
}

QueueElement* Queue::getLastElement()
{
    return LastElement;
}

unsigned Queue::size()
{
    return count;
}

bool Queue::isEmpty()
{
    if(size() == 0)
    {
        return 1;
    }else
    {
        return 0;
    }
}

void Queue::print()
{
    std::cout << "Queue: " << '\n';
    std::cout << "<<>" << '\n';
    QueueElement* tempElement = FirstElement;
    if(tempElement != nullptr)
    {
        int i=0;
        do
        {
            std::cout << "<<" << i << ": ";
            tempElement->print();
            tempElement = tempElement->getNext();
            i++;
        }while(tempElement != nullptr);
    }else
    {

    }
    std::cout << "<<!" << '\n';
}

void Queue::push(QueueElement* NewItem)
{
    if(size()==0)
    {
        FirstElement = NewItem;
        LastElement = NewItem;
    }else
    {
        QueueElement* temp = FirstElement;
        FirstElement = NewItem;
        FirstElement->Next = temp;
        FirstElement->Next->Previous = FirstElement;
    }
    count++;
}

void Queue::pop()
{
    if(FirstElement == LastElement)
    {
        FirstElement = nullptr;
        LastElement = nullptr;
    }else
    {
        LastElement = LastElement->Previous;
        LastElement->Next = nullptr;
    }
    count--;
}

void Queue::clear()
{
    for(int i =size()-1 ; i>=0; i--)
    {
        pop();
    }
}

Queue::~Queue(){}

void Queue::insert(QueueElement* NewItem, unsigned Position)
{
    if(FirstElement==nullptr && LastElement==nullptr)
    {
        push(NewItem);
    }else if(Position <=size()-1)
    {
        if(Position==0)
        {
            QueueElement* temp = FirstElement;
            FirstElement = NewItem;
            FirstElement->Next = temp;
            FirstElement->Next->Previous = FirstElement;
        }else
        {
            QueueElement* temp1 = FirstElement;
            QueueElement* temp2;
            int i;
            while(i<Position)
            {
                temp1 = temp1->getNext();
                temp2 = temp1->getPrevious();
                i++;
            }
            NewItem->Next = temp1;
            NewItem->Next->Previous = temp1;
            temp2->Next = NewItem;
            temp2->Next->Previous = temp2;
        }
    }
    else
    {
        QueueElement* temp3 = LastElement;
        LastElement = NewItem;
        LastElement->Previous = temp3;
        LastElement->Previous->Next = LastElement;
    }
}
