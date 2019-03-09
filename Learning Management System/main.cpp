#include <iostream>
#include <fstream>
#include "user.h"
#include "student.h"
#include "instructor.h"
#include "course.h"
using namespace std;
ostream& operator<<(ostream& out, user& a)
{
    out << a.getfame() << "\t" << a.getlame() << "\t" << a.getpassword() << "\t" << a.getuserName() << "\t";
    return out;
}
int main()
{
    string op,op1,use,pass,w,q,r,name;
    ifstream userlist, cor;
    int type;
    userlist.open("userList.txt");
    user* u[20];
    course* c[5];
    course finder;
    //finder = new course;
    for (int i=0; i<5; i++)
        c[i] = new course;
    for (int i=0; i<15; i++)
        u[i] = new student;
    for (int i=15; i<20; i++)
        u[i] = new instructor;
    for (int i=0; i<20; i++)
        u[i]->populateUserData(userlist);
    userlist.close();

    cor.open("Course1.txt");
    c[0]->setstudents(6);
    c[0]->courseInfo(cor);
    cor.close();
    cor.open("Course2.txt");
    c[1]->setstudents(10);
    c[1]->courseInfo(cor);
    cor.close();
    cor.open("Course3.txt");
    c[2]->setstudents(4);
    c[2]->courseInfo(cor);
    cor.close();
    cor.open("Course4.txt");
    c[3]->setstudents(10);
    c[3]->courseInfo(cor);
    cor.close();
    cor.open("Course5.txt");
    c[4]->setstudents(15);
    c[4]->courseInfo(cor);
    cor.close();
while (true)
{


    cout << "Press 1 to log in\nPress 2 to exit\nYour choice: ";
    cin >> op;
    while (op!="1" && op!="2")
    {
        cout << "Please enter a valid number\n";
        cout << "Press 1 to log in\nPress 2 to exit\nYour choice: ";
        cin >> op;
    }
    if (op=="1")
    {
        cout << "Enter username: ";
        cin >> use;
        cout << "Enter password: ";
        cin >> pass;
        for (int i=0; i<20; i++)
        {
            name = u[i]->getuserName();
            string pw = u[i]->getpassword();
            if (use==name && pass==pw)
            {
                type = i;
               if (type<15)
               {
                cout << "You are logged in as a Student\n";
                cout << "Your Courses:\n";
                cor.open("Course1.txt");
                finder.setstudents(6);
                finder.checkCourse(cor, name);
                cor.close();
                cor.open("Course2.txt");
                finder.setstudents(10);
                finder.checkCourse(cor, name);
                cor.close();
                cor.open("Course3.txt");
                finder.setstudents(4);
                finder.checkCourse(cor, name);
                cor.close();
                cor.open("Course4.txt");
                finder.setstudents(10);
                finder.checkCourse(cor, name);
                cor.close();
                cor.open("Course5.txt");
                finder.setstudents(15);
                finder.checkCourse(cor, name);
                cor.close();
               }
               else
               {
                cout << "You are logged in as an Instructor\nYour Courses:\n";
                cor.open("Course1.txt");
                finder.setstudents(6);
                finder.checkInstructor(cor, name);
                cor.close();
                cor.open("Course2.txt");
                finder.setstudents(10);
                finder.checkInstructor(cor, name);
                cor.close();
                cor.open("Course3.txt");
                finder.setstudents(4);
                finder.checkInstructor(cor, name);
                cor.close();
                cor.open("Course4.txt");
                finder.setstudents(10);
                finder.checkInstructor(cor, name);
                cor.close();
                cor.open("Course5.txt");
                finder.setstudents(15);
                finder.checkInstructor(cor, name);
                cor.close();
               }
            }
        }
    }
    if (type<15)
    {
        cout << "Enter the course code of course you want to choose: ";
        string code;
        cin >> code;
        int courseNum=0;
        for (int i=0; i<5; i++)
            {
                if (code==(c[i]->getcourseCode()))
                {
                    courseNum = i;
                }
            }
        cout << "Press 1 to view Marks\nPress 2 to view Resources\nPress 3 to view Assignments\n";
        cout << "Press 4 to view Roster\nPress 5 to log out\nYour choice: ";
        cin >> op1;
        while (op1!="1" && op1!="2" && op1!="3" && op1!="4" && op1!="5")
        {
            cout << "Please enter a valid number\n";
            cout << "Press 1 to view Marks\nPress 2 to view Resources\nPress 3 to view Assignments\n";
            cout << "Press 4 to view Roster\nPress 5 to log out\nYour choice: ";
            cin >> op1;
        }

        if (op1=="1")
        {
            for (int i=0; i<5; i++)
            {
                if (code==(c[i]->getcourseCode()))
                {
                    u[i]->viewMarksTab(c[i], 0, i);
                }
            }
        }
        else if (op=="2")
        {
            c[courseNum]->getResources();
        }
        else if (op=="3")
        {
            c[courseNum]->getAssignments();
        }
        else if (op=="4")
        {
            c[courseNum]->getstudentsName();
        }
        else if (op=="5")
            break;
    }

    else
    {
        cout << "Enter the course code of course you want to choose: ";
        string code;
        cin >> code;
        int courseNum=0;
        for (int i=0; i<5; i++)
            {
                if (code==(c[i]->getcourseCode()))
                {
                    courseNum = i;
                }
            }
        cout << "Press 1 to view Marks\nPress 2 to view Resources\nPress 3 to view Assignments\n";
        cout << "Press 4 to view Roster\nPress 5 to log out\nYour choice: ";
        cin >> op1;
        while (op1!="1" && op1!="2" && op1!="3" && op1!="4" && op1!="5")
        {
            cout << "Please enter a valid number\n";
            cout << "Press 1 to view Marks\nPress 2 to view Resources\nPress 3 to view Assignments\n";
            cout << "Press 4 to view Roster\nPress 5 to log out\nYour choice: ";
            cin >> op1;
        }
//while (op1!="5")
//{
        if (op1=="1")
        {
            for (int i=0; i<5; i++)
            {
                if (code==(c[i]->getcourseCode()))
                {
                    courseNum = i;
                    c[i]->getstudentsName();
                    int num, marks;
                    cout << "Press 1 to Add Marks\nPress 2 to continue\nYour choice: ";
                    string op2;
                    cin >> op2;
                    if (op2=="1")
                    {
                    cout << "Enter # of student to add marks: ";
                    cin >> num;
                    cout << "Enter marks for student #" << num << ": ";
                    cin >> marks;
                    u[16]->viewMarksTab(c[courseNum], num, marks);
                    cout << "Marks successfully updated\n";
                    }
                    else if (op2=="2")
                        break;
                    else
                        cout << "Should've entered a valid number :/\n";
                }
            }
        }
        else if (op1=="2")
        {
            c[courseNum]->getResources();
            cout << "Press 1 to add new Resource\nPress 2 to continue\nYour choice: ";
            string op2;
            cin >> op2;
            if(op2=="1")
            {
                cout << "Enter the new resource: ";
                string res;
                cin >> res;
                c[courseNum]->setResources(res);
                cout << "New resource successfully added\n";
            }
            else if (op2=="2")
                break;
            else
                cout << "Should've entered a valid number\n";
        }
        else if (op1=="3")
        {
            c[courseNum]->getAssignments();
            cout << "Press 1 to add new assignment\nPress 2 to continue\nYour choice: ";
            string op2;
            cin >> op2;
            if(op2=="1")
            {
                cout << "Enter the new assignment: ";
                string asg;
                cin >> asg;
                c[courseNum]->setAssignments(asg);
                cout << "New assignment successfully added\n";
            }
            else if (op2=="2")
                break;
            else
                cout << "Should've entered a valid number\n";
        }
        else if (op1=="4")
        {
            c[courseNum]->getstudentsName();
        }
        else if (op1=="5")
        {
            break;
        }
   // }
    }
}
    return 0;
}
