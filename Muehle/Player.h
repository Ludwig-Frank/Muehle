#include <iostream>
#include "Token.h"
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
	bool surrendered;
};
