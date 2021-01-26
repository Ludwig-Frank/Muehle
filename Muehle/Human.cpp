#include "Human.h"
#include "Field.h"
#include <string>
extern Field* field;
Human::Human(string color):Player(color) {
	tokencolor = color;
}
void Human::kickEnemyToken() {

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