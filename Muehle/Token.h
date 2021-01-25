#pragma once
#include "Player.h"
class Token
{
public:
	Token(Player* player);
	~Token();
	Player* relatedPlayer;
	string get_tokenasstring();
};
