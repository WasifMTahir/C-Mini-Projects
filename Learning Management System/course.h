#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include <fstream>
#include "user.h"
#include <vector>
using namespace std;

class course
{
    private:
        string courseName;
        string courseCode;
        string offeringSchool;
        int capacity;
        int students;
        string fame;
        string lame;
        string roll;
        string status;
        string password;
        string finstructors;
        string linstructors;
        string username;
        string studentNum[15];
        string fstudents[15];
        string lstudents[15];
        int marks[15];
        vector <string> resources;
        vector <string> assignments;
    public:
        course();
        virtual ~course();
        course(string n, string c, string o, int cap);
        string getcourseName();
        string getcourseCode();
        string getofferingSchool();
        int getcapacity();
        void setstudents(int s);
        int getstudents();
        void courseInfo(ifstream& in);
        string getinstructors();
        void getstudentsName();
        int checkCourse(ifstream& in, string use);
        int checkInstructor(ifstream& in, string use);
        string getpassword();
        string getusername();
        string getroll();
        string getstatus();
        int getMarks(int m);
        void setMarks(int s, int m);
        string getStudentNum(int i);
        void setStudentNum(int i, string u);
        void setAssignments(string a);
        void setResources(string r);
        void getAssignments();
        void getResources();
};

#endif // COURSE_H
