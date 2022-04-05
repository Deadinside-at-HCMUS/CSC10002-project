#include "Init.h"
using namespace std;

int main() {
	fixConsoleWindow();
	noCursorType();
	changeConsoleColor(WHITE);
	loading();
	while (true) {
		mainMenu();
		POSITION choice = inputMainMenu();
		if (choice.x == 0 && choice.y == 0) {
			system("cls");
			playMenu();
			POSITION sub_choice = inputPlayMenu();
			if (sub_choice.y == 0) {
				infoBoard(1, 5);
				newGame();

			} else if (sub_choice.y == 1) {
				infoBoard(1, 5);
				gotoXY(1, 1);
				cout << "hi hi";
				system("pause");
			} else {
				infoBoard(1, 5);
				gotoXY(1, 1);
				cout << "hi hi";
				system("pause");
			}
		}
		else if (choice.x == 1 && choice.y == 0) {
			gameTurtorial();
			// _getch();
		}
		else if (choice.x == 0 && choice.y == 1) {
			aboutUs();
			// _getch();
		}
		else {
			break;
		}
	}
	return 0;
}