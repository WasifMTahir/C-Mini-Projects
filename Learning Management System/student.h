#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<fstream>
#include "user.h"
#include "course.h"
using namespace std;

class student : public user
{
    private:
        string roll;
        string status;
    public:
        student();
        student(string r, string s);
        virtual ~student();
        string getroll();
        string getstatus();
        void setroll(string r);
        void setstatus(string s);
        void populateUserData(ifstream& in);
        void viewMarksTab(course*& cobj, int s, int m);
};

#endif // STUDENT_H
