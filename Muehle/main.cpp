#include<iostream>
#include "Field.h"

using namespace std;
Field* field;

main() {
	field = new Field();
	std::cout << field->fieldAsArray[0];
};