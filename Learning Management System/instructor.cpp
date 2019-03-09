#include "instructor.h"

instructor::instructor()
{
    designation = "";
    qualification = "";
}
instructor::instructor(string d, string q)
{
    designation = d;
    qualification = q;
}
instructor::~instructor()
{
    //dtor
}
string instructor::getdesignation(){return designation;}
string instructor::getqualification(){return qualification;}
void instructor::setdesignation(string d){designation = d;}
void instructor::setqualification(string q){qualification = q;}

void instructor::populateUserData(ifstream& in)
{
    string d,q,f,l,u,p;
    in >> d >> q >> f >> l >> u >> p;
    setfame(f);
    setlame(l);
    setuserName(u);
    setpassword(p);
    designation = d;
    qualification = q;
}

void instructor::viewMarksTab(course*& cobj, int s, int m)
{
    cobj->setMarks(s, m);
}
