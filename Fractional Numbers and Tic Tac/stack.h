#ifndef STACK_H
#define STACK_H
#include<iostream>
#include "operation.h"

using namespace std;

class stack
{
    private:
        operation *list;
        int size;
    public:
        stack();
        stack(operation obj, int sz);
        ~stack();
        stack(const stack& other);
        void push(operation& obj);
        void pop();
        void print();
        void setSize(int sz);
        int getSize();
};

#endif // STACK_H
