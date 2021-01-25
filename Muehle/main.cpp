#include<iostream>
#include "Field.h"

using namespace std;
Field* field;

 int main() {
	field = new Field();
	Human* henri = new Human("b");
	henri->placeToken(henri->get_Token(), field->fieldAsArray[0][0]);
	field->printfield();
	return field->fieldAsArray[0][1]->neighbourpositions[3]->get_currentToken();
	getchar();
};