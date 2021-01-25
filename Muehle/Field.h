#include <iostream>
#include "Player.h"
using namespace std;

class Field
{
public:
	string fieldAsArray[3][9];
	void printfield();
	Player checkwin();
	Field();
};
