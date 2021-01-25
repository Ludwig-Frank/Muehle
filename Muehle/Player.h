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
	virtual void kickEnemyToken(Positions position) = 0;
	virtual void spawnToken(Positions position) = 0;
	bool surrendered;
	Token* get_Token();
};
