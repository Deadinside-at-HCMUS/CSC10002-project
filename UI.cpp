#include <iostream>
#include "Init.h"
using namespace std;


void DrawBoard(int x, int y, int length, int width, int color) {
	TextColorWithBackground(color, WHITE);
	GotoXY(x, y);
	cout << static_cast<char>(220);
	for (int i = 1; i < length; i++)
		cout << static_cast<char>(220);
	cout << static_cast<char>(220);
	GotoXY(x, width + y);
	cout << static_cast<char>(223);
	for (int i = 0; i < length; i++)
		cout << static_cast<char>(223);

	for (int i = y + 1; i < width + y; i++)
	{
		GotoXY(x, i);
		cout << static_cast<char>(219);
		GotoXY(x + length, i);
		cout << static_cast<char>(219);
	}
}

void DrawSmallLogo(int x, int y) {
	TextColorWithBackground(DARK_YELLOW, WHITE);
	GotoXY(x, y);
	cout << char(176) << char(219) << char(223) << char(223) << char(176) << char(219) << char(223) << char(223) << char(220) << char(176) << char(219) << char(223) << char(223) << char(220) << char(176) << char(219) << char(176) << char(220) << char(176) << char(219) << char(223) << char(223) << char(176) << char(176) << char(176) << char(219) << char(223) << char(223) << char(223) << char(176) << char(219) << char(223) << char(223) << char(220) << char(176) << char(219) << char(223) << char(220) << char(223) << char(219) << char(176) << char(219) << char(223) << char(223) << endl;
	GotoXY(x, y + 1);
	cout << char(176) << char(223) << char(223) << char(220) << char(176) << char(219) << char(176) << char(177) << char(219) << char(176) << char(219) << char(220) << char(220) << char(219) << char(176) << char(219) << char(223) << char(220) << char(176) << char(219) << char(223) << char(223) << char(176) << char(176) << char(176) << char(219) << char(176) << char(223) << char(220) << char(176) << char(219) << char(220) << char(220) << char(219) << char(176) << char(219) << char(176) << char(223) << char(176) << char(219) << char(176) << char(219) << char(223) << char(223) << endl;
	GotoXY(x, y + 2);
	cout << char(176) << char(223) << char(223) << char(223) << char(176) << char(223) << char(176) << char(176) << char(219) << char(176) << char(223) << char(176) << char(176) << char(223) << char(176) << char(223) << char(176) << char(223) << char(176) << char(223) << char(223) << char(223) << char(176) << char(176) << char(176) << char(223) << char(223) << char(223) << char(223) << char(176) << char(223) << char(176) << char(176) << char(223) << char(176) << char(223) << char(176) << char(176) << char(177) << char(223) << char(176) << char(223) << char(223) << char(223) << endl;
}

void DrawChoiceBox(int x, int y, int length, int width) {
	GotoXY(x, y);
	cout << static_cast<char>(201);
	for (int i = 0; i < length - 1; ++i) {
		cout << static_cast<char>(205);
	}
	cout << static_cast<char>(187) << endl;
	for (int i = 1; i <= width - 2; ++i) {
		GotoXY(x, y + i);
		cout << static_cast<char>(186);
		GotoXY(x + length, y + i);
		cout << static_cast<char>(186);
	}
	GotoXY(x, y + width - 1);
	cout << static_cast<char>(200);
	for (int i = 0; i < length - 1; ++i) {
		cout << static_cast<char>(205);
	}
	cout << static_cast<char>(188) << endl;
}

void DrawBlank(int x, int y, int length, int width) {
	GotoXY(x, y);
	for (int i = 0; i < width + 2; i++) {
		GotoXY(x, y + i);
		for (int j = 0; j < length + 2; j++) {
			cout << ' ';
		}
	}
}

void Loading() {
	TextColorWithBackground(DARK_RED, WHITE);
	GotoXY(41, 4);
	cout << "       _                        __   " << endl;
	TextColorWithBackground(DARK_PINK, WHITE);
	GotoXY(41, 5);
	cout << " _ __ | |__   ___  _ __ ___    / /_  " << endl;
	TextColorWithBackground(DARK_YELLOW, WHITE);
	GotoXY(41, 6);
	cout << "| '_ \\| '_ \\ / _ \\| '_ ` _ \\  | '_ \\ " << endl;
	TextColorWithBackground(DARK_GREEN, WHITE);
	GotoXY(41, 7);
	cout << "| | | | | | | (_) | | | | | | | (_) |" << endl;
	TextColorWithBackground(DARK_CYAN, WHITE);
	GotoXY(41, 8);
	cout << "|_| |_|_| |_|\\___/|_| |_| |_|  \\___/ " << endl;

	TextColorWithBackground(DARK_RED, WHITE);
	GotoXY(42, 12);
	cout << "__                 _ _";
	TextColorWithBackground(DARK_PINK, WHITE);
	GotoXY(41, 13);
	cout << "/ /  ___   __ _  __| (_)_ __   __ _ ";
	TextColorWithBackground(DARK_YELLOW, WHITE);
	GotoXY(40, 14);
	cout << "/ /  / _ \\ / _` |/ _` | | '_ \\ / _` | ";
	TextColorWithBackground(DARK_GREEN, WHITE);
	GotoXY(39, 15);
	cout << "/ /__| (_) | (_| | (_| | | | | | (_| |_ _ _ ";
	TextColorWithBackground(DARK_CYAN, WHITE);
	GotoXY(36, 16);
	cout << "   \\____/\\___/ \\__,_|\\__,_|_|_| |_|\\__, (_|_|_) ";
	TextColorWithBackground(DARK_BLUE, WHITE);
	GotoXY(71, 17);
	cout << "|___/ ";
	for (int i = 0; i <= 109; i++) {
		TextColorWithBackground(DARK_GREEN, WHITE);
		GotoXY(i + 5, 21);
		cout << char(254);
	}
	GotoXY(5, 22);
	TextColorWithBackground(DARK_GREEN, WHITE);
	cout << char(124);
	GotoXY(5, 23);
	TextColorWithBackground(DARK_GREEN, WHITE);
	cout << char(124);
	GotoXY(114, 22);
	TextColorWithBackground(DARK_GREEN, WHITE);
	cout << char(124);
	GotoXY(114, 23);
	TextColorWithBackground(DARK_GREEN, WHITE);
	cout << char(124);

	for (int i = 0; i <= 109; i++) {
		TextColorWithBackground(DARK_GREEN, WHITE);
		GotoXY(i + 5, 24);
		cout << char(254);
	}
	for (int i = 1; i <= 108; i++)
	{
		TextColorWithBackground(202, WHITE);
		GotoXY(i + 5, 22);
		cout << char(219);
		TextColorWithBackground(202, WHITE);
		GotoXY(i + 5, 23);
		cout << char(219);
		Sleep(20);
	}
	TextColorWithBackground(7, WHITE);
	noCursorType();
}

void MainMenu() {
	system("cls");

	TextColorWithBackground(DARK_RED, WHITE);
	GotoXY(23, 4);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << " " << char(220) << char(220) << "    " << char(220) << " " << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << " " << char(220) << char(220) << char(220) << "   " << char(220) << " " << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << "    " << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << " " << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << " " << char(220) << char(220) << "   " << char(220) << char(220) << " " << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << endl;
	TextColorWithBackground(DARK_RED, WHITE);
	GotoXY(23, 5);
	cout << char(219) << "       " << char(219) << "  " << char(219) << "  " << char(219) << " " << char(219) << "      " << char(219) << "   " << char(219) << " " << char(219) << " " << char(219) << "       " << char(219) << "  " << char(219) << "       " << char(219) << "      " << char(219) << "  " << char(219) << char(220) << char(219) << "  " << char(219) << "       " << char(219) << endl;
	TextColorWithBackground(DARK_RED, WHITE);
	GotoXY(23, 6);
	cout << char(219) << "  " << char(220) << char(220) << char(220) << char(220) << char(220) << char(219) << "   " << char(219) << char(220) << char(219) << " " << char(219) << "  " << char(220) << "   " << char(219) << "   " << char(219) << char(220) << char(219) << " " << char(219) << "    " << char(220) << char(220) << char(220) << char(219) << "  " << char(219) << "   " << char(220) << char(220) << char(220) << char(220) << char(219) << "  " << char(220) << "   " << char(219) << "       " << char(219) << "    " << char(220) << char(220) << char(220) << char(219) << endl;
	TextColorWithBackground(DARK_RED, WHITE);
	GotoXY(23, 7);
	cout << char(219) << " " << char(219) << char(220) << char(220) << char(220) << char(220) << char(220) << char(219) << "       " << char(219) << " " << char(219) << char(220) << char(219) << "  " << char(219) << "      " << char(220) << char(219) << "   " << char(219) << char(220) << char(220) << char(220) << "   " << char(219) << "  " << char(219) << "  " << char(220) << char(220) << char(219) << " " << char(219) << char(220) << char(219) << "  " << char(219) << "       " << char(219) << "   " << char(219) << char(220) << char(220) << char(220) << endl;
	TextColorWithBackground(DARK_RED, WHITE);
	GotoXY(23, 8);
	cout << char(219) << char(220) << char(220) << char(220) << char(220) << char(220) << "  " << char(219) << "  " << char(220) << "    " << char(219) << "      " << char(219) << "     " << char(219) << char(220) << char(219) << "    " << char(220) << char(220) << char(220) << char(219) << "  " << char(219) << "  " << char(219) << " " << char(219) << "  " << char(219) << "      " << char(219) << "       " << char(219) << "    " << char(220) << char(220) << char(220) << char(219) << endl;
	TextColorWithBackground(DARK_RED, WHITE);
	GotoXY(23, 9);
	cout << " " << char(220) << char(220) << char(220) << char(220) << char(220) << char(219) << " " << char(219) << " " << char(219) << " " << char(219) << "   " << char(219) << "  " << char(220) << "   " << char(219) << "    " << char(220) << "  " << char(219) << "   " << char(219) << char(220) << char(220) << char(220) << "   " << char(219) << "  " << char(219) << char(220) << char(220) << char(219) << " " << char(219) << "  " << char(220) << "   " << char(219) << " " << char(219) << char(219) << char(220) << char(219) << char(219) << " " << char(219) << "   " << char(219) << char(220) << char(220) << char(220) << endl;
	TextColorWithBackground(DARK_RED, WHITE);
	GotoXY(23, 10);
	cout << char(219) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(219) << char(220) << char(219) << "  " << char(219) << char(220) << char(220) << char(219) << char(220) << char(219) << " " << char(219) << char(220) << char(220) << char(219) << char(220) << char(220) << char(220) << char(219) << " " << char(219) << char(220) << char(219) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(219) << "  " << char(219) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(219) << char(220) << char(219) << " " << char(219) << char(220) << char(220) << char(219) << char(220) << char(219) << "   " << char(219) << char(220) << char(219) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(219) << endl;
	TextColorWithBackground(DARK_RED, WHITE);
	DrawChoiceBox(27, 14, 17, 3);
	GotoXY(34, 15);
	cout << "PLAY" << endl;
	TextColorWithBackground(DARK_YELLOW, WHITE);
	DrawChoiceBox(75, 14, 17, 3);
	GotoXY(77, 15);
	cout << "GAME TURTORIAL" << endl;
	DrawChoiceBox(27, 22, 17, 3);
	GotoXY(32, 23);
	cout << "ABOUT US";
	DrawChoiceBox(75, 22, 17, 3);
	GotoXY(82, 23);
	cout << "EXIT" << endl;
}

POSITION InputMainMenu() {
	POSITION choice {0, 0};
	POSITION prechoice{0, 0};
	while (true) {
		if (_kbhit()) {
			switch (_getch()) {
			case 'a': case LEFT_ARROW:
				if (choice.x == 1) {
					prechoice = choice;
					choice.x--;
					InputMenuBoxEffect(prechoice, DARK_YELLOW);
					InputMenuBoxEffect(choice, DARK_RED);
				}
				break;
			case 'w': case UP_ARROW:
				prechoice = choice;
				if (choice.y == 1) {
					prechoice = choice;
					choice.y--;
					InputMenuBoxEffect(prechoice, DARK_YELLOW);
					InputMenuBoxEffect(choice, DARK_RED);
				}
				break;
			case 's': case DOWN_ARROW:
				prechoice = choice;
				if (choice.y == 0) {
					prechoice = choice;
					choice.y++;
					InputMenuBoxEffect(prechoice, DARK_YELLOW);
					InputMenuBoxEffect(choice, DARK_RED);
				}
				break;
			case 'd': case RIGHT_ARROW:
				prechoice = choice;
				if (choice.x == 0) {
					prechoice = choice;
					choice.x++;
					InputMenuBoxEffect(prechoice, DARK_YELLOW);
					InputMenuBoxEffect(choice, DARK_RED);
				}
				break;
			case enter:
				return choice;
			}
		}
	}
}

void InputMenuBoxEffect(POSITION choice, int color) {
	if (choice.x == 0 && choice.y == 0) {
		// DrawBlank(27, 14, 17, 3);
		TextColorWithBackground(color, WHITE);
		DrawChoiceBox(27, 14, 17, 3);
		GotoXY(34, 15);
		cout << "PLAY";
	}
	if (choice.x == 1 && choice.y == 0) {
		// DrawBlank(75, 14, 17, 3);
		TextColorWithBackground(color, WHITE);
		DrawChoiceBox(75, 14, 17, 3);
		GotoXY(77, 15);
		cout << "GAME TURTORIAL";
	}
	if (choice.x == 0 && choice.y == 1) {
		// DrawBlank(27, 22, 17, 3);
		TextColorWithBackground(color, WHITE);
		DrawChoiceBox(27, 22, 17, 3);
		GotoXY(32, 23);
		cout << "ABOUT US";
	}
	if (choice.x == 1 && choice.y == 1) {
		// DrawBlank(75, 22, 17, 3);
		TextColorWithBackground(color, WHITE);
		DrawChoiceBox(75, 22, 17, 3);
		GotoXY(82, 23);
		cout << "EXIT";
	}

}

void PlayMenu() {
	// logo
	DrawSmallLogo(38, 1);

	// box choice
	TextColorWithBackground(DARK_RED, WHITE);
	DrawChoiceBox(1, 7, 22, 5);
	GotoXY(9, 9);
	cout << "CLASSIC";
	TextColorWithBackground(DARK_YELLOW, WHITE);
	DrawChoiceBox(1, 14, 22, 5);
	GotoXY(8, 16);
	cout << "TIME RUSH";
	DrawChoiceBox(1, 21, 22, 5);
	GotoXY(11, 23);
	cout << "PvP";

	// game simulator
	TextColorWithBackground(DARK_GREEN, WHITE);
	DrawBoard(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH, PURPLE);

}

void InputPlayBoxEffect(POSITION choice, int color) {
	if (choice.y == 0) {
		TextColorWithBackground(color, WHITE);
		DrawChoiceBox(1, 7, 22, 5);
		GotoXY(9, 9);
		cout << "CLASSIC";
	} else if (choice.y == 1) {
		TextColorWithBackground(color, WHITE);
		DrawChoiceBox(1, 14, 22, 5);
		GotoXY(8, 16);
		cout << "TIME RUSH";
	} else {
		TextColorWithBackground(color, WHITE);
		DrawChoiceBox(1, 21, 22, 5);
		GotoXY(11, 23);
		cout << "PvP";
	}
}

POSITION InputPlayMenu() {
	POSITION choice {0, 0};
	POSITION prechoice {0, 0};
	while (true) {
		if (_kbhit()) {
			switch (_getch()) {
			case 'w': case UP_ARROW:
				if (choice.y != 0) {
					prechoice = choice;
					choice.y--;
					InputPlayBoxEffect(prechoice, DARK_YELLOW);
					InputPlayBoxEffect(choice, DARK_RED);
				}
				break;
			case 's': case DOWN_ARROW:
				if (choice.y != 2) {
					prechoice = choice;
					choice.y++;
					InputPlayBoxEffect(prechoice, DARK_YELLOW);
					InputPlayBoxEffect(choice, DARK_RED);
				}
				break;
			case enter:
				return choice;
			}
		}
	}
}

void InfoBoard(int x, int y) {
	DrawBlank(x, y, INFO_BOARD_LENGTH, INFO_BOARD_WIDTH);
	GotoXY(x, y);
	TextColorWithBackground(PURPLE, WHITE);
	for (int i = 0; i < INFO_BOARD_LENGTH + 2; ++i) {
		cout << static_cast<char>(220);
		Sleep(10);
	}
	for (int i = 1; i < INFO_BOARD_WIDTH; ++i) {
		GotoXY(x + INFO_BOARD_LENGTH + 1, y + i);
		cout << static_cast<char>(219);
		Sleep(10);
	}
	for (int i = x + INFO_BOARD_LENGTH; i >= x - 1; --i) {
		GotoXY(x + i, y + INFO_BOARD_WIDTH);
		cout << static_cast<char>(223);
		Sleep(10);
	}
	for (int i = y + INFO_BOARD_WIDTH - 1; i > y; --i) {
		GotoXY(x, i);
		cout << static_cast<char>(219);
		Sleep(10);
	}

	
	_getch();
}

void GameTurtorial() {
	system("cls");
	// TextColorWithBackground(DARK_GREEN, WHITE);
	// DrawBoard(30, 4, 60, 15);

	TextColorWithBackground(DARK_YELLOW, WHITE);
	GotoXY(20, 6);
	cout << "Snake moving: " << endl;
	GotoXY(20, 8);
	cout << ">> Using A to move left." << endl;
	GotoXY(20, 10);
	cout << ">> Using S to move down." << endl;
	GotoXY(20, 12);
	cout << ">> Using W to move up." << endl;
	GotoXY(20, 14);
	cout << ">> Using D to move right." << endl;
	GotoXY(20, 16);
	cout << "Gameplay working: " << endl;
	GotoXY(20, 18);
	cout << ">> Eating fruit to get more point and speed." << endl;
	GotoXY(20, 20);
	cout << ">> Avoiding the obstacles, avoid hitting the tail." << endl;
	GotoXY(20, 22);
	cout << ">> Go through gate to move to the next stage." << endl;
	
}

void AboutUs() {
	system("cls");
	DrawBoard(20, 6, 78, 11, DARK_GREEN);

	TextColorWithBackground(DARK_YELLOW, WHITE);
	GotoXY(30, 8);
	cout << "Snake Game Project - Programming Technique - Class: 21CLC07" << endl;
	GotoXY(40, 9);
	cout << "Supporting Teacher: Mr.Truong Toan Thinh" << endl;
	GotoXY(55, 11);
	cout << "Group 6:" << endl;
	GotoXY(45, 12);
	cout << "21127294 - Nguyen Hi Huu" << endl;
	GotoXY(45, 13);
	cout << "21127419 - Ngo Phuoc Tai" << endl;
	GotoXY(45, 14);
	cout << "21127175 - Le Anh Thu" << endl;
	GotoXY(45, 15);
	cout << "21127693 - Huynh Duc Thien" << endl;

}