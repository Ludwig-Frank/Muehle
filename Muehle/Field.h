#include <iostream>
#include"AI.h"
#include"Human.h"
#include"Positions.h"
#include "Token.h"

using namespace std;
class Field
{
public:
	Positions* fieldAsArray[3][8];
	void printfield();
	Token checkwin();
	bool checkMuehle(string token);
	Field();
};
