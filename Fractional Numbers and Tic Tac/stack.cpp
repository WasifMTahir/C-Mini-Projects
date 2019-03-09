#include "stack.h"
#include <iostream>

using namespace std;

stack::stack()
{
    list = new operation[0];
    size = 0;
}

stack::~stack()
{
    delete[] list;
}

stack::stack(const stack& stock)
{
    list = new operation[stock.size];
    for (int i=0; i<(stock.size); i++)
    {
        *(list+i) = *(stock.list+i);
    }
    size = stock.size;
}

void stack::print()
{
    if (size==0)
        cout << "No operations have been performed\n";
    else
    {
        for (int i=0; i<size+1; i++)
            cout << "OPERATION #" << i+1 << endl << *(list+i) << endl;
    }
}

void stack::push(operation& obj)
{
    operation *dynamic;
    dynamic = new operation[size+1];
    for (int i=0; i<size; i++)
    {
        *(dynamic+i) = *(list+i);
    }
    delete[] list;
    list = dynamic;
    dynamic = NULL;
    *(list+size) = obj;
    size++;
}

void stack::pop()
{
    if (size==0)
        cout << "There is no operation to pop\n";
    else
    {
        operation *dynamic;
        dynamic = new operation[size-1];
        for (int i=0; i<=size; i++)
        {
            *(dynamic+i) = *(list+i);
        }
        delete[] list;
        list = dynamic;
        //dynamic = NULL;
        size--;
        cout << "Last operation successfully popped\n";
    }
}

void stack::setSize(int sz)
{
    size = sz;
}

int stack::getSize()
{
    return size;
}

