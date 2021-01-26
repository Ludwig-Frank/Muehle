//MatrNr: 5340606


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
	Player* playerarray[2];
	bool start = false;
	while (start == false) {
		int type1;
		int type2;
		start = true;
		std::cout << "Willkommen bei Muehle" << endl;
		std::cout << "Soll Spieler 1 eine KI oder ein Mensch sein?" << endl;
		std::cout << "(1)Mensch     (2)KI" << endl;
		std::cin >> type1;
		std::cout << "Soll Spieler 1 eine KI oder ein Mensch sein?" << endl;
		std::cout << "(1)Mensch     (2)KI" << endl;
		std::cin >> type2;
		switch (type1) {
		case 1: playerarray[0] = new Human("w");
			break;
		case 2: playerarray[0] = new RandomAI("w");
			break;
		default:
			std::cout << "Fehlerhafte Eingabe" << endl;
			playerarray[0] = new RandomAI("w");
			start = false;
		}
		switch (type2) {
		case 1: playerarray[1] = new Human("b");
			break;
		case 2: playerarray[1] = new RandomAI("b");
			break;
		default:
			std::cout << "Fehlerhafte Eingabe" << endl;
			playerarray[1] = new RandomAI("b");
			start = false;
		}
	}
	field = new Field();
	bool win = false;
	string winner;
	Player* player1 = playerarray[0];
	Player* player2 = playerarray[1];
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
		field->printfield();
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
		currentPlayer = changeturn(currentPlayer, player1, player2);
		if (field->checkwin(player1, player2)) {
			win = true;
			winner = field->checkwin(player1, player2)->get_tokencolor();
		}

	}
	std::cout << winner << " hat gewonnen" << endl;
	getchar();
}
 