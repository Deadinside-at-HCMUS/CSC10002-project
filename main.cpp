#include "Init.h"
using namespace std;

int main() {
	setlocale(LC_CTYPE, ".OCP");
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
				textColorWithBackground(CYAN, WHITE);
				drawBoard(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH, PURPLE);
				drawBlank(27, 6, 89, 19);
				gotoXY(50, 14);
				wcout << L"░▒█▀▀█░█▀▀▄░█▀▄▀█░█▀▀░▒█▀▀▀█░▄░░░▄░█▀▀░█▀▀▄";
				gotoXY(50, 15);
				wcout << L"░▒█░▄▄░█▄▄█░█░▀░█░█▀▀░▒█░░▒█░░█▄█░░█▀▀░█▄▄▀";
				gotoXY(50, 16);
				wcout << L"░▒█▄▄▀░▀░░▀░▀░░▒▀░▀▀▀░▒█▄▄▄█░░░▀░░░▀▀▀░▀░▀▀";
				cin.ignore();  

			} else if (sub_choice.y == 1) {
				// che do choi time rush
				infoBoard(1, 5);
				infoSet(1);
				drawBlank(27, 6, 89, 19);
				gotoXY(50, 14);
				wcout << L"░▒█▀▀█░█▀▀▄░█▀▄▀█░█▀▀░▒█▀▀▀█░▄░░░▄░█▀▀░█▀▀▄";
				gotoXY(50, 15);
				wcout << L"░▒█░▄▄░█▄▄█░█░▀░█░█▀▀░▒█░░▒█░░█▄█░░█▀▀░█▄▄▀";
				gotoXY(50, 16);
				wcout << L"░▒█▄▄▀░▀░░▀░▀░░▒▀░▀▀▀░▒█▄▄▄█░░░▀░░░▀▀▀░▀░▀▀";
				cin.ignore();
			} else {
				//che do choi infinitie
				drawBlank(1, 5, INFO_BOARD_LENGTH, INFO_BOARD_WIDTH);
				textColorWithBackground(PURPLE, WHITE);
				drawChoiceBox(1, 5, INFO_BOARD_LENGTH + 1, INFO_BOARD_WIDTH + 1);
				infoSet(3);
				newInfiniteGame();
				textColorWithBackground(PURPLE, WHITE);
				drawChoiceBox(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH + 1);
				drawBlank(27, 6, 89, 19);
				gotoXY(50, 14);
				wcout << L"░▒█▀▀█░█▀▀▄░█▀▄▀█░█▀▀░▒█▀▀▀█░▄░░░▄░█▀▀░█▀▀▄";
				gotoXY(50, 15);
				wcout << L"░▒█░▄▄░█▄▄█░█░▀░█░█▀▀░▒█░░▒█░░█▄█░░█▀▀░█▄▄▀";
				gotoXY(50, 16);
				wcout << L"░▒█▄▄▀░▀░░▀░▀░░▒▀░▀▀▀░▒█▄▄▄█░░░▀░░░▀▀▀░▀░▀▀";
				cin.ignore();
			}
		}
		else if (choice.x == 1 && choice.y == 0) {
			gameTurtorial();
			cin.ignore();
		}
		else if (choice.x == 0 && choice.y == 1) {
			aboutUs();
			cin.ignore();
		}
		else {
			break;
		}
	}
	return 0;
}