#include <iostream>
using namespace std;
#include "Player.h"
#include "Field.h"
extern Field* field;

Player::Player(string color) {
	for (int i = 0; i < 9; i++) {
		tokenarray[i] = new Token(this);
	}
	tokencounter = 9;
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
	if (tokencounter > 0) {
		tokencounter -= 1;
		return tokenarray[tokencounter];
	}
	else {
		Token* token = new Token(this);
		return token;
	}
}
void Player::add_muehle(Positions* position1, Positions* middleposition, Positions* position3)
{
	bool existing = false;
	for (int i = 0; i < 5; i++) {
		if (muehlen[i][0] == position1 && muehlen[i][1] == middleposition && muehlen[i][2] == position3) {
			existing = true;
		}
	}
	if (existing == false) {
		for (int i = 0; i < 5; i++) {
			if (muehlen[i][1] == nullptr) {
				muehlen[i][0] = position1;
				muehlen[i][1] = middleposition;
				muehlen[i][2] = position3;
				break;
			}
		}
	}
}
void Player::del_muehle(Positions* position1, Positions* middleposition, Positions* position3)
{
	for (int i = 0; i < 5; i++) {
		if (muehlen[i][0]==position1 && muehlen[i][1]==middleposition && muehlen[i][2]==position3) {
			muehlen[i][0] = NULL;
			muehlen[i][1] = NULL;
			muehlen[i][2] = NULL;
		}
	}
}
int Player::get_tokencounter() {
	return tokencounter;
}