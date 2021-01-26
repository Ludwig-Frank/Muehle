#include "Human.h"
#include "Field.h"
#include <string>
extern Field* field;
Human::Human(string color):Player(color) {
	tokencolor = color;
}
void Human::kickEnemyToken() {
	bool kick = false;
	while (kick == false) {
		int ring;
		int position;
		std::cout << "Auf welchem Ring befindet sich der Spielstein des Gegners?" << endl;
		std::cin >> ring;
		std::cout << "Auf welcher Position befindet sich der Spielstein des Gegners?" << endl;
		std::cin >> position;
		bool validation1 = false;
		bool validation2 = false;
		switch (ring) {
		case 0: validation1 = true;
			break;
		case 1: validation1 = true;
			break;
		case 2: validation1 = true;
			break;
		default: validation1 = false;
			int ring;
			int position;
		}
		switch (position) {
		case 0:validation2 = true;
			break;
		case 1:validation2 = true;
			break;
		case 2:validation2 = true;
			break;
		case 3:validation2 = true;
			break;
		case 4:validation2 = true;
			break;
		case 5:validation2 = true;
			break;
		case 6:validation2 = true;
			break;
		case 7:validation2 = true;
			break;
		default: validation2 = false;
			break;
		}
		if (!validation1 || !validation2) {
			std::cout << "Das eingebene Feld existiert nicht" << endl;
		}
		else {
			if (field->fieldAsArray[ring][position]->get_currentToken() == this->get_tokencolor() || field->fieldAsArray[ring][position]->get_currentToken() == "0") {
				std::cout << "Das gewählte Feld ist entweder dein eigenes oder ein leeres" << endl;
			}
			else {
				field->fieldAsArray[ring][position]->set_token(NULL);
				kick = true;
			}
		}

	}
}
void Human::spawnToken() {
	bool spawn = false;
	if (tokencounter >=1 ) {
		while (spawn == false) {
			int ring;
			int position;
			std::cout << "Auf welchem Ring soll dein Stein platziert werden?" << endl;
			std::cin >> ring;
			std::cout << "An welcher Position soll dein Stein Platziert werden?" << endl;
			std::cin >> position;
			bool validation1 = false;
			bool validation2 = false;
			switch (ring) {
			case 0: validation1 = true;
				break;
			case 1: validation1 = true;
				break;
			case 2: validation1 = true;
				break;
			default: validation1 = false;
				int ring;
				int position;
			}
			switch (position) {
			case 0:validation2 = true;
				break;
			case 1:validation2 = true;
				break;
			case 2:validation2 = true;
				break;
			case 3:validation2 = true;
				break;
			case 4:validation2 = true;
				break;
			case 5:validation2 = true;
				break;
			case 6:validation2 = true;
				break;
			case 7:validation2 = true;
				break;
			default: validation2 = false;
				break;
			}
			if (0 <= ring <= 2 && 0 <= position <= 7 && validation1 == true && validation2 == true) {
				if (field->fieldAsArray[ring][position]->get_currentToken() == "0") {
					field->fieldAsArray[ring][position]->set_token(this->get_Token());
					spawn = true;
				}
				else {
					std::cout << "Das eingegebene Feld ist besetzt" << endl;
				}
			}
			else {
				std::cout << "Das eingegebene Feld existiert nicht" << endl;

			}
		}
	}
	else {
	std:cout << "Keine Spielsteine mehr!" << endl;
	}
}

void Human::move()
{
	int ring;
	int position;
	int oldposition[2];
	bool validation1;
	bool validation2;
	bool moved = false;
	while (moved == false) {
		std::cout << "Auf welchem Ring befindet sich der Stein den du bewegen moechtest?" << endl;
		std::cin >> ring;
		std::cout << "An welcher Position befindet sich der Stein den du bewegen moechtest?" << endl;
		std::cin >> position;
		oldposition[0] = ring;
		oldposition[1] = position;
		switch (ring) {
		case 0: validation1 = true;
			break;
		case 1: validation1 = true;
			break;
		case 2: validation1 = true;
			break;
		default: validation1 = false;
			int ring;
			int position;
		}
		switch (position) {
		case 0:validation2 = true;
			break;
		case 1:validation2 = true;
			break;
		case 2:validation2 = true;
			break;
		case 3:validation2 = true;
			break;
		case 4:validation2 = true;
			break;
		case 5:validation2 = true;
			break;
		case 6:validation2 = true;
			break;
		case 7:validation2 = true;
			break;
		default: validation2 = false;
			break;
		}
		if (!validation1 || !validation2) {
			std::cout << "Das eingegebene Feld existiert nicht" << endl;
		}
		if (field->fieldAsArray[ring][position]->get_currentToken() != this->get_tokencolor()) {
			std::cout << "Das ist nicht dein eigener Spielstein !" << endl;
		}
		else {
			int directory;
			std::cout << "In welche Richtung moechtest du deinen Stein bewegen?" << endl;
			std::cout << "(1)Nach Aussen"<<endl;
			std::cout << "(2)Nach Innen" << endl;
			std::cout << "(3)Weiter auf dem Ring" << endl;
			std::cout << "(4)Zurueck auf dem Ring" << endl;
			std::cin >> directory;
			switch (directory) {
			case 1: if (field->fieldAsArray[ring][position]->neighbourpositions[1] != NULL){
				if (field->fieldAsArray[ring][position]->neighbourpositions[1]->get_currentToken() == "0") {
					this->placeToken(this->get_Token(), field->fieldAsArray[ring - 1][position]);
					this->deleteToken(field->fieldAsArray[ring][position]);
					moved = true;
				}
				else {
					std::cout << "Das Feld auf welches du dich bewegen moechtest ist besetzt" << endl;
				}
				}
				else {	
						std::cout<<"Das eingegebene Feld existiert nicht"<<endl;
					}
				break;
			case 2: if (field->fieldAsArray[ring][position]->neighbourpositions[0] != NULL) {
				if (field->fieldAsArray[ring][position]->neighbourpositions[0]->get_currentToken() == "0") {
					this->placeToken(this->get_Token(), field->fieldAsArray[ring + 1][position]);
					this->deleteToken(field->fieldAsArray[ring][position]);
					moved = true;
				}
				else {
					std::cout << "Das Feld auf welches du dich bewegen moechtest ist besetzt" << endl;
				}
			}
				  else {
				std::cout << "Das eingegebene Feld existiert nicht" << endl;
			}
				  break;
			case 3: if (field->fieldAsArray[ring][position]->neighbourpositions[2] != NULL) {
				if (field->fieldAsArray[ring][position]->neighbourpositions[2]->get_currentToken() == "0") {
					if (oldposition[1] == 7) {
						this->placeToken(this->get_Token(), field->fieldAsArray[ring][0]);
						this->deleteToken(field->fieldAsArray[ring][7]);
						moved = true;
					}
					else {
						this->placeToken(this->get_Token(), field->fieldAsArray[ring][position + 1]);
						this->deleteToken(field->fieldAsArray[ring][position]);
						moved = true;
					}
				}
				else {
					std::cout << "Das Feld auf welches du dich bewegen moechtest ist besetzt" << endl;
				}
			}
				  else {
				std::cout << "Das eingegebene Feld existiert nicht" << endl;
			}
				  break;
			case 4: if (field->fieldAsArray[ring][position]->neighbourpositions[3] != NULL) {
				if (field->fieldAsArray[ring][position]->neighbourpositions[3]->get_currentToken() == "0") {
					if (oldposition[1] == 0) {
						this->placeToken(this->get_Token(), field->fieldAsArray[ring][7]);
						this->deleteToken(field->fieldAsArray[ring][0]);
						moved = true;
					}
					else {
						this->placeToken(this->get_Token(), field->fieldAsArray[ring][position - 1]);
						this->deleteToken(field->fieldAsArray[ring][position]);
						moved = true;
					}
				}
				else {
					std::cout << "Das Feld auf welches du dich bewegen moechtest ist besetzt" << endl;
				}
			}
				  else {
				std::cout << "Das eingegebene Feld existiert nicht" << endl;
			}
				  break;
			default: std::cout << "Fehlerhafte Eingabe" << endl;
				  break;
			
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			if (this->muehlen[i][j] == field->fieldAsArray[oldposition[0]][oldposition[1]]) {
				muehlen[i][0] = NULL;
				muehlen[i][0] = NULL;
				muehlen[i][0] = NULL;
			}
		}
	}
}
