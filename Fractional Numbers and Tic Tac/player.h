#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "square.h"
#include "player.h"
#include "game.h"

using namespace std;

class player
{
    private:
        string fname;
        string lname;
    public:
        player();
        ~player();
        player(const player& other);
        void setFname(string name);
        string getFname();
        void setLname(string name);
        string getLname();
        void setSign(string name);
        string getSign();
};

#endif // PLAYER_H
