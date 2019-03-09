#include "game.h"
#include <iostream>
#include "square.h"
#include "player.h"

game::game()
{
    board = new square*[1];
    board[1] = new square[1];
}

game::game(player p1, player p2, int sz)
{
	py1=p1;
	py2=p2;
	size=sz;
	board = new square*[size];
	for(int i = 0; i < size; i++)
    {
        board[i] = new square[size];
    }
}

game::~game()
{
    //delete[] square;
}

void game::setSize(int sz)
{
    size = sz;
}

int game::getSize()
{
    return size;
}

void game::makeGame()
{
    cout << py1.getFname() << " " << py1.getLname() << "  " <<py1.getSign() << "\tvs\t" << py2.getFname() << " " << py2.getLname() << "  " << py1.getSign() << "\n\n";

    for (int i=1; i<=size; i++)
		cout << "Col"<<i<<endl;
	for (int i = 0;i < size; i++)
    {
        cout << "Row" << i+1;
        for(int j = 0; j < size; j++)
        cout << board[i][j].getGrid();
        cout << "\n\n";
    }

}
