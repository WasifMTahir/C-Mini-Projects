#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include<iostream>
#include<fstream>
#include "user.h"
#include "course.h"
using namespace std;

class instructor : public user
{
    private:
        string designation;
        string qualification;
    public:
        instructor();
        instructor(string d, string q);
        virtual ~instructor();
        string getdesignation();
        string getqualification();
        void setdesignation(string d);
        void setqualification(string q);
        void populateUserData(ifstream& in);
        void viewMarksTab(course*& cobj, int s, int m);
};

#endif // INSTRUCTOR_H
