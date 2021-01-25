#pragma once
#include "Player.h"
class AI : public Player
{
public:
	void kickEnemyToken(Positions) override;
	void spawnToken(Positions) override;
};

