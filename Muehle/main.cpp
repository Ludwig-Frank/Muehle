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
	bool win = false;
	Human* player1 = new Human("w");
	Human* player2 = new Human("b");
	Player* currentPlayer = player1;	
	while (!(player1->get_tokencounter() == 0 && player2->get_tokencounter() == 0)) {
		field->printfield();
		std::cout << currentPlayer->get_tokencolor() << " ist am Zug" << endl;
		currentPlayer->spawnToken();
		field->updateneighbourpositions();
		int oldmills = 0;
		int newmills = 0;
		for (int i = 0; i < 5; i++) {
			if (currentPlayer->muehlen[i][1]!= nullptr) {
				oldmills += 1;
			}
		}
		if (field->checkMuehle(currentPlayer->get_tokencolor()) == true) {
			for (int i = 0; i < 5; i++) {
				if (currentPlayer->muehlen[i][1] != nullptr) {
					newmills += 1;
				}
			}
			if (newmills > oldmills) {
				std::cout << "Muehle! Du darfst einen gegnerischen Spielstein entfernen" << endl;
				currentPlayer->kickEnemyToken();
			}
		}
		currentPlayer = changeturn(currentPlayer, player1, player2);
	}
	while (win == false) {
		int oldmills = 0;
		int newmills = 0;
		Positions* oldmuehlen[5][3];
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 3; j++) {
				oldmuehlen[i][j] = currentPlayer->muehlen[i][j];
			}
		}
		for (int i = 0; i < 5; i++) {
			if (currentPlayer->muehlen[i][1] != nullptr) {
				oldmills += 1;
			}
		}
		currentPlayer->move();
		field->updateneighbourpositions();
		if (field->checkMuehle(currentPlayer->get_tokencolor()) == true) {
			bool same = true;
			for (int i = 0; i < 5; i++) {
				if (currentPlayer->muehlen[i][1] != nullptr) {
					newmills += 1;
				}
				for (int j = 0; j < 3; j++) {
					if (currentPlayer->muehlen[i][j] != oldmuehlen[i][j]) {
						same = false;
					}
				}
			}
			if (same == false) {
				if (oldmills <= newmills) {
					std::cout << "Muehle! Du darfst einen Spielstein deines Gegners entfernen." << endl;
					currentPlayer->kickEnemyToken();
				}
			}
		}

	}
	/*field->printfield();
	player1->spawnToken();
	field->updateneighbourpositions();
	field->printfield();
	player1->move();
	field->printfield();*/
	getchar();
}
 