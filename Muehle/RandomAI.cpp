#include "RandomAI.h"
#include"Field.h"

extern Field* field;

RandomAI::RandomAI(string color) :Player(color) {
	tokencolor = color;
}

void RandomAI::kickEnemyToken()
{
	bool kick = false;
	while (kick == false) {
		int ring;
		int position;
		ring = rand() % 3;
		position = rand() % 8;
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
		if (field->fieldAsArray[ring][position]->get_currentToken() == this->get_tokencolor() || field->fieldAsArray[ring][position]->get_currentToken() == "0") {
			kick = false;
		}
		else {
			field->fieldAsArray[ring][position]->set_token(NULL);
			kick = true;
		}
		
	}
}

void RandomAI::spawnToken()
{
	bool spawn = false;
	if (tokencounter >= 1) {
		while (spawn == false) {
			int ring;
			int position;
			ring = rand() % 3;
			position = rand() % 8;
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
			}
		}
	}
}

void RandomAI::move()
{
	int ring;
	int position;
	int oldposition[2];
	bool validation1;
	bool validation2;
	bool moved = false;
	while (moved == false) {
		ring = rand() % 3;
		position = rand() % 8;
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
		if (!(field->fieldAsArray[ring][position]->get_currentToken() != this->get_tokencolor())){
			int directory;
			directory = rand()%4 +1;
			switch (directory) {
			case 1: if (field->fieldAsArray[ring][position]->neighbourpositions[1] != NULL) {
				if (field->fieldAsArray[ring][position]->neighbourpositions[1]->get_currentToken() == "0") {
					this->placeToken(this->get_Token(), field->fieldAsArray[ring - 1][position]);
					this->deleteToken(field->fieldAsArray[ring][position]);
					moved = true;
				}
			}
				  break;
			case 2: if (field->fieldAsArray[ring][position]->neighbourpositions[0] != NULL) {
				if (field->fieldAsArray[ring][position]->neighbourpositions[0]->get_currentToken() == "0") {
					this->placeToken(this->get_Token(), field->fieldAsArray[ring + 1][position]);
					this->deleteToken(field->fieldAsArray[ring][position]);
					moved = true;
				}
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
			}
				  break;
			default: moved = false;
				break;

			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			if (muehlen[i][0]!= NULL && this->muehlen[i][j] == field->fieldAsArray[oldposition[0]][oldposition[1]]) {
				muehlen[i][0] = NULL;
				muehlen[i][0] = NULL;
				muehlen[i][0] = NULL;
				return;
			}
		}
	}

}
