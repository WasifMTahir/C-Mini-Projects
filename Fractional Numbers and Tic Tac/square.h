#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include "player.h"
#include "game.h"

using namespace std;

class square
{
    private:
        string box;
    public:
        square();
        square(string g);
        void setGrid(string g);
        string getGrid();
};

#endif // SQUARE_H
