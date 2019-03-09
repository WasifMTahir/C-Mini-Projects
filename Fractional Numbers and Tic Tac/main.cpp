#include<iostream>
#include<fstream>
#include "fraction.h"
#include "operation.h"
#include "stack.h"
using namespace std;

ostream& operator << (ostream& print, fraction& frac3)
{
    print << *(frac3.numerator) << "/" << *(frac3.denominator) << endl;
    return print;
}

istream& operator >> (istream& in, fraction& frac3)
{
    cout << "Enter numerator: ";
    in >> *(frac3.numerator);
    cout << "Enter denominator: ";
    in >>*(frac3.denominator);
    return in;
}





int main()
{
    int op=0;
    fraction frac1;
    fraction frac2;
    fraction frac3;
    operation obj;
    stack stock;
while (op>-1 && op<12)
{
    cout << "Press 1 to add two fractional number\n";
    cout << "Press 2 to subtract two fractional number\n";
    cout << "Press 3 to multiply two fractional number\n";
    cout << "Press 4 to divide two fractional number\n";
    cout << "Press 5 to compare two fractional number\n";
    cout << "Press 6 to pre-increment a fractional number\n";
    cout << "Press 7 to post-increment a fractional number\n";
    cout << "Press 8 to pre-decrement a fractional number\n";
    cout << "Press 9 to post-decrement a fractional number\n";
    cout << "Press 10 to pop last operation from stack\n";
    cout << "Press 11 to print stack\n\n";
    cout << "Your Choice: ";


    cin >> op;

    if (op>0 && op<6)
        obj.setCount(2);
    else if (op>5 && op<10)
        obj.setCount(1);
    else if (op<0 || op>11)
    {
        cout << "Please enter a valid option :)\n";
        break;
    }
    if (op==1)
        obj.setSymbol("+");
    else if (op==2)
        obj.setSymbol("-");
    else if (op==3)
        obj.setSymbol("*");
    else if (op==4)
        obj.setSymbol("/");
    else if (op==5)
        obj.setSymbol("==");
    else if (op==6)
        obj.setSymbol("++PRE");
    else if (op==7)
        obj.setSymbol("POST++");
    else if (op==8)
        obj.setSymbol("--PRE");
    else if (op==9)
        obj.setSymbol("POST--");
    if (op>0 && op<10)
    {
        cin >> obj;
        cout << obj;
        stock.push(obj);
    }
    else if (op==10)
    {
        stock.pop();
    }
    else if (op==11)
    {
        stock.print();
    }
}
    return 0;
}
