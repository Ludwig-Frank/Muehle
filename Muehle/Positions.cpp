#include "Positions.h"
#include "Field.h"

Positions::Positions(int ring, int position)
{
	coordinates[0] = ring;
	coordinates[1] = position;
	for (int i = 0; i < 4; i++) {
		neighbourpositions[i] = NULL;
	}
}

string Positions::get_currentToken()
{
	if (currentToken) {
		return currentToken->get_tokenasstring();
	}
	else {
		return "0";
	}
}

void Positions::set_token(Token* token)
{
	currentToken = token;
}
