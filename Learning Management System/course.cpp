#include "course.h"

course::course()
{
    for (int i=0; i<15; i++)
    studentNum[i]="h";
}

course::~course()
{
    //dtor
}
course::course(string n, string c, string o, int cap)
{
    courseName = n;
    courseCode = c;
    offeringSchool = o;
    capacity = cap;
}
string course::getpassword(){return password;}
string course::getroll(){return roll;}
string course::getstatus(){return status;}


string course::getcourseName(){return courseName;}
string course::getcourseCode(){return courseCode;}
string course::getofferingSchool(){return offeringSchool;}
int course::getcapacity(){return capacity;}
void course::setstudents(int a){students = a;}
int course::getstudents(){return students;}
string course::getinstructors(){return finstructors;}
string course::getusername(){return username;}
int course::getMarks(int m){return marks[m];}
void course::setMarks(int s, int m){marks[s]=m;}
string course::getStudentNum(int i){for (int j=0; j<15; j++){cout << studentNum[j] << endl;} return studentNum[i];}
void course::setStudentNum(int i, string u){studentNum[i] = u;}
int course::checkCourse(ifstream& in, string use)
{
    string s,r,d,q,f,l,u,p,m,n,b,v;
    in >> m >> n >> b >> v;
    for (int i=0; i<(getstudents()); i++)
    {
        in >> r >> s >> f >> l >> u >> p;
        if (use==u)
        {
            cout << n << "  " << m << endl;
            setStudentNum(i, p);
            return 1;
        }
    }
    in >> r >> s;
    return 0;
}
int course::checkInstructor(ifstream& in, string use)
{
    string s,r,d,q,f,l,u,p,m,n,b,v;
    in >> m >> n >> b >> v;
    for (int i=0; i<(getstudents()); i++)
        in >> r >> s >> f >> l >> u >> p;

    in >> r >> s >> f >> l >> u >> p;
    if (use==u)
        {
            cout << n << "  " << m << endl;
            return 1;
        }
    return 0;
}
void course::getstudentsName()
{
    for (int i=0; i<getstudents(); i++)
    {cout << "#" << i << "- " << fstudents[i] << " " << lstudents[i] << endl;}
}
void course::courseInfo(ifstream& in)
{
    in >> courseName >> courseCode >> offeringSchool >> capacity;
    for (int i=0; i<(getstudents()); i++)
    {
        in >> roll >> status >> fame >> lame >> username >> password;
        fstudents[i] = fame;
        lstudents[i] = lame;
    }
    in >> finstructors >> linstructors;
}

void course::getResources()
{
   for(int i=0; i<resources.size(); i++)
       cout << resources[i] << endl;
}
void course::setResources(string r)
{
   resources.push_back(r);
}
void course::getAssignments()
{
   for(int i=0; i<assignments.size(); i++)
       cout << assignments[i] << endl;
}
void course::setAssignments(string a)
{
   assignments.push_back(a);
}
