#include<iostream>
#include "Field.h"

using namespace std;
Field* field;

 int main() {
	field = new Field();
	Human* henri = new Human("b");
	while (henri->get_tokencounter != 0) {
		field->printfield();
		henri->spawnToken();
	}
	getchar();
};
 