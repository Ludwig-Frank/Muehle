
#include "Field.h"
#include <iostream>
#include <string>
using namespace std;
Field::Field() {
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 8; j++) {
			fieldAsArray[i][j] = new Positions(i,j);
			

		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 8; j++) {
			if (j % 2 == 1) {
				if (i < 2) {
					fieldAsArray[i][j]->neighbourpositions[0] = fieldAsArray[i + 1][j];
				}
				if (i > 0) {
					fieldAsArray[i][j]->neighbourpositions[1] = fieldAsArray[i - 1][j];
				}
				if (j < 7) {
					fieldAsArray[i][j]->neighbourpositions[2] = fieldAsArray[i][j + 1];
				}
				if (j > 0) {
					fieldAsArray[i][j]->neighbourpositions[3] = fieldAsArray[i][j - 1];
				}
			}
			if (j % 2 == 0) {
				if (j < 7) {
					fieldAsArray[i][j]->neighbourpositions[2] = fieldAsArray[i][j + 1];
				}
				if (j > 0) {
					fieldAsArray[i][j]->neighbourpositions[3] = fieldAsArray[i][j - 1];
				}
				if (j == 0) {
					fieldAsArray[i][j]->neighbourpositions[3] = fieldAsArray[i][7];
				}
				if (j == 7) {
					fieldAsArray[i][j]->neighbourpositions[2] = fieldAsArray[i][0];
				}
			}
		}
	}
 }

void Field::printfield() {
	std::cout << fieldAsArray[0][0]->get_currentToken() << "- - - - -" << fieldAsArray[0][1]->get_currentToken() << "- - - - -" << fieldAsArray[0][2]->get_currentToken() << endl;
	std::cout << "|         |         |" << endl;
	std::cout << "|   " << fieldAsArray[1][0]->get_currentToken() << "- - -" << fieldAsArray[1][1]->get_currentToken() << "- - -" << fieldAsArray[1][2]->get_currentToken() << "   |" << endl;
	std::cout << "|   |     |     |   |" << endl;
	std::cout << "|   |  " << fieldAsArray[2][0]->get_currentToken() <<" -"<< fieldAsArray[2][1]->get_currentToken() <<"- "<< fieldAsArray[2][2]->get_currentToken() << "  |   |" << endl;
	std::cout << "|   |  |     |  |   |" << endl;
	std::cout << fieldAsArray[0][7]->get_currentToken() <<" - "<< fieldAsArray[1][7]->get_currentToken() <<" -"<< fieldAsArray[2][7]->get_currentToken() << "     " << fieldAsArray[2][3]->get_currentToken() <<"- "<< fieldAsArray[1][3]->get_currentToken() <<" - "<< fieldAsArray[0][3]->get_currentToken() << endl;
	std::cout << "|   |  |     |  |   |" << endl;
	std::cout << "|   |  " << fieldAsArray[2][6]->get_currentToken() << " -" << fieldAsArray[2][5]->get_currentToken() << "- " << fieldAsArray[2][4]->get_currentToken() << "  |   |" << endl;
	std::cout << "|   |     |     |   |" << endl;
	std::cout << "|   " << fieldAsArray[1][6]->get_currentToken() << "- - -" << fieldAsArray[1][5]->get_currentToken() << "- - -" << fieldAsArray[1][4]->get_currentToken() << "   |" << endl;
	std::cout << "|         |         |" << endl;
	std::cout << fieldAsArray[0][6]->get_currentToken() << "- - - - -" << fieldAsArray[0][5]->get_currentToken() << "- - - - -" << fieldAsArray[0][4]->get_currentToken() << endl;
}
Token Field::checkwin() {
	return NULL;
}