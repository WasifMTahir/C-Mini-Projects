#include "student.h"

student::student()
{
    roll = "";
    status = "";
}
student::student(string r, string s)
{
    roll = r;
    status = s;
}
student::~student()
{
    //dtor
}
string student::getroll(){return roll;}
string student::getstatus(){return status;}
void student::setroll(string r){roll = r;}
void student::setstatus(string s){status = s;}

void student::populateUserData(ifstream& in)
{
    string r,s,f,l,u,p;
    in >> r >> s >> f >> l >> u >> p;
    setfame(f);
    setlame(l);
    setuserName(u);
    setpassword(p);
    roll = r;
    status = s;
}

void student::viewMarksTab(course*& cobj, int s, int m)
{
    cout << cobj->getMarks(m) << endl;
}
