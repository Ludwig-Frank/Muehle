#include <iostream>
#include"RandomAI.h"
#include"Human.h"
#include"Positions.h"
#include "Token.h"

using namespace std;
class Field
{
public:
	Positions* fieldAsArray[3][8];
	void printfield();
	Player* checkwin(Player* player1, Player* player2);
	bool checkMuehle(string token);
	void updateneighbourpositions();
	Field();
};
