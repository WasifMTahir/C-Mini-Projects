#include "user.h"
#include "course.h"
user::user()
{
    fame = "";
    lame = "";
    password = "";
    userName = "";
}
user::user(string f, string l, string p, string u)
{
    fame = f;
    lame = l;
    password = p;
    userName = u;
}
user::~user()
{
    //dtor
}
string user::getfame(){return fame;}
string user::getlame(){return lame;}
string user::getpassword(){return password;}
string user::getuserName(){return userName;}
void user::setfame(string f){fame = f;}
void user::setlame(string l){lame = l;}
void user::setuserName(string u){userName = u;}
void user::setpassword(string p){password = p;}

