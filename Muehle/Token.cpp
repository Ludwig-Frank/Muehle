#include "Field.h"
#include "Token.h"
Token::Token(Player* player) {
	relatedPlayer = player;
}
Token::~Token() {

}

string Token::get_tokenasstring()
{
	return relatedPlayer->get_tokencolor();
}
