#ifndef USER_H
#define USER_H
#include<iostream>
using namespace std;
class course;

class user
{
    private:
        string fame;
        string lame;
        string password;
        string userName;
    public:
        user();
        user(string f, string l, string p, string u);
        virtual ~user();
        string getfame();
        string getlame();
        string getpassword();
        string getuserName();
        void setfame(string f);
        void setlame(string l);
        void setuserName(string u);
        void setpassword(string p);
        virtual void populateUserData(ifstream& in){}
        virtual void viewMarksTab(course*& cobj, int s, int m){}
};

#endif // USER_H
