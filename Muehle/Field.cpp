
#include "Field.h"
#include <iostream>
using namespace std;
Field::Field() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 9; j++) {
			fieldAsArray[i][j] = "0";
		}
	}
 }
Field::~Field() {

}
void Field::printfield() {
	std::cout <<
}
Player Field::checkwin() {

}