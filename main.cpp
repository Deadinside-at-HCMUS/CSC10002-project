#include "Init.h"
using namespace std;

int main() {
	// _setmode(_fileno(stdout), _O_U16TEXT);
	fixConsoleWindow();
	noCursorType();
	changeConsoleColor(WHITE);
	// loading();
	while (true) {
		mainMenu();
		POSITION choice = inputMainMenu();
		if (choice.x == 0 && choice.y == 0) {
			system("cls");
			playMenu();
			POSITION sub_choice = inputPlayMenu();
			if (sub_choice.y == 0) {
				// che do choi classic
				infoBoard(1, 5);
				infoSet(1);
				newClassicGame();

			} else if (sub_choice.y == 1) {
				// che do choi time rush
				infoBoard(1, 5);
				gotoXY(1, 1);
				cout << "hi hi";
				system("pause");
			} else {
				//che do choi infinitie
				drawBlank(1, 5, INFO_BOARD_LENGTH, INFO_BOARD_WIDTH);
				textColorWithBackground(PURPLE, WHITE);
				drawChoiceBox(1, 5, INFO_BOARD_LENGTH + 1, INFO_BOARD_WIDTH + 1);
				infoSet(3);
				newInfiniteGame();

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