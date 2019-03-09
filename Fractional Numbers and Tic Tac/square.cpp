#include "square.h"
#include <iostream>
#include "player.h"
square::square()
{
    grid = "-"
}

square::square(string g)
{
	grid = g;
}

void square::setGrid(string g)
{
	grid = g;
}
string square::getGrid()
{
	return grid;
}
