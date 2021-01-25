#include <iostream>
#include "Token.h"
#include "Positions.h"
using namespace std;
class Player
{
protected:
	string tokencolor;
	int tokencounter;
public: 
	string get_tokencolor();
	void placeToken(Token, Positions);
	void deleteToken(Positions);
	void surrender();
	virtual void kickEnemyToken(Positions) = 0;
	virtual void spawnToken(Positions) = 0;
	bool surrendered;
};
