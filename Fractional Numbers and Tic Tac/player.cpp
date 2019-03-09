#include "player.h"
#include "square.h"
#include <iostream>

using namespace std;

player::player()
{
    fname = "";
    lname = "";
    sign = "";
}

player::player(string f, string l, string s)
{
    fname = f;
    lname = l;
    sign = s;
}

player::~player()
{
    //dtor
}

player::player(const player& other)
{
    //copy ctor
}

void player::setfname(string name)
{
    fname = name;
}
string player::getFname()
{
    return name;
}
void player::setLname(string name)
{
    lname = name;
}
string player::getLname()
{
    return lname;
}
void player::setSign(string name)
{
    sign = name;
}
string player::getSign()
{
    return sign;
}

void player::operator = (const player& p1)
{
    fname = p1.fname;
	lname = p1.lname;
	sign = p1.sign;
}
