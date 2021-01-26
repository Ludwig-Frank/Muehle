#pragma once
#include "Player.h"
class RandomAI : public Player
{
public:
	RandomAI(string color);
	void kickEnemyToken() override ;
	void spawnToken() override ;
	void move() override ;
};

