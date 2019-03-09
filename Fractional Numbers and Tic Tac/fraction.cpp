#include "fraction.h"
using namespace std;

fraction::fraction()
{
    numerator = new int;
    denominator = new int;
    *numerator=0;
    *denominator=1;
    //cout<<"created\n";
}

fraction::fraction(int num, int denom)
{
    *numerator=num;
    *denominator=denom;
    //cout<<"created321\n";
}

fraction::fraction(const fraction& frac)
{
    numerator = new int;
    denominator = new int;
    *numerator = *frac.numerator;
    *denominator = *frac.denominator;
}

fraction::~fraction()
{
    //cout << "deleted\n";
    delete numerator;
    delete denominator;
}

int fraction::hcf(int num, int den)
{
    int hcf;
    if (den==0)
        return 1;
    if (num==0)
        return 1;
    if (num<0)
        num=-num;
    if (den<0)
        den=-den;
    for (int i=1; i<num+1; i++)
    {
        if (num%i==0 && den%i==0)
            hcf=i;
    }
    return hcf;
}

fraction fraction::operator+(const fraction& frac1)
{
    int n1 = *(frac1.numerator);
    int d1 = *(frac1.denominator);
    int n2 = *numerator;
    int d2 = *denominator;
    cout << "Operand:";
    int numer = (n1*d2)+(n2*d1);
    int denom = d1*d2;
    int hc;
    hc = hcf(numer,denom);
    numer /= hc;
    denom /= hc;
    fraction frac3;
    *(frac3.numerator)=numer;
    *(frac3.denominator)=denom;
    return frac3;
}

fraction fraction::operator-(const fraction& frac1)
{
    int n1 = *(frac1.numerator);
    int d1 = *(frac1.denominator);
    int n2 = *numerator;
    int d2 = *denominator;
    int numer = (n1*d2)-(n2*d1);
    int denom = d1*d2;
    int hc = hcf(numer,denom);
    numer /= hc;
    denom /= hc;
    fraction frac3;
    *(frac3.numerator)=numer;
    *(frac3.denominator)=denom;
    return frac3;
}

fraction fraction::operator*(const fraction& frac1)
{
    int n1 = *(frac1.numerator);
    int d1 = *(frac1.denominator);
    int n2 = *numerator;
    int d2 = *denominator;
    int numer = n1*n2;
    int denom = d1*d2;
    int hc = hcf(numer,denom);
    numer /= hc;
    denom /= hc;
    fraction frac3;
    *(frac3.numerator)=numer;
    *(frac3.denominator)=denom;
    return frac3;
}

fraction fraction::operator/(const fraction& frac1)
{
    int n1 = *(frac1.numerator);
    int d1 = *(frac1.denominator);
    int n2 = *numerator;
    int d2 = *denominator;
    int numer = n1*d2;
    int denom = d1*n2;
    int hc = hcf(numer,denom);
    numer /= hc;
    denom /= hc;
    fraction frac3;
    *(frac3.numerator)=numer;
    *(frac3.denominator)=denom;
    return frac3;
}

fraction& fraction::operator=(const fraction& frac2)
{
    *numerator = *(frac2.numerator);
    *denominator = *(frac2.denominator);
    /*fraction frac3;
    (frac3.numerator)=*numerator;
    *(frac3.denominator)=*denominator;
    return frac3;*/
}

bool fraction::operator==(const fraction& frac2)
{
    int n1 = *(frac2.numerator);
    int d1 = *(frac2.denominator);
    int n2 = *numerator;
    int d2 = *denominator;
    int hcf1=hcf(n1,d1);
    int hcf2=hcf(n2,d2);
    n1/=hcf1;
    d1/=hcf1;
    n2/=hcf2;
    d2/=hcf2;
    if ((n1 == n2) && (d1 == d2))
    {
        //cout << "Yes " << *numerator << "/" << *denominator << " is equal to " << *(frac2.numerator) << "/" << *(frac2.denominator) << "!!\n";
        return true;
    }
    //cout << "Nope they ain't equal bruh\n";
    return false;
}

fraction fraction::operator++()
{
    fraction frac1;
    *(frac1.numerator)=*numerator;
    *(frac1.denominator)=*denominator;
    *numerator=*numerator+*denominator;
    return frac1;
}

fraction& fraction::operator++(const int fazool)
{
    ++*this;
    return *this;
}

fraction fraction::operator--()
{
    fraction frac1;
    *(frac1.numerator)=*numerator;
    *(frac1.denominator)=*denominator;
    *numerator=*numerator-*denominator;
    return frac1;
}

fraction& fraction::operator--(const int fazool)
{
    --*this;
    return *this;
}

void fraction::setNum(int num)
{
    *numerator = num;
}
int fraction::getNum()
{
    return *numerator;
}
void fraction::setDen(int den)
{
    *denominator = den;
}
int fraction::getDen()
{
    return *denominator;
}
