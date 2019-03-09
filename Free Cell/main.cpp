#include <iostream>
#include <time.h>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <iomanip>
using namespace std;

typedef string* ptr;
int strint(string str);
string intstr(int val);
void randomtableau(string totalcards[],int tableaumatrix[]);
void grid(string* home[],int homematrix[],string* tableau[], int tableaumatrix[], string free[]);
void coltocol(string* tableau[], int tableaumatrix[], int &freecell);
void coltofree(string* tableau[], int tableaumatrix[], string free[], int &freecell);
void coltohome(string* tableau[], int tableaumatrix[], string home[], int &freecell);
void freetohome(string free[], string home[], int &freecell)
void save(string* tableau[], int tableaumatrix[], string home[], int &freecell, string free[]);

int main()
{
    int game,choice;
    int homematrix[4]={0,0,0,0};
    string hometemp[4];
    string free[4];
    int tableaumatrix[8]={7,7,7,7,6,6,6,6};
    //string tableautemp[8];
    int deck=13;
    int tilesno=7;
    int freecell=4;
     string *t1=new string[7];
    string *t2=new string[7];
    string *t3=new string[7];
    string *t4=new string[7];
    string *t5=new string[6];
    string *t6=new string[6];
    string *t7=new string[6];
    string *t8=new string[6];
    string *tableau[8]={t1,t2,t3,t4,t5,t6,t7,t8};
    string totalcards[52]={};
    randomtableau(totalcards,tableaumatrix);
    for(int i=0;i<7;i++)
    {
        t1[i]=totalcards[i];
        t2[i]=totalcards[i+7];
        t3[i]=totalcards[i+14];
        t4[i]=totalcards[i+21];
    }
    for(int i=0;i<6;i++)
    {
        t5[i]=totalcards[i+28];
        t6[i]=totalcards[i+34];
        t7[i]=totalcards[i+40];
        t8[i]=totalcards[i+46];
    }
    ptr *home=new ptr[deck];
    //string *tableau[8];

    for (int i=0;i<deck;i++)
        *(home+i)=new string[4];
    cout << "****This is Free Cell Game****\n";
    cout << "Press 1 to start a new game\nPress 2 to resume a saved game\n";
    cin >> game;
    if (game==1)
    {

        while (choice!=6)
{


            grid(home,homematrix,tableau,tableaumatrix,free);
    cout << "Press 1 for column to column move"<<endl;
    cout << "Press 2 for column to free cell move"<<endl;
    cout << "Press 3 for column to home move\n";
    cout << "Press 4 for free to home\n";
    cout << "Press 5 for to column\n";
    cout << "Press 6 to save: ";

    cin >> choice;
    if (choice==1)
        coltocol(tableau,tableaumatrix,freecell);
    else if (choice==2)
        coltofree(tableau,tableaumatrix,free,freecell);
    else if (choice==3)
        coltofree(tableau,tableaumatrix,free,freecell);
    else if (choice==4)
        freetohome(free,home,freecell)
    /*else if (choice==5)

    else if (choice==6)*/

        //grid(home,homematrix,tableau,tableaumatrix,free);

}
    }

return 0;
}


void randomtableau(string totalcards[52],int tableaumatrix[8])
{
    srand(time(NULL));

    string free[4]={"","","",""};


    string cards[13]={"A","K","Q","J","1","9","8","7","6","5","4","3","2"};
    string colour[52]={};
    string deck[4]={"S", "C", "H", "D"};
    int n=0,i;
    for (i=0; i<4; i++)
    {
        for (int j=1; j<14; j++)
        {
            if (j==11)
                totalcards[n]="J"+deck[i];
            else if (j==12)
                totalcards[n]="Q"+deck[i];
            else if (j==13)
                totalcards[n]="K"+deck[i];
            else if (j==1)
                totalcards[n]="A"+deck[i];
            else
            totalcards[n]=intstr(j)+deck[i];
            n++;
        }
    }

    for (i=0; i<52; i++)
    {
        if (totalcards[i][1]=='D'||totalcards[i][1]=='H')
            colour[i]="R";
        else if (totalcards[i][1]=='C'||totalcards[i][1]=='S')
            colour[i]="B";
            cout << totalcards[i];
    }
    for (i=0; i<52; i++)
    {
        totalcards[i]=totalcards[i]+colour[i];
    }

    string first,sec,c;
    int one,two,j;
    int num1=0;
    for (i=0;i<n*n;i++)
    {
        one=rand()%52;
        two=rand()%52;
        c=totalcards[one];
        totalcards[one]=totalcards[two];
        totalcards[two]=c;
    }

}

void grid(string* home[],int homematrix[], string* tableau[], int tableaumatrix[], string free[])
{
    int col=tableaumatrix[0];
    int homies=homematrix[0];
    int i,j;
    for (i=0; i<8; i++)
    {
        if (tableaumatrix[i]>col)
            col=tableaumatrix[i];
    }
    for (i=0; i<4; i++)
    {
        if (homematrix[i]<homies)
            homies=homematrix[i];
    }
    cout <<"\t\t****THIS IS FREE CELL GAME****\n";
    for (i=0; i<8; i++)
    {
        cout << setw(8) << left << "|  |";
    }
    cout << "\n";
    for (i=0; i<4; i++)
    {
        if (free[i]!="")
            cout << setw(8) << left << "|"+free[i]+"|";
        else
            cout<<"\t";
    }
    cout << "\n";
    for (i=0; i<homies; i++)
    {
        for (j=0; j<4; j++)
        {
            cout << setw(8) << left << "|"+home[i][j]+"|";
        }
        cout << "\t";
    }
    cout <<"\n\n";
    for (i=0; i<col; i++)
    {
        for (j=0; j<8; j++)
        {
            if (tableaumatrix[j]-1<i)
                cout << "\t";
            else cout << "|"+tableau[j][i]+"|\t";
        }
        cout << "\n";
    }
}

int strint(string str)
{
    int val=0;
    string value="";
    istringstream convert(str);
    convert >> val;
    return val;
}
string intstr(int val)
{
    stringstream convert;
    convert << val;
    return convert.str();
}

void coltocol(string* tableau[8], int tableaumatrix[8], int &freecell)
{
    int from,to,num,src,dest;
    cout << "Enter the column no. as source: ";
    cin >> from;
    while (from<1 || from>8)
    {
        cout << "The column no. should be from 1 to 8!!\nEnter the column no. as source: ";
        cin >> from;
    }
    while (tableau[from]==0)
    {
        cout << "There is no card in this location\nEnter the column no. as source: ";
        cin >> from;
    }
    cout << "Enter the column no. as destination: ";
    cin >> to;
    while (to<1 || to>8)
    {
        cout << "The column no. should be from 1 to 8!!\nEnter the column no. as destination: ";
        cin >> to;
    }
    cout << "Enter the number of cards to be moved: ";
    cin >> num;
    if (num<1 || num>freecell+1)
    {
        cout << "Not enough free cells to make this move";
        return;
    }
    from=from-1;
    to=to-1;
    if (tableau[to]==0)
    {
        string* table = new string[tableaumatrix[to]+num];
        for (int i=0; i<tableaumatrix[to]; i++)
        {
            table[i] = tableau[to][i];
        }
        int j=1;
        for (int i=to; i>0; i--)
        {
            table[tableaumatrix[to]-1+i]=tableau[from][tableaumatrix[from]-j];
            j++;
        }
        delete []tableau[to];
        tableau[to]=table;
        tableaumatrix[to]=tableaumatrix[to]+num;
        string* table1= new string[tableaumatrix[from]];
        for (int i=0; i<tableaumatrix[from]-to; i++)
        {
            table1[i]=tableau[from][i];
        }
        delete []tableau[from];
        tableau[from]=table1;
        tableaumatrix[from]-=num;
        return;
    }
    for (int i=1; i<num; i++)
    {
        if (tableau[from][tableaumatrix[from]-i][2]==tableau[from][tableaumatrix[from]-(i+1)][2])
        {
            cout << "Cards of same colour cannot be stacked on each other!!\n";
            return;
        }
    }
    for (int i=1; i<num; i++)
    {
        if (tableau[from][tableaumatrix[from]-i][0]=='A')
            src=1;
        else if (tableau[from][tableaumatrix[from]-i][0]=='J')
            src=11;
        else if (tableau[from][tableaumatrix[from]-i][0]=='Q')
            src=12;
        else if (tableau[from][tableaumatrix[from]-i][0]=='K')
            src=13;
        else
            src=tableau[from][tableaumatrix[to]-i][0]-48;
        if (tableau[to][tableaumatrix[to]-(i+1)][0]=='A')
            dest=1;
        else if (tableau[to][tableaumatrix[to]-(i+1)][0]=='J')
            dest=11;
        else if (tableau[to][tableaumatrix[to]-(i+1)][0]=='Q')
            dest=12;
        else if (tableau[to][tableaumatrix[to]-(i+1)][0]=='K')
            dest=13;
        else
            dest=tableau[to][tableaumatrix[to]-(i+1)][0]-48;
        if (src!=dest-1)
        {
            cout << "The source card(s) cannot be placed on the destination because of not being in descending order!";
            return;
        }
    }
    cout<<num<<endl;
    if ((tableau[from][tableaumatrix[from]-num][2])==(tableau[to][tableaumatrix[to]-1][2]))
    {
        cout << "Same coloured cards cannot be placed on each other!!\n";
        return;
    }
    if (tableau[from][tableaumatrix[from]-num][0]=='A')
            src=1;
        else if (tableau[from][tableaumatrix[from]-num][0]=='J')
            src=11;
        else if (tableau[from][tableaumatrix[from]-num][0]=='Q')
            src=12;
        else if (tableau[from][tableaumatrix[from]-num][0]=='K')
            src=13;
        else
            src=tableau[from][tableaumatrix[from]-num][0]-48;
        if (tableau[to][tableaumatrix[to]-1][0]=='A')
            dest=1;
        else if (tableau[to][tableaumatrix[to]-1][0]=='J')
            dest=11;
        else if (tableau[to][tableaumatrix[to]-1][0]=='Q')
            dest=12;
        else if (tableau[to][tableaumatrix[to]-1][0]=='K')
            dest=13;
        else
            dest=tableau[to][tableaumatrix[to]-1][0]-48;
            cout<<tableau[from][tableaumatrix[from]-num][0]<<endl;
            cout<<tableau[to][tableaumatrix[to]-1][0]<<endl;
    cout<<src<<endl;
    cout<<dest<<endl;
    if (src!=dest-1)
    {
        cout << "The source card(s) cannot be placed on the destination because of not being in descending order!\n";
        return;
    }
    string* table = new string[tableaumatrix[to]+num];
        for (int i=0; i<tableaumatrix[to]; i++)
        {
            table[i] = tableau[to][i];
        }

        int j=1;
        cout<<num<<"\n";
        for (int i=num; i>=1; i--)
        {
            table[tableaumatrix[to]-1+i]=tableau[from][tableaumatrix[from]-j];
            j++;
        }
        cout<<"ii"<<endl;
        delete []tableau[to];
        tableau[to]=table;
        tableaumatrix[to]+=num;
        string* table1= new string[tableaumatrix[from]];
        for (int i=0; i<tableaumatrix[from]-num; i++)
        {
            table1[i]=tableau[from][i];
        }
        delete []tableau[from];
        cout<<"ii"<<endl;
        tableau[from]=table1;
        tableaumatrix[from]-=num;
        return;

}

void coltofree(string* tableau[], int tableaumatrix[], string free[], int &freecell)
{
    int from,to,i;
    cout << "Enter column no. as source: ";
    cin >> from;
    while (from<1 || from>8)
    {
        cout << "The column no. should be from 1 to 8!!\nEnter the column no. as source: ";
        cin >> from;
    }
    cout << "Enter free cell no. as destination: ";
    cin >> to;
    while (to<1 || to>4)
    {
        cout << "The free cell no. should be from 1 to 4!!\nEnter the free cell no. as destination: ";
        cin >> to;
    }
    from=from-1;
    to=to-1;
    if (free[to]!="")
    {
        cout << "This free cell is already filled!!";
        return;
    }
    free[to]=tableau[from][tableaumatrix[from]-1];
    string *table = new string[tableaumatrix[from]-1];
    for (i=0; i<tableaumatrix[from]-1; i++)
        table[i]=tableau[from][i];

    delete []tableau[from];
    tableaumatrix[from]-=1;
    tableau[from]=table;
    freecell=freecell-1;
}
void coltohome(string* tableau[], int tableaumatrix[], string home[], int &freecell)
{
    int from,to,src,dest,i;
    cout << "Enter column no. as source: ";
    cin >> from;
    while (from<1 || from>8)
    {
        cout << "The column no. should be from 1 to 8!!\nEnter the column no. as source: ";
        cin >> from;
    }
    cout << "Enter home no. as destination: ";
    cin >> to;
    while (to<1 || to>4)
    {
        cout << "The home no. should be from 1 to 4!!\nEnter the free cell no. as destination: ";
        cin >> to;
    }
    from=from-1;
    to=to-1;
    if (tableau[from][tableaumatrix[from]-1][0]=='A')
        src=1;
    else if (tableau[from][tableaumatrix[from]-1][0]=='J')
        src=11;
    else if (tableau[from][tableaumatrix[from]-1][0]=='Q')
        src=12;
    else if (tableau[from][tableaumatrix[from]-1][0]=='K')
        src=13;
    else
        src=tableau[from][tableaumatrix[to]-1][0]-48;
    if (home[to][0]=='A')
        dest=1;
    else if (home[to][0]=='J')
        dest=11;
    else if (home[to][0]=='Q')
        dest=12;
    else if (home[to][0]=='K')
        dest=13;
    else if (home[to][0]=='0')
        dest=home[to][0]-48;

    if (src!=dest+1)
    {
        cout << "The source card(s) cannot be placed on the destination because of not being in descending order!\n";
    }
    if (home[to]!=""&& tableau[from][tableaumatrix[from]-1][1]!=home[to][1])
    {
        cout << "This card does not belong to this home!\n";
        return;
    }
    string *table = new string[tableaumatrix[from]-1];
    for (i=0; i<tableaumatrix[from]-1; i++)
        table[i]=tableau[from][i];
    home[to]=tableau[from][tableaumatrix[from]-1];
    delete []tableau[from];
    tableaumatrix[from]-=1;
    tableau[from]=table;
}
void freetohome(string free[], string home[], int &freecell)
{
    int from,to,src,dest,i;
    cout << "Enter free cell no. as source: ";
    cin >> from;
    while (from<1 || from>4)
    {
        cout << "The free cell no. should be from 1 to 4!!\nEnter the column no. as source: ";
        cin >> from;
    }
    cout << "Enter home no. as destination: ";
    cin >> to;
    while (to<1 || to>4)
    {
        cout << "The home no. should be from 1 to 4!!\nEnter the free cell no. as destination: ";
        cin >> to;
    }
    from=from-1;
    to=to-1;
    if (free[from]=="")
    {
        cout << "This free cell is already empty!\n";
        return;
    }
    if (home[from]!=""&&home[to][1]!=free[from][1])
    {
        cout << "This card does not belong to this home!\n";
    }
    if (free[from][0]=='A')
        dest=1;
    else if (free[from][0]=='J')
        dest=11;
    else if (free[from][0]=='Q')
        dest=12;
    else if (free[from][0]=='K')
        dest=13;
    else
        dest=free[from][0]-48;
    if (home[to][0]=='A')
        dest=1;
    else if (home[to][0]=='J')
        dest=11;
    else if (home[to][0]=='Q')
        dest=12;
    else if (home[to][0]=='K')
        dest=13;
    else if (home[to][0]=='0')
        dest=home[to][0]-48;
    if (src!=dest+1)
    {
        cout << "The source card(s) cannot be placed on the destination because of not being in ascending order!\n";
        return;
    }
    home[to]=free[from];
    freecell--;
    free[a]="";
}

void save(string* tableau[], int tableaumatrix[], string home[], int &freecell, string free[]);
{
    ifstream in;
    ofstream out;
    in.open("savedgame.txt");
    in.open("savedgame.txt");
    int i,j;
    for (i=0;i<8;i++)
    {
        out<<tableaumatrix[][]
    }
}
