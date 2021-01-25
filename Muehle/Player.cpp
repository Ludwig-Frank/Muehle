#include <iostream>
using namespace std;
#include "Player.h"
#include "Field.h"
extern Field* field;

Player::Player(string color) {
	for (int i = 0; i < 9; i++) {
		tokenarray[i] = new Token(this);
	}
	

}

string Player::get_tokencolor() {
	return tokencolor;
}
void Player::placeToken(Token* token, Positions* position) {
	field->fieldAsArray[position->coordinates[0]][position->coordinates[1]]->set_token(token);
}
void Player::deleteToken(Positions* position) {
	field->fieldAsArray[position->coordinates[0]][position->coordinates[1]]->set_token(NULL);
}
void Player::surrender() {
	surrendered = true;
}

Token* Player::get_Token()
{
	return tokenarray[0];
}
