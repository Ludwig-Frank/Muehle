#pragma once
#include <iostream>
using namespace std;
#include "Player.h"
class Human : public Player
{
public:
	Human(string color);
	void kickEnemyToken() override;
	void spawnToken() override;
	void move() override ;
};

