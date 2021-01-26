#pragma once
#include <iostream>
class Token;
class Positions;
using namespace std;
class Player
{
protected:
	string tokencolor;
	int tokencounter;
	Token* tokenarray[9];
public:
	Player(string color);
	string get_tokencolor();
	void placeToken(Token* token, Positions* position);
	void deleteToken(Positions* position);
	void surrender();
	virtual void move() = 0;
	virtual void kickEnemyToken() = 0;
	virtual void spawnToken() = 0;
	Positions* muehlen[5][3] = { NULL };
	bool surrendered;
	Token* get_Token();
	void add_muehle(Positions* position1, Positions* middleposition, Positions* position3);
	void del_muehle(Positions* position1, Positions* middleposition, Positions* position3);
	int get_tokencounter();
	
};
