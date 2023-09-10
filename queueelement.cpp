#include "string.h"
#include <iostream>
#include "queueelement.h"

QueueElement::QueueElement()
:Label{'\0'}
{
    Previous = nullptr;
    Next = nullptr;
    X = 0;
    Y = 0;
    Z = 0;
}

QueueElement::QueueElement(const char* Label, int X, int Y, int Z)
{
    if(strlen(Label)<LABELSIZE)
    {
        strcpy(this->Label, Label);
    }else
    {
        strncpy(this->Label, Label, LABELSIZE);
        this->Label[LABELSIZE-1] = '\0';
    }
    this->X = X;
    this->Y = Y;
    this->Z = Z;
    Previous = nullptr;
    Next = nullptr;
}

QueueElement::QueueElement(const char* Label, int X, int Y, int Z, QueueElement* Previous, QueueElement* Next)
{
    if(strlen(Label)<LABELSIZE)
    {
        strcpy(this->Label, Label);
    }else
    {
        strncpy(this->Label, Label, LABELSIZE);
        this->Label[LABELSIZE-1] = '\0';
    }
    this->X = X;
    this->Y = Y;
    this->Z = Z;
    this->Previous = Previous;
    this->Next = Next;
}

void QueueElement::print()
{
    std::cout << "QueueElement: " << "'" << Label << "' (" << X << ", " << Y << ", " << Z << ")" << '\n';

}

QueueElement* QueueElement::getNext()
{
    return Next;
}

QueueElement* QueueElement::getPrevious()
{
    return Previous;
}
