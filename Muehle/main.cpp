#include<iostream>
#include "Field.h"
#include <stdio.h>
using namespace std;
Field* field;

Player* changeturn(Player* currentPlayer, Player* player1, Player* player2) {
	if (currentPlayer->get_tokencolor() == player1->get_tokencolor()) {
		currentPlayer = player2;
	}
	else {
		currentPlayer = player1;
	}
	return currentPlayer;
}

int main() {
	field = new Field();
	Human* player1 = new Human("w");
	Human* player2 = new Human("b");
	Player* currentPlayer = player1;
	while (player1->get_tokencounter() != 0){ //&& player2->get_tokencounter() != 0) {
		field->printfield();
		std::cout << currentPlayer->get_tokencolor() << " ist am Zug" << endl;
		currentPlayer->spawnToken();
		if (field->checkMuehle(currentPlayer->get_tokencolor()) == true) {
			std::cout << "Muehle !!" << endl;
			//currentPlayer = changeturn(currentPlayer, player1, player2);
		}
	}
}
 