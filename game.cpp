#include <iostream>
#include "Init.h"
using namespace std;

bool gameover;
int charlock;
int score;
int tailsize;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void GameLoad() {
	gameover = false;
	ChangeConsoleColor(WHITE);
	Loading();
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
			_getch();

		}
		else if (choice.x == 0 && choice.y == 1) {
			AboutUs();
			_getch();

		}
		else {
			break;
		}
	}


}