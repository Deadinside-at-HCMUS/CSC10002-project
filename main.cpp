#include <iostream>
#include "Init.h"
using namespace std;

int main() {
	//ham khoi chay game
	GameSetup();
	while (true) {
		MainMenu();
		POSITION choice = InputMainMenu();
		if (choice.x == 0 && choice.y == 0) {
			system("cls");
			PlayMenu();
			POSITION sub_choice = InputPlayMenu();
			if (sub_choice.y == 0) {
				InfoBoard(1, 5);

			} else if (sub_choice.y == 1) {
				InfoBoard(1, 5);

			} else {
				InfoBoard(1, 5);

			}
		}
		else if (choice.x == 1 && choice.y == 0) {
			GameTurtorial();
			system("pause");

		}
		else if (choice.x == 0 && choice.y == 1) {
			AboutUs();
			system("pause");

		}
		else {
			break;
		}
	}
	return 0;
}