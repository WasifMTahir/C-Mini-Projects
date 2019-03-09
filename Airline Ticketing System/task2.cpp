#include<iostream>

using namespace std;

void login(string grid[][8], string roll[][8], string students[][2]);
void logoff(string grid[][8], string roll[][8]);
void reset(string grid[][8], string roll[][8], string students[][2], string request[][2]);
void message(string grid[][8], string roll[][8], string students[][2], string request[][2]);
void arrangement(string grid[][8]);
void trace(string grid[][8], string roll[][8], string students[][2]);
void viewreq(string grid[][8], string roll[][8], string students[][2], string request[][2]);
void change(string grid[][8], string roll[][8], string students[][2], string request[][2]);
int mode(int choice, string grid[][8], string roll[][8], string students[][2], string request[][2]);


int main()
{
    string grid[4][8];
    string pass[4][8];
    string roll[4][8];
    string request[10][2];
    for (int i=0;i<4;i++)
    {   for (int j=0;j<8;j++)
        {
            grid[i][j]="*";
            pass[i][j]="*";
            roll[i][j]="*";
        }

    }
    cout << "\t";
    for (int q=0;q<8;q++)
    {
        cout << "Col[" << q+1 << "]\t";
    }
    cout << "\n\n";
    for (int p=0;p<4;p++)
    {
        cout << "Row[" << p+1 << "]\t";
        for (int o=0;o<8;o++)
        {
            cout << grid[p][o] << "\t";
        }
        cout << endl;
    }
    string students[10][2];
    students[0][0]="19100001";
    students[0][1]="abc123";
    students[1][0]="19100002";
    students[1][1]="abc456";
    students[2][0]="19100003";
    students[2][1]="abc789";
    students[3][0]="19100004";
    students[3][1]="def123";
    students[4][0]="19100005";
    students[4][1]="def456";
    students[5][0]="19100006";
    students[5][1]="def789";
    students[6][0]="19100007";
    students[6][1]="xyz123";
    students[7][0]="19100008";
    students[7][1]="xyz456";
    students[8][0]="19100009";
    students[8][1]="xyz789";
    students[9][0]="19100010";
    students[9][1]="xyz123";
    for (int i=0;i<10;i++)
    {
        request[i][0]="*";
        request[i][1]="*";
    }

    int choice = 1;

    while (choice!=-1)
    {
    cout << "Press 1 to log in to a computer\nPress 2 to log off from a computer\n";
    cout << "Press 3 to request for password reset\nPress 4 to view message from Helpdesk\n";
    cout << "Press 5 to view Lab seating arrangement\nPress 6 to switch mode\nPress -1 to exit\n\nEnter your choice: ";
    cin >> choice;
    if (choice == -1)
        return 0;
    else if (choice == 1)
        login(grid,roll,students);
    else if (choice == 2)
        logoff(grid,roll);
    else if (choice == 3)
        reset(grid,roll,students,request);
    else if (choice == 4)
        message(grid,roll,students,request);
    else if (choice == 5)
        arrangement(grid);
    else if (choice == 6)
        mode(choice,grid,roll,students,request);
    else
        cout << "Please enter a valid input";
    }
    return 0;
}

void login(string grid[][8], string roll[][8], string students[][2])
{
    int row,col,test=0,test1=0;
    string rol,pass;
    cout << "Enter your Roll number: ";
    cin >> rol;
    cout << "Enter your password: ";
    cin >> pass;
    cout << "Enter Row Number: ";
    cin >> row;
    cout << "Enter Column Number: ";
    cin >> col;

    for (int i=0; i<4; i++)
    {
        for (int j=0; j<8; j++)
        if (roll[i][j]==rol)
        {
            cout << "You can't login to multiple computers at the same time!\n";
            break;
        }
        else
            test++;
    }
    if (test==32)
    {
    for (int i=0; i<10; i++)
    {
        if (students[i][0]==rol && students[i][1]==pass)
        {
            grid[row-1][col-1]="o";
            roll[row-1][col-1]=rol;
            cout << "You have successfully logged into computer #" << (row-1)*8+col;
            break;
        }
        else
            test1++;
    }
        if (test1==10)
        {
            cout << "ERROR!! Incorrect Credentials!";
        }

    cout << "\n\t";
    for (int q=0;q<8;q++)
    {
        cout << "Col[" << q+1 << "]\t";
    }
    cout << "\n\n";
    for (int p=0;p<4;p++)
    {
        cout << "Row[" << p+1 << "]\t";
        for (int o=0;o<8;o++)
        {
            cout << grid[p][o] << "\t";
        }
        cout << endl;
    }
    }
}


void logoff(string grid[][8], string roll[][8])
{
    string roll2;
    int test=0;
    cout << "Please Enter your Roll No.: ";
    cin >> roll2;
    for (int i=0; i<4; i++)
    {
        for (int j=0;j<8;j++)
        {
            if (roll[i][j]==roll2)
            {
                grid[i][j]="*";
                cout << "You have successfully been logged off";
            }
            else
                test++;
        }
    }
    if (test==32)
    {
        cout << "You cant logoff unless you've logged in first";
    }
    cout << "\n\n";
}

void reset(string grid[][8], string roll[][8], string students[][2], string request[][2])
{
    string roll2;
    int test=0,test1=0;
    cout << "Please Enter your Roll No.: ";
    cin >> roll2;
    for (int i=0; i<4; i++)
    {
        for (int j=0;j<8;j++)
        {
            if (roll[i][j]==roll2)
            {
                cout << "You can't request a password change while logged in\n";
            }
            else
                test++;
        }
    }
    if (test==32)
    {
        for (int i=0;i<10;i++)
        {
            if (students[i][0]==roll2 && request[i][0]=="o")
            {
                cout << "You already have a pending request!";
                break;
            }
            else if (students[i][0]==roll2)
            {
                request[i][0]="o";
                cout << "You have successfully requested a password reset\n";
            }
            else
                test1++;
        }
        if (test1==10)
        cout << "ERROR!! Unregistered Roll Number!\n";
    }

}

void message(string grid[][8], string roll[][8], string students[][2], string request[][2])
{
    string roll2;
    int test=0,test1=0;
    cout << "Please Enter your Roll No.: ";
    cin >> roll2;
    for (int i=0;i<10;i++)
        {
            if (students[i][0]==roll2 && request[i][1]=="o")
            {
                cout << "You have no new messages!\n";
                break;
            }
            else if (students[i][0]==roll2)
            {
                request[i][1]="o";
                cout << "Dear " << roll2 << ", Thank you for contacting IST Helpdesk.\n";
                cout << "It is our top priority to resolve your issue in the most timely manner.\n";
            }
            else
                test1++;
        }
        if (test==10)
            cout << "ERROR!! Unregistered Roll Number!\n";
}


void arrangement(string grid[][8])
{
    for (int q=0;q<8;q++)
    {
        cout << "Col[" << q+1 << "]\t";
    }
    cout << "\n\n";
    for (int p=0;p<4;p++)
    {
        cout << "Row[" << p+1 << "]\t";
        for (int o=0;o<8;o++)
        {
            cout << grid[p][o] << "\t";
        }
        cout << endl;
    }
}

int mode(int choice, string grid[][8], string roll[][8], string students[][2], string request[][2])
{
    int choice1=1;

    while (choice1!=-1)
    {
    cout << "**********Admin Mode**********\n";
    cout << "Press 1 to trace a student\nPress 2 to view password change requests\n";
    cout << "Press 3 to change password for a student\nPress 4 to view Lab seating arrangement\n";
    cout << "Press 5 to switch mode\nPress -1 to exit\n\nEnter your choice: ";
    cin >> choice1;
    if (choice1 == -1)
        return 0;
    else if (choice1 == 1)
        trace(grid,roll,students);
    else if (choice1 == 2)
        viewreq(grid,roll,students,request);
    else if (choice1 == 3)
        change(grid,roll,students,request);
    else if (choice1 == 4)
        arrangement(grid);
    else if (choice1 == 5)
        return choice;
    else
        cout << "Please enter a valid input";
    }
}

void trace(string grid[][8], string roll[][8], string students[][2])
{
    string rol;
    int test=0;
    cout << "Enter Roll No. of student: ";
    cin >> rol;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (roll[i][j]==rol)
            {
                cout << "Student Roll No.: " << rol;
                cout << "\nComputer No. :  " << i*8+j+1;
                cout << "\nRow No.:        " << i+1;
                cout << "\nColumn No.:     " << j+1 << endl;
            }
            else
                test++;
        }
    }
    if (test==32)
        cout << "There is no student with Roll no. " << rol << " logged in!\n";
}


void viewreq(string grid[][8], string roll[][8], string students[][2], string request[][2])
{
    cout << "Following students have requested for password change:\n";
    for (int i=0;i<10;i++)
    {
        if (request[i][0]=="o")
        {
            cout << students[i][0] << endl;
        }
    }
}


void change(string grid[][8], string roll[][8], string students[][2], string request[][2])
{
    string rol,pas;
    int val,test=0;
    cout << "Enter Roll No. of student: ";
    cin >> rol;
    for (int i=0;i<10;i++)
    {
        if (request[i][0]=="o" && students[i][0]==rol)
        {
            val=i;
            break;
        }
        else
            test++;
    }
    if (test==10)
    {
        cout << "Wrong Roll. No entered!";
        return;
    }
    cout << "Enter new password: ";
    cin >> pas;
    students[val][1]=pas;
    cout << "Password Changed Successfully!!\n";
    request[val][0]="*";
    request[val][1]="Your password has been reset. Your new password is: " + pas + "\n";
}
