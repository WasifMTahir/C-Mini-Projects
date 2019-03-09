#ifndef OPERATION_H
#define OPERATION_H
#include<iostream>
#include<fstream>
#include "fraction.h"
using namespace std;



class operation
{
    private:
        fraction *operands;
        fraction result;
        int operandCount;
        string symbol;
    public:
        operation();
        operation(int num, int denom);
        operation(const operation& other);
        ~operation();

        void setSymbol(string symbol);
        string getSymbol();
        void setCount(int num);
        int getCount();
        void setOperand(fraction frac1, fraction frac2);
        fraction* getOperand();
        void setResult(fraction res);
        fraction getResult();

        operation(fraction frac1, fraction frac2, fraction res, string sym, int num);

        friend ostream& operator << (ostream& print, operation& obj);
        friend istream& operator >> (istream& in, operation& obj);
        void operator=(const operation& obj);

};

//ostream& operator << (ostream& print, operation& obj);
//istream& operator >> (istream& in, operation& obj);
#endif //OPERATION_H
