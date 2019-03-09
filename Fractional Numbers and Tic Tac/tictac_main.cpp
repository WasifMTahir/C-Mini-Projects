#include <iostream>
#include "square.h"
#include "player.h"
#include "game.h"
using namespace std;

int main()
{
    game obj;
    player p1,p2;
    int size;
    string fn1,ln1,s1,fn2,ln2,s2;
    cout << "Enter Odd Numbered Size: ";
    cin >> size;

    cout << "Enter First name of Player 1: ";
    cin >> fn1;
    cout << "Enter Last name of Player 1: ";
    cin >> ln1;
    cout << "Enter Symbol of Player 1: ";
    cin >> s1;
    cout << "Enter First name of Player 2: ";
    cin >> fn2;
    cout << "Enter Last name of Player 2: ";
    cin >> ln2;
    cout << "Enter Symbol of Player 2: ";
    cin >> s2;

    obj.makeboard();
    rturn 0;
}
