#include<iostream>
#include<string>
#include<stdlib.h>
#include<sstream>

using namespace std;

void reserve(string grid[10][4], string name[10][4], string roll[10][4]);
void cancel(string grid[10][4], string name[10][4], string roll[10][4]);
void change(string grid[10][4], string name[10][4], string roll[10][4]);
void plan(string grid[10][4]);
void seekhelp(string grid[10][4], string name[10][4], string roll[10][4]);



int main()
{
    int choice=1;
    string grid[10][4];
    string name[10][4];
    string roll[10][4];
    for (int i=0;i<10;i++)
    {   for (int j=0;j<4;j++)
        {
            grid[i][j]="*";
            name[i][j]="*";
            roll[i][j]="*";
        }

    }

    while (choice!=-1)
    {
        cout << "Press 1 to reserve a seat\nPress 2 to cancel your seat\nPress 3 to change your seat\n";
        cout << "Press 4 to view seating plan\nPress 5 to seek help\nPress -1 to exit\n\nEnter your choice: ";
        cin >> choice;
        if (choice == -1)
            return 0;
        else if (choice == 1)
        reserve(grid,name,roll);
        else if (choice == 2)
        cancel(grid,name,roll);
        else if (choice == 3)
        change(grid,name,roll);
        else if (choice == 4)
        plan(grid);
        else if (choice == 5)
        seekhelp(grid,name,roll);
    }

    return 0;
}





void reserve(string grid[10][4], string name[10][4], string roll[10][4])
{
    char clas;
    string name1,roll1;
    cout << "Enter B for Business class or E for Economy class: ";
    cin >> clas;
    cout << "Please Enter your Name: ";
    cin >> name1;
    cout << "Please Enter your Roll No.: ";
    cin >> roll1;
    string row;
    int col,row2;
    cout << "Enter Row No.: ";
    cin >> row;
    string row1 = row.substr (1,1);
    stringstream convert;
    convert.str(row1);
    convert >> row2;
    cout << "Enter Column No.: ";
    cin >> col;
    grid[row2-1][col-1]="o";
    name[row2-1][col-1]=name1;
    roll[row2-1][col-1]=roll1;

    cout << "            ";

    if (clas=='B' || clas=='b')
    {
    for (int q=0;q<4;q++)
    {
        cout << "Column[" << q+1 << "]\t";
    }
    cout << endl;
    for (int p=0;p<3;p++)
    {
        cout << "A[" << p+1 << "]\t\t";
        for (int o=0;o<4;o++)
        {
            cout << grid[p][o] << "\t\t";
        }
        cout << endl;
    }
    }
    else if (clas=='E' || clas=='e')
    {
        for (int q=0;q<4;q++)
    {
        cout << "Column[" << q+1 << "]\t";
    }
    cout << endl;
    for (int p=3;p<10;p++)
    {
        cout << "B[" << p+1 << "]\t\t";
        for (int o=0;o<4;o++)
        {
            cout << grid[p][o] << "\t\t";
        }
        cout << "\n";
    }
    }
    cout << "\nDear " << name1 << ", seat " << row2 << "." << col << " has been reserved for you\n";
}


void cancel(string grid[10][4], string name[10][4], string roll[10][4])
{
    string roll2,name1;
    int row3,col3;
    cout << "Please enter your name: ";
    cin >> name1;
    cout << "Please Enter your Roll No.: ";
    cin >> roll2;
    for (int i=0; i<10; i++)
    {
        for (int j=0;j<4;j++)
        {
            if (roll[i][j]==roll2)
            {
                grid[i][j]="*";
                cout << "Your seat " << i+1 << "." << j+1 <<" has successfully been cancelled";
            }
            /*else
                cout << "There is no seat reserved with this Name & Roll no.";*/

        }
    }
    cout << "\n\n";
}

void seekhelp(string grid[10][4], string name[10][4], string roll[10][4])
{
    string roll2,name1;
    int row3,col3;
    cout << "Please enter your name: ";
    cin >> name1;
    cout << "Please Enter your Roll No.: ";
    cin >> roll2;
    for (int i=0; i<10; i++)
    {
        for (int j=0;j<4;j++)
        {
            if (roll[i][j]==roll2)
            {
                cout << "The seat " << i+1 << "." << j+1 <<" is booked on your name";
            }
        }
    }
    cout << "\n\n";
}

void plan(string grid[10][4])
{
    cout << "\t\t";
    for (int q=0;q<4;q++)
    {
        cout << "Column[" << q+1 << "]\t";
    }
    cout << endl;
    for (int p=0;p<3;p++)
    {
        cout << "A[" << p+1 << "]\t\t";
        for (int o=0;o<4;o++)
        {
            cout << grid[p][o] << "\t\t";
        }
        cout << endl;
    }
    /*for (int q=0;q<4;q++)
    {
        cout << "Column[" << q+1 << "]\t";
    }
    cout << endl;*/
    for (int p=3;p<10;p++)
    {
        cout << "B[" << p+1 << "]\t\t";
        for (int o=0;o<4;o++)
        {
            cout << grid[p][o] << "\t\t";
        }
        cout << "\n";
    }
}


void change(string grid[10][4], string name[10][4], string roll[10][4])
{
    string roll2,name1;
    int row3,col3;
    cout << "Please enter your name: ";
    cin >> name1;
    cout << "Please Enter your Roll No.: ";
    cin >> roll2;
    for (int i=0; i<10; i++)
    {
        for (int j=0;j<4;j++)
        {
            if (roll[i][j]==roll2)
            {
                grid[i][j]="*";
            }
        }
    }

    cout << "\n\n";

    string row;
    int col,row2;
    cout << "Enter Row No.: ";
    cin >> row;
    string row1 = row.substr (1,1);
    string clas = row.substr (0,1);
    stringstream convert;
    convert.str(row1);
    convert >> row2;
    cout << "Enter Column No.: ";
    cin >> col;
    grid[row2-1][col-1]="o";
    name[row2-1][col-1]=name1;
    roll[row2-1][col-1]=roll2;

    cout << "            ";

    if (clas=="A" || clas=="a")
    {
    for (int q=0;q<4;q++)
    {
        cout << "Column[" << q+1 << "]\t";
    }
    cout << endl;
    for (int p=0;p<3;p++)
    {
        cout << "A[" << p+1 << "]\t\t";
        for (int o=0;o<4;o++)
        {
            cout << grid[p][o] << "\t\t";
        }
        cout << endl;
    }
    }
    else if (clas=="B" || clas=="b")
    {
        for (int q=0;q<4;q++)
    {
        cout << "Column[" << q+1 << "]\t";
    }
    cout << endl;
    for (int p=3;p<10;p++)
    {
        cout << "B[" << p+1 << "]\t\t";
        for (int o=0;o<4;o++)
        {
            cout << grid[p][o] << "\t\t";
        }
        cout << "\n";
    }
    }
    else
    {
        cout << "Enter a valid Row number";
    }
    cout << "\nDear " << name1 << ", seat " << row2 << "." << col << " has been reserved for you\n";
}

