#include "operation.h"
//#include "fraction.h"
using namespace std;

operation::operation()
{
    operands = new fraction[2];
    (*operands).setNum(0);
    (*operands).setDen(1);
    (*(operands+1)).setNum(0);
    (*(operands+1)).setDen(1);
    result.setNum(0);
    result.setDen(1);
    symbol="";
    operandCount=0;
    //cout << "eksjgnemw\n";
}
operation::operation(fraction frac1, fraction frac2, fraction res, string sym, int num)
{
    operands = new fraction[num];
    *operands = frac1;
    *(operands+1) = frac2;
    result = res;
    symbol = sym;
    operandCount = num;
}
operation::~operation()
{
    delete[] operands;
    //cout << "Deleted\n";
}
operation::operation(const operation& other)
{
    //copy ctor
}
void operation::operator=(const operation& obj)
{
    *operands = *(obj.operands);
    *(operands+1) = *(obj.operands+1);
    result = obj.result;
    operandCount = obj.operandCount;
    symbol = obj.symbol;
}


void operation::setSymbol(string sym)
{
    symbol = sym;
}
string operation::getSymbol()
{
    return symbol;
}
void operation::setCount(int num)
{
    operandCount = num;
}
int operation::getCount()
{
    return operandCount;
}
void operation::setResult(fraction res)
{
    result = res;
}
fraction operation::getResult()
{
    return result;
}
void operation::setOperand(fraction frac1, fraction frac2)
{
    *operands = frac1;
    *(operands+1) = frac2;
}

fraction* operation::getOperand()
{
    return operands;
}




istream& operator >> (istream& in, operation& obj)
{
    fraction frac1, frac2;
    if (obj.operandCount==1)
    {
        cout << "For 1st fraction:\n";
        in >> frac1;
        *(obj.operands) = frac1;
        obj.operandCount = 1;
    }
    if (obj.operandCount==2)
    {
        cout << "For 1st fraction:\n";
        in >> frac1;
        cout << "For 2nd fraction:\n";
        in >> frac2;
        *(obj.operands) = frac1;
        *((obj.operands)+1) = frac2;
        obj.operandCount = 2;
    }
    if (obj.getSymbol() == "+")
        obj.setResult(frac1+frac2);

    else if (obj.getSymbol() == "-")
        obj.setResult(frac2-frac1);

    else if (obj.getSymbol() == "*")
        obj.setResult(frac1*frac2);

    else if (obj.getSymbol() == "/")
        obj.setResult(frac2/frac1);

    else if (obj.getSymbol() == "==")
    {
        fraction yes;
        yes.setNum(1);
        yes.setDen(1);
        fraction no;
        no.setNum(0);
        no.setDen(0);
        if (frac1==frac2)
        {
            cout << "Yup they're euqal\n";
            obj.setResult(yes);
        }
        else
        {
            cout << "Nah they're not equal\n";
            obj.setResult(no);
        }

    }

    else if(obj.getSymbol() == "++PRE")
        obj.setResult((frac1++));

    else if(obj.getSymbol() == "POST++")
        obj.setResult((++frac1));

    else if(obj.getSymbol() == "--PRE")
        obj.setResult((frac1--));

    else if(obj.getSymbol() == "POST++")
        obj.setResult((--frac1));
}

ostream& operator << (ostream& print,operation& obj)
{
    int num;
    num = obj.getCount();
    if (num==1)
    {
        print << "Operator: " << obj.symbol << endl;
        print << "Operand: " << *(obj.operands) << endl;
        print << "Result: " << obj.result << endl;
    }
    else if (num==2)
    {
        print << "Operator: " << obj.symbol << endl;
        print << "Operand 1: " << *(obj.operands) << endl;
        print << "Operand 2: " << *(obj.operands+1) << endl;
        print << "Result: " << obj.result << endl;
    }
    return print;
}
