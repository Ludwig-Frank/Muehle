#pragma once
#include "Player.h"
class AI : public Player
{
public:
	AI(string color);
	void kickEnemyToken(Positions position) override;
	void spawnToken(Positions position) override;
};

