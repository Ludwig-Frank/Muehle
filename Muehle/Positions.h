#pragma once
#include<iostream>
class Token;
using namespace std;
class Positions
{
private:
	Token* currentToken;
public:
	Positions(int ring, int position);
	Positions* neighbourpositions[4];
	int coordinates[2];
	string get_currentToken();
	void set_token(Token* token);
};

