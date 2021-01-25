#pragma once
#include<iostream>
#include "Token.h"
using namespace std;
class Positions
{
private:
	Token currentToken;
public:
	int type;
	Positions* neighbourpositions[4];
	int coordinates[2];
	Token get_currentToken();

};

