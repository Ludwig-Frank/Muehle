#pragma once
#include "Player.h"
class Human : public Player
{
public:
	void kickEnemyToken(Positions) override;
	void spawnToken(Positions) override;
};

