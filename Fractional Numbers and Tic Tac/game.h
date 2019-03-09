#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "square.h"
#include "player.h"


using namespace std;

class game
{
    private:
        square* *board;
        int size;
        player py1;
        player py2;
    public:
        game();
		game(player p1,player p2, int sz);
		~game();
		void setSize(int sz);
		int getSize();
		void makeGame();

};

#endif // GAME_H
