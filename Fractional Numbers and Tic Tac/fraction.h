#ifndef FRACTION_H
#define FRACTION_H
#include<iostream>
using namespace std;


class fraction
{
    private:
        int *numerator;
        int *denominator;

    public:
        fraction();
        fraction(int num, int denom);
        fraction(const fraction& frac);
        ~fraction();
        int hcf(int num, int den);
        void setNum(int num);
        int getNum();
        void setDen(int den);
        int getDen();
        fraction operator+(const fraction& frac1);
        fraction operator-(const fraction& frac1);
        fraction operator*(const fraction& frac1);
        fraction operator/(const fraction& frac1);
        friend ostream& operator << (ostream& print,fraction&frac3);
        friend istream& operator >> (istream& in, fraction& frac3);
        fraction& operator=(const fraction& frac2);
        bool operator==(const fraction& frac2);
        fraction operator++();
        fraction& operator++(const int fazool);
        fraction operator--();
        fraction& operator--(const int fazool);



};

#endif //FRACTION_H
