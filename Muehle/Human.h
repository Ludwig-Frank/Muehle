#pragma once
#include <iostream>
using namespace std;
#include "Player.h"
class Human : public Player
{
public:
	Human(string color);
	void kickEnemyToken();
	void spawnToken();
	void move();
};

