#pragma once
#include "Player.h"
class AI : public Player
{
public:
	AI(string color);
	void kickEnemyToken() override;
	void spawnToken() override;
};

