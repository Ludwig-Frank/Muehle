#include <iostream>
using namespace std;
#include "Player.h"
#include "Token.h"
#include "Field.h"
#include "Positions.h"
extern Field* field;

Player::Player() {
	tokencolor = "w";
}
Player::~Player() {

}
string Player::get_tokencolor() {
	return tokencolor;
}
void Player::placeToken(Token token, Positions position) {
	field->fieldAsArray[position.coordinates[0]][position.coordinates[1]] = token.relatedPlayer.get_tokencolor();
}
void Player::deleteToken(Positions position) {
	field->fieldAsArray[position.coordinates[0]][position.coordinates[1]] = "0";
}
void Player::surrender() {
	surrendered = true;
}
