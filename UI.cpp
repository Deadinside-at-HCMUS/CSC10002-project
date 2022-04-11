#include "Init.h"
using namespace std;


void drawBoard(int x, int y, int length, int width, int color) {
	textColorWithBackground(color, WHITE);
	gotoXY(x, y);
	cout << static_cast<char>(220);
	for (int i = 1; i < length; i++)
		cout << static_cast<char>(220);
	cout << static_cast<char>(220);
	gotoXY(x, width + y);
	cout << static_cast<char>(223);
	for (int i = 0; i < length; i++)
		cout << static_cast<char>(223);

	for (int i = y + 1; i < width + y; i++)
	{
		gotoXY(x, i);
		cout << static_cast<char>(219);
		gotoXY(x + length, i);
		cout << static_cast<char>(219);
	}
}

void drawSmallLogo(int x, int y) {
	textColorWithBackground(DARK_YELLOW, WHITE);
	gotoXY(x, y);
	cout << char(176) << char(219) << char(223) << char(223) << char(176) << char(219) << char(223) << char(223) << char(220) << char(176) << char(219) << char(223) << char(223) << char(220) << char(176) << char(219) << char(176) << char(220) << char(176) << char(219) << char(223) << char(223) << char(176) << char(176) << char(176) << char(219) << char(223) << char(223) << char(223) << char(176) << char(219) << char(223) << char(223) << char(220) << char(176) << char(219) << char(223) << char(220) << char(223) << char(219) << char(176) << char(219) << char(223) << char(223) << endl;
	gotoXY(x, y + 1);
	cout << char(176) << char(223) << char(223) << char(220) << char(176) << char(219) << char(176) << char(177) << char(219) << char(176) << char(219) << char(220) << char(220) << char(219) << char(176) << char(219) << char(223) << char(220) << char(176) << char(219) << char(223) << char(223) << char(176) << char(176) << char(176) << char(219) << char(176) << char(223) << char(220) << char(176) << char(219) << char(220) << char(220) << char(219) << char(176) << char(219) << char(176) << char(223) << char(176) << char(219) << char(176) << char(219) << char(223) << char(223) << endl;
	gotoXY(x, y + 2);
	cout << char(176) << char(223) << char(223) << char(223) << char(176) << char(223) << char(176) << char(176) << char(219) << char(176) << char(223) << char(176) << char(176) << char(223) << char(176) << char(223) << char(176) << char(223) << char(176) << char(223) << char(223) << char(223) << char(176) << char(176) << char(176) << char(223) << char(223) << char(223) << char(223) << char(176) << char(223) << char(176) << char(176) << char(223) << char(176) << char(223) << char(176) << char(176) << char(177) << char(223) << char(176) << char(223) << char(223) << char(223) << endl;
}

void drawChoiceBox(int x, int y, int length, int width) {
	gotoXY(x, y);
	cout << static_cast<char>(201);
	for (int i = 0; i < length - 1; ++i) {
		cout << static_cast<char>(205);
	}
	cout << static_cast<char>(187) << endl;
	for (int i = 1; i <= width - 2; ++i) {
		gotoXY(x, y + i);
		cout << static_cast<char>(186);
		gotoXY(x + length, y + i);
		cout << static_cast<char>(186);
	}
	gotoXY(x, y + width - 1);
	cout << static_cast<char>(200);
	for (int i = 0; i < length - 1; ++i) {
		cout << static_cast<char>(205);
	}
	cout << static_cast<char>(188) << endl;
}

void drawBlank(int x, int y, int length, int width) {
	gotoXY(x, y);
	for (int i = 0; i < width + 2; i++) {
		gotoXY(x, y + i);
		for (int j = 0; j < length + 2; j++) {
			cout << ' ';
		}
	}
}

void loading() {
	textColorWithBackground(DARK_RED, WHITE);
	gotoXY(41, 4);
	cout << "       _                        __   " << endl;
	textColorWithBackground(DARK_PINK, WHITE);
	gotoXY(41, 5);
	cout << " _ __ | |__   ___  _ __ ___    / /_  " << endl;
	textColorWithBackground(DARK_YELLOW, WHITE);
	gotoXY(41, 6);
	cout << "| '_ \\| '_ \\ / _ \\| '_ ` _ \\  | '_ \\ " << endl;
	textColorWithBackground(DARK_GREEN, WHITE);
	gotoXY(41, 7);
	cout << "| | | | | | | (_) | | | | | | | (_) |" << endl;
	textColorWithBackground(DARK_CYAN, WHITE);
	gotoXY(41, 8);
	cout << "|_| |_|_| |_|\\___/|_| |_| |_|  \\___/ " << endl;

	textColorWithBackground(DARK_RED, WHITE);
	gotoXY(42, 12);
	cout << "__                 _ _";
	textColorWithBackground(DARK_PINK, WHITE);
	gotoXY(41, 13);
	cout << "/ /  ___   __ _  __| (_)_ __   __ _ ";
	textColorWithBackground(DARK_YELLOW, WHITE);
	gotoXY(40, 14);
	cout << "/ /  / _ \\ / _` |/ _` | | '_ \\ / _` | ";
	textColorWithBackground(DARK_GREEN, WHITE);
	gotoXY(39, 15);
	cout << "/ /__| (_) | (_| | (_| | | | | | (_| |_ _ _ ";
	textColorWithBackground(DARK_CYAN, WHITE);
	gotoXY(36, 16);
	cout << "   \\____/\\___/ \\__,_|\\__,_|_|_| |_|\\__, (_|_|_) ";
	textColorWithBackground(DARK_BLUE, WHITE);
	gotoXY(71, 17);
	cout << "|___/ ";
	for (int i = 0; i <= 109; i++) {
		textColorWithBackground(DARK_GREEN, WHITE);
		gotoXY(i + 5, 21);
		cout << char(254);
	}
	gotoXY(5, 22);
	textColorWithBackground(DARK_GREEN, WHITE);
	cout << char(124);
	gotoXY(5, 23);
	textColorWithBackground(DARK_GREEN, WHITE);
	cout << char(124);
	gotoXY(114, 22);
	textColorWithBackground(DARK_GREEN, WHITE);
	cout << char(124);
	gotoXY(114, 23);
	textColorWithBackground(DARK_GREEN, WHITE);
	cout << char(124);

	for (int i = 0; i <= 109; i++) {
		textColorWithBackground(DARK_GREEN, WHITE);
		gotoXY(i + 5, 24);
		cout << char(254);
	}
	for (int i = 1; i <= 108; i++)
	{
		textColorWithBackground(202, WHITE);
		gotoXY(i + 5, 22);
		cout << char(219);
		textColorWithBackground(202, WHITE);
		gotoXY(i + 5, 23);
		cout << char(219);
		Sleep(20);
	}
	textColorWithBackground(7, WHITE);
}

void mainMenu() {
	system("cls");

	textColorWithBackground(DARK_RED, WHITE);
	gotoXY(23, 4);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << " " << char(220) << char(220) << "    " << char(220) << " " << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << " " << char(220) << char(220) << char(220) << "   " << char(220) << " " << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << "    " << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << " " << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << " " << char(220) << char(220) << "   " << char(220) << char(220) << " " << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << endl;
	textColorWithBackground(DARK_RED, WHITE);
	gotoXY(23, 5);
	cout << char(219) << "       " << char(219) << "  " << char(219) << "  " << char(219) << " " << char(219) << "      " << char(219) << "   " << char(219) << " " << char(219) << " " << char(219) << "       " << char(219) << "  " << char(219) << "       " << char(219) << "      " << char(219) << "  " << char(219) << char(220) << char(219) << "  " << char(219) << "       " << char(219) << endl;
	textColorWithBackground(DARK_RED, WHITE);
	gotoXY(23, 6);
	cout << char(219) << "  " << char(220) << char(220) << char(220) << char(220) << char(220) << char(219) << "   " << char(219) << char(220) << char(219) << " " << char(219) << "  " << char(220) << "   " << char(219) << "   " << char(219) << char(220) << char(219) << " " << char(219) << "    " << char(220) << char(220) << char(220) << char(219) << "  " << char(219) << "   " << char(220) << char(220) << char(220) << char(220) << char(219) << "  " << char(220) << "   " << char(219) << "       " << char(219) << "    " << char(220) << char(220) << char(220) << char(219) << endl;
	textColorWithBackground(DARK_RED, WHITE);
	gotoXY(23, 7);
	cout << char(219) << " " << char(219) << char(220) << char(220) << char(220) << char(220) << char(220) << char(219) << "       " << char(219) << " " << char(219) << char(220) << char(219) << "  " << char(219) << "      " << char(220) << char(219) << "   " << char(219) << char(220) << char(220) << char(220) << "   " << char(219) << "  " << char(219) << "  " << char(220) << char(220) << char(219) << " " << char(219) << char(220) << char(219) << "  " << char(219) << "       " << char(219) << "   " << char(219) << char(220) << char(220) << char(220) << endl;
	textColorWithBackground(DARK_RED, WHITE);
	gotoXY(23, 8);
	cout << char(219) << char(220) << char(220) << char(220) << char(220) << char(220) << "  " << char(219) << "  " << char(220) << "    " << char(219) << "      " << char(219) << "     " << char(219) << char(220) << char(219) << "    " << char(220) << char(220) << char(220) << char(219) << "  " << char(219) << "  " << char(219) << " " << char(219) << "  " << char(219) << "      " << char(219) << "       " << char(219) << "    " << char(220) << char(220) << char(220) << char(219) << endl;
	textColorWithBackground(DARK_RED, WHITE);
	gotoXY(23, 9);
	cout << " " << char(220) << char(220) << char(220) << char(220) << char(220) << char(219) << " " << char(219) << " " << char(219) << " " << char(219) << "   " << char(219) << "  " << char(220) << "   " << char(219) << "    " << char(220) << "  " << char(219) << "   " << char(219) << char(220) << char(220) << char(220) << "   " << char(219) << "  " << char(219) << char(220) << char(220) << char(219) << " " << char(219) << "  " << char(220) << "   " << char(219) << " " << char(219) << char(219) << char(220) << char(219) << char(219) << " " << char(219) << "   " << char(219) << char(220) << char(220) << char(220) << endl;
	textColorWithBackground(DARK_RED, WHITE);
	gotoXY(23, 10);
	cout << char(219) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(219) << char(220) << char(219) << "  " << char(219) << char(220) << char(220) << char(219) << char(220) << char(219) << " " << char(219) << char(220) << char(220) << char(219) << char(220) << char(220) << char(220) << char(219) << " " << char(219) << char(220) << char(219) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(219) << "  " << char(219) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(219) << char(220) << char(219) << " " << char(219) << char(220) << char(220) << char(219) << char(220) << char(219) << "   " << char(219) << char(220) << char(219) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(219) << endl;
	textColorWithBackground(DARK_RED, WHITE);
	drawChoiceBox(27, 14, 17, 3);
	gotoXY(34, 15);
	cout << "PLAY" << endl;
	textColorWithBackground(DARK_YELLOW, WHITE);
	drawChoiceBox(75, 14, 17, 3);
	gotoXY(77, 15);
	cout << "GAME TURTORIAL" << endl;
	drawChoiceBox(27, 22, 17, 3);
	gotoXY(32, 23);
	cout << "ABOUT US";
	drawChoiceBox(75, 22, 17, 3);
	gotoXY(82, 23);
	cout << "EXIT" << endl;
}

POSITION inputMainMenu() {
	POSITION choice {0, 0};
	POSITION prechoice{0, 0};
	while (true) {
		if (_kbhit()) {
			switch (_getch()) {
			case 'a': case LEFT_ARROW:
				if (choice.x == 1) {
					prechoice = choice;
					choice.x--;
					inputMenuBoxEffect(prechoice, DARK_YELLOW);
					inputMenuBoxEffect(choice, DARK_RED);
				}
				break;
			case 'w': case UP_ARROW:
				prechoice = choice;
				if (choice.y == 1) {
					prechoice = choice;
					choice.y--;
					inputMenuBoxEffect(prechoice, DARK_YELLOW);
					inputMenuBoxEffect(choice, DARK_RED);
				}
				break;
			case 's': case DOWN_ARROW:
				prechoice = choice;
				if (choice.y == 0) {
					prechoice = choice;
					choice.y++;
					inputMenuBoxEffect(prechoice, DARK_YELLOW);
					inputMenuBoxEffect(choice, DARK_RED);
				}
				break;
			case 'd': case RIGHT_ARROW:
				prechoice = choice;
				if (choice.x == 0) {
					prechoice = choice;
					choice.x++;
					inputMenuBoxEffect(prechoice, DARK_YELLOW);
					inputMenuBoxEffect(choice, DARK_RED);
				}
				break;
			case enter:
				return choice;
			}
		}
	}
}

void inputMenuBoxEffect(POSITION choice, int color) {
	if (choice.x == 0 && choice.y == 0) {
		// DrawBlank(27, 14, 17, 3);
		textColorWithBackground(color, WHITE);
		drawChoiceBox(27, 14, 17, 3);
		gotoXY(34, 15);
		cout << "PLAY";
	}
	if (choice.x == 1 && choice.y == 0) {
		// DrawBlank(75, 14, 17, 3);
		textColorWithBackground(color, WHITE);
		drawChoiceBox(75, 14, 17, 3);
		gotoXY(77, 15);
		cout << "GAME TURTORIAL";
	}
	if (choice.x == 0 && choice.y == 1) {
		// DrawBlank(27, 22, 17, 3);
		textColorWithBackground(color, WHITE);
		drawChoiceBox(27, 22, 17, 3);
		gotoXY(32, 23);
		cout << "ABOUT US";
	}
	if (choice.x == 1 && choice.y == 1) {
		// DrawBlank(75, 22, 17, 3);
		textColorWithBackground(color, WHITE);
		drawChoiceBox(75, 22, 17, 3);
		gotoXY(82, 23);
		cout << "EXIT";
	}

}

void playMenu() {
	// logo
	drawSmallLogo(38, 1);

	// box choice
	textColorWithBackground(DARK_RED, WHITE);
	drawChoiceBox(1, 7, 22, 5);
	gotoXY(9, 9);
	cout << "CLASSIC";
	textColorWithBackground(DARK_YELLOW, WHITE);
	drawChoiceBox(1, 14, 22, 5);
	gotoXY(8, 16);
	cout << "TIME RUSH";
	drawChoiceBox(1, 21, 22, 5);
	gotoXY(8, 23);
	cout << "INFINITE";

	// game simulator
	textColorWithBackground(DARK_GREEN, WHITE);
	drawBoard(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH, PURPLE);

}

void inputPlayBoxEffect(POSITION choice, int color) {
	if (choice.y == 0) {
		textColorWithBackground(color, WHITE);
		drawChoiceBox(1, 7, 22, 5);
		gotoXY(9, 9);
		cout << "CLASSIC";
	} else if (choice.y == 1) {
		textColorWithBackground(color, WHITE);
		drawChoiceBox(1, 14, 22, 5);
		gotoXY(8, 16);
		cout << "TIME RUSH";
	} else {
		textColorWithBackground(color, WHITE);
		drawChoiceBox(1, 21, 22, 5);
		gotoXY(8, 23);
		cout << "INFINITE";
	}
}

POSITION inputPlayMenu() {
	POSITION choice {0, 0};
	POSITION prechoice {0, 0};
	while (true) {
		if (_kbhit()) {
			switch (_getch()) {
			case 'w': case UP_ARROW:
				if (choice.y != 0) {
					prechoice = choice;
					choice.y--;
					inputPlayBoxEffect(prechoice, DARK_YELLOW);
					inputPlayBoxEffect(choice, DARK_RED);
				}
				break;
			case 's': case DOWN_ARROW:
				if (choice.y != 2) {
					prechoice = choice;
					choice.y++;
					inputPlayBoxEffect(prechoice, DARK_YELLOW);
					inputPlayBoxEffect(choice, DARK_RED);
				}
				break;
			case enter:
				return choice;
			}
		}
	}
}

int inputTimeChoice() {
	drawBoard(57, 9, 30, 9, PINK);
	gotoXY(67, 11);
	cout << "[1] Map 1";
	gotoXY(67, 12);
	cout << "[2] Map 2";
	gotoXY(67, 13);
	cout << "[3] Map 3";
	gotoXY(67, 14);
	cout << "[4] Map 4";
	gotoXY(67, 15);
	cout << "[5] Map 5";
	drawBoard(57, 18, 30, 4, PINK);
	gotoXY(57, 18);
	for (int i = 0; i < 31; i++) {
		cout << char(BLOCK);
	}
	gotoXY(66, 20);
	cout << "Chose a map: ";
	int choice;
	cin >> choice;
	choice = choice % 5;
	if (choice == 0) choice = 5;
	return choice;

}

void infoBoard(int x, int y) {
	drawBlank(x, y, INFO_BOARD_LENGTH, INFO_BOARD_WIDTH);
	gotoXY(x, y);
	textColorWithBackground(PURPLE, WHITE);
	for (int i = 0; i < INFO_BOARD_LENGTH + 2; ++i) {
		textColorWithBackground(PURPLE, WHITE);
		cout << static_cast<char>(220);
		Sleep(10);
	}
	for (int i = 1; i < INFO_BOARD_WIDTH; ++i) {
		gotoXY(x + INFO_BOARD_LENGTH + 1, y + i);
		textColorWithBackground(PURPLE, WHITE);
		cout << static_cast<char>(219);
		Sleep(10);
	}
	for (int i = x + INFO_BOARD_LENGTH; i >= x - 1; --i) {
		gotoXY(x + i, y + INFO_BOARD_WIDTH);
		textColorWithBackground(PURPLE, WHITE);
		cout << static_cast<char>(223);
		Sleep(10);
	}
	for (int i = y + INFO_BOARD_WIDTH - 1; i > y; --i) {
		gotoXY(x, i);
		textColorWithBackground(PURPLE, WHITE);
		cout << static_cast<char>(219);
		Sleep(10);
	}

}

void infoSet(int type) {
	textColorWithBackground(DARK_YELLOW, WHITE);
	if (type == 1) {
		gotoXY(3, 7);
		cout << "Stage: ";
	}
	if (type == 3) {
		gotoXY(3, 7);
		cout << "Speed: ";
	}

	gotoXY(3, 9);
	cout << "Score: ";

	gotoXY(3, 11);
	cout << "(p): Pause";

}

void gameTurtorial() {
	system("cls");
	// textColorWithBackground(DARK_GREEN, WHITE);
	// DrawBoard(30, 4, 60, 15);

	textColorWithBackground(DARK_YELLOW, WHITE);
	gotoXY(20, 6);
	cout << "Snake moving: " << endl;
	gotoXY(20, 8);
	cout << ">> Using A to move left." << endl;
	gotoXY(20, 10);
	cout << ">> Using S to move down." << endl;
	gotoXY(20, 12);
	cout << ">> Using W to move up." << endl;
	gotoXY(20, 14);
	cout << ">> Using D to move right." << endl;
	gotoXY(20, 16);
	cout << "Gameplay working: " << endl;
	gotoXY(20, 18);
	cout << ">> Eating fruit to get more point and speed." << endl;
	gotoXY(20, 20);
	cout << ">> Avoiding the obstacles, avoid hitting the tail." << endl;
	gotoXY(20, 22);
	cout << ">> Go through gate to move to the next stage." << endl;
	
}

void aboutUs() {
	system("cls");
	drawBoard(20, 6, 78, 11, DARK_GREEN);

	textColorWithBackground(DARK_YELLOW, WHITE);
	gotoXY(30, 8);
	cout << "Snake Game Project - Programming Technique - Class: 21CLC07" << endl;
	gotoXY(40, 9);
	cout << "Supporting Teacher: Mr.Truong Toan Thinh" << endl;
	gotoXY(55, 11);
	cout << "Group 6:" << endl;
	gotoXY(45, 12);
	cout << "21127294 - Nguyen Hi Huu" << endl;
	gotoXY(45, 13);
	cout << "21127419 - Ngo Phuoc Tai" << endl;
	gotoXY(45, 14);
	cout << "21127175 - Le Anh Thu" << endl;
	gotoXY(45, 15);
	cout << "21127693 - Huynh Duc Thien" << endl;

}

void deathEffect(SNAKE* snake) {
	for (int i = snake->size; i >= 0; i--) {
		drawChar(snake->part[i].x, snake->part[i].y, DARK_YELLOW, ' ');
		Sleep(60);
	}
	drawChar(snake->part[0].x, snake->part[0].y, DARK_RED, '*');
	Sleep(120);
	for (int i = 0; i < 7; i++) {
		if (i == 0)
		{
			drawChar(snake->part[0].x, snake->part[0].y, DARK_RED, '#');
			drawChar(snake->part[0].x - 1, snake->part[0].y, DARK_RED, '*');
			drawChar(snake->part[0].x + 1, snake->part[0].y, DARK_RED, '*');
			Sleep(120);
		}
		if (i == 1)
		{
			drawChar(snake->part[0].x, snake->part[0].y, DARK_RED, '@');
			drawChar(snake->part[0].x - 1, snake->part[0].y, DARK_RED, '#');
			drawChar(snake->part[0].x + 1, snake->part[0].y, DARK_RED, '#');
			drawChar(snake->part[0].x, snake->part[0].y - 1, DARK_RED, '#');
			drawChar(snake->part[0].x, snake->part[0].y + 1, DARK_RED, '#');
			drawChar(snake->part[0].x - 1, snake->part[0].y - 1, DARK_RED, '*');
			drawChar(snake->part[0].x + 1, snake->part[0].y - 1, DARK_RED, '*');
			drawChar(snake->part[0].x - 1, snake->part[0].y + 1, DARK_RED, '*');
			drawChar(snake->part[0].x + 1, snake->part[0].y + 1, DARK_RED, '*');
			Sleep(120);
		}
		if (i == 2)
		{
			{
				drawChar(snake->part[0].x, snake->part[0].y, DARK_RED, '@');
				drawChar(snake->part[0].x - 1, snake->part[0].y, DARK_RED, '#');
				drawChar(snake->part[0].x - 2, snake->part[0].y, DARK_RED, '#');
				drawChar(snake->part[0].x - 3, snake->part[0].y, DARK_RED, '*');
				drawChar(snake->part[0].x + 1, snake->part[0].y, DARK_RED, '#');
				drawChar(snake->part[0].x + 2, snake->part[0].y, DARK_RED, '#');
				drawChar(snake->part[0].x + 3, snake->part[0].y, DARK_RED, '*');
				drawChar(snake->part[0].x, snake->part[0].y + 1, DARK_RED, '#');
				drawChar(snake->part[0].x, snake->part[0].y + 2, DARK_RED, '#');
				drawChar(snake->part[0].x, snake->part[0].y + 3, DARK_RED, '*');
				drawChar(snake->part[0].x, snake->part[0].y - 1, DARK_RED, '#');
				drawChar(snake->part[0].x, snake->part[0].y - 2, DARK_RED, '#');
				drawChar(snake->part[0].x, snake->part[0].y - 3, DARK_RED, '*');
				drawChar(snake->part[0].x - 1, snake->part[0].y - 1, DARK_RED, '#');
				drawChar(snake->part[0].x - 2, snake->part[0].y - 1, DARK_RED, '*');
				drawChar(snake->part[0].x - 3, snake->part[0].y - 1, DARK_RED, '*');
				drawChar(snake->part[0].x + 1, snake->part[0].y - 1, DARK_RED, '#');
				drawChar(snake->part[0].x + 2, snake->part[0].y - 1, DARK_RED, '*');
				drawChar(snake->part[0].x + 3, snake->part[0].y - 1, DARK_RED, '*');
				drawChar(snake->part[0].x - 1, snake->part[0].y - 2, DARK_RED, '#');
				drawChar(snake->part[0].x - 2, snake->part[0].y - 2, DARK_RED, '*');
				drawChar(snake->part[0].x + 1, snake->part[0].y - 2, DARK_RED, '#');
				drawChar(snake->part[0].x + 2, snake->part[0].y - 2, DARK_RED, '*');
				drawChar(snake->part[0].x - 1, snake->part[0].y + 1, DARK_RED, '#');
				drawChar(snake->part[0].x - 2, snake->part[0].y + 1, DARK_RED, '*');
				drawChar(snake->part[0].x - 3, snake->part[0].y + 1, DARK_RED, '*');
				drawChar(snake->part[0].x + 1, snake->part[0].y + 1, DARK_RED, '#');
				drawChar(snake->part[0].x + 2, snake->part[0].y + 1, DARK_RED, '*');
				drawChar(snake->part[0].x + 3, snake->part[0].y + 1, DARK_RED, '*');
				drawChar(snake->part[0].x - 1, snake->part[0].y + 2, DARK_RED, '#');
				drawChar(snake->part[0].x - 2, snake->part[0].y + 2, DARK_RED, '*');
				drawChar(snake->part[0].x + 1, snake->part[0].y + 2, DARK_RED, '#');
				drawChar(snake->part[0].x + 2, snake->part[0].y + 2, DARK_RED, '*');
			}
			Sleep(120);
		}
		if (i == 3)
		{
			drawChar(snake->part[0].x, snake->part[0].y, DARK_YELLOW, ' ');
			Sleep(120);
		}
		if (i == 4)
		{
			drawChar(snake->part[0].x - 1, snake->part[0].y, DARK_YELLOW, ' ');
			drawChar(snake->part[0].x + 1, snake->part[0].y, DARK_YELLOW, ' ');
			Sleep(120);
		}
		if (i == 5)
		{
			drawChar(snake->part[0].x, snake->part[0].y - 1, DARK_YELLOW, ' ');
			drawChar(snake->part[0].x, snake->part[0].y + 1, DARK_YELLOW, ' ');
			drawChar(snake->part[0].x - 1, snake->part[0].y - 1, DARK_YELLOW, ' ');
			drawChar(snake->part[0].x + 1, snake->part[0].y - 1, DARK_YELLOW, ' ');
			drawChar(snake->part[0].x - 1, snake->part[0].y + 1, DARK_YELLOW, ' ');
			drawChar(snake->part[0].x + 1, snake->part[0].y + 1, DARK_YELLOW, ' ');
			Sleep(120);
		}
		if (i == 6)
		{
			{
				drawChar(snake->part[0].x - 2, snake->part[0].y, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x - 3, snake->part[0].y, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x + 2, snake->part[0].y, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x + 3, snake->part[0].y, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x, snake->part[0].y + 2, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x, snake->part[0].y + 3, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x, snake->part[0].y - 2, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x, snake->part[0].y - 3, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x - 2, snake->part[0].y - 1, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x - 3, snake->part[0].y - 1, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x + 2, snake->part[0].y - 1, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x + 3, snake->part[0].y - 1, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x - 1, snake->part[0].y - 2, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x - 2, snake->part[0].y - 2, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x + 1, snake->part[0].y - 2, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x + 2, snake->part[0].y - 2, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x - 2, snake->part[0].y + 1, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x - 3, snake->part[0].y + 1, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x + 2, snake->part[0].y + 1, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x + 3, snake->part[0].y + 1, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x - 1, snake->part[0].y + 2, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x - 2, snake->part[0].y + 2, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x + 1, snake->part[0].y + 2, DARK_YELLOW, ' ');
				drawChar(snake->part[0].x + 2, snake->part[0].y + 2, DARK_YELLOW, ' ');
			}
			Sleep(120);
		}
	}
}

void pauseGameBoard(int x, int y) {
	drawBlank(x, y, 23, 7);
	textColorWithBackground(PINK, WHITE);
	for (int i = 0; i < 8; ++i) {
		gotoXY(x + 21, y + i);
		cout << char(219);
		// Sleep(10);
	}
	for (int i = y + 8; i > y; --i) {
		gotoXY(x, i);
		cout << char(219);
		// Sleep(10);
	}
	gotoXY(x, y);
	for (int i = 0; i < 20 + 2; ++i) {
		cout << char(220);
		// Sleep(10);
	}
	for (int i = x + 20 + 1; i >= x; --i) {
		gotoXY(i, y + 8);
		cout << char(223);
		// Sleep(10);
	}

	gotoXY(x + 3, y + 2);
	cout << " (c): continue";
	gotoXY(x + 3, y + 4);
	cout << " (s): save game";
	gotoXY(x + 3, y + 6);
	cout << " (x): exit";

}

void renderTimeRush(SNAKE *snake, int& time) {
	textColorWithBackground(BLUE, WHITE);
	gotoXY(3, 15);
	cout << "TIME: ";
	gotoXY(3, 17);
	switch (time / 5) {
	case 5:
		cout << char(182) << char(219) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(199);
		break;
	case 10:
		cout << char(182) << char(219) << char(219) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(199);
		break;
	case 15:
		cout << char(182) << char(219) << char(219) << char(219) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(199);
		break;
	case 20:
		cout << char(182) << char(219) << char(219) << char(219) << char(219) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(199);
		break;
	case 25:
		cout << char(182) << char(219) << char(219) << char(219) << char(219) << char(219) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(199);
		break;
	case 30:
		cout << char(182) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(199);
		break;
	case 35:
		cout << char(182) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(199);
		break;
	case 40:
		cout << char(182) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(199);
		break;
	case 45:
		cout << char(182) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(176) << char(176) << char(176) << char(176) << char(176) << char(199);
		break;
	case 50:
		cout << char(182) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(176) << char(176) << char(176) << char(176) << char(199);
		break;
	case 55:
		cout << char(182) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(176) << char(176) << char(176) << char(199);
		break;
	case 60:
		cout << char(182) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(176) << char(176) << char(199);
		break;
	case 65:
		cout << char(182) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(176) << char(199);
		break;
	case 70:
		cout << char(182) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(199);
		break;
	case 71:
		cout << char(182) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(199);
		break;	
	case 72:
		cout << char(182) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(199);
		break;
	}
}

// sub menu
void inputSubChoiceEffect(POSITION choice, int color) {
	if (choice.y == 0) {
		textColorWithBackground(color, WHITE);
		drawChoiceBox(1, 10, 22, 5);
		gotoXY(8, 12);
		cout << "DIFFICULTY";
	} else {
		textColorWithBackground(color, WHITE);
		drawChoiceBox(1, 19, 22, 5);
		gotoXY(8, 21);
		cout << "LOAD GAME";
	}
}

POSITION inputSubChoiceMenu() {
	POSITION choice {0, 0};
	POSITION prechoice {0, 0};
	while (true) {
		if (_kbhit()) {
			switch (_getch()) {
			case 'w': case UP_ARROW:
				if (choice.y != 0) {
					prechoice = choice;
					choice.y--;
					inputSubChoiceEffect(prechoice, DARK_YELLOW);
					inputSubChoiceEffect(choice, DARK_RED);
				}
				break;
			case 's': case DOWN_ARROW:
				if (choice.y != 1) {
					prechoice = choice;
					choice.y++;
					inputSubChoiceEffect(prechoice, DARK_YELLOW);
					inputSubChoiceEffect(choice, DARK_RED);
				}
				break;
			case enter:
				return choice;
			}
		}
	}
}

POSITION subChoiceMenu() {
	drawBlank(1, 5, 21, 20);
	textColorWithBackground(DARK_RED, WHITE);
	drawChoiceBox(1, 10, 22, 5);
	gotoXY(8, 12);
	cout << "DIFFICULTY";

	textColorWithBackground(DARK_YELLOW, WHITE);
	drawChoiceBox(1, 19, 22, 5);
	gotoXY(8, 21);
	cout << "LOAD GAME";

	return inputSubChoiceMenu();
}

//difficulty
void hoverDifficultyyChoice(int choice, int prechoice) {
	textColorWithBackground(PURPLE, WHITE);
	switch (choice) {
		case 0:
			gotoXY(40, 11);
			cout << ">> Easy        ";
			break;
		case 1:
			gotoXY(40, 16);
			cout << ">> Normal      ";
			break;
		case 2:
			gotoXY(40, 21);
			cout << ">> Hard	    ";
			break;
	}

	textColorWithBackground(DARK_PINK, WHITE);
	switch (prechoice) {
		case 0:
			gotoXY(40, 11);
			cout << "Easy           ";
			break;
		case 1:
			gotoXY(40, 16);
			cout << "Normal         ";
			break;
		case 2:
			gotoXY(40, 21);
			cout << "Hard	        ";
			break;
	}
}

int inputDifficultyChoice(int choice) {
	int prechoice = choice + 1;
	while (true) {
		if (_kbhit()) {
			switch (_getch()) {
				case 's': case DOWN_ARROW:
					if (choice != 2) {
						prechoice = choice;
						choice++;
					}
					break;
				case 'w': case UP_ARROW:
					if (choice != 0) {
						prechoice = choice;
						choice--;
					}
					break;
				case enter:
					return choice;
			}
		}
		hoverDifficultyyChoice(choice, prechoice);
	}

}

int choseDifficulty() {
	int choice = 0;
	textColorWithBackground(PURPLE, WHITE);
	gotoXY(40, 11);
	cout << ">> Easy";
	textColorWithBackground(DARK_PINK, WHITE);
	gotoXY(40, 16);
	cout << "Normal";
	gotoXY(40, 21);
	cout << "Hard";
	return inputDifficultyChoice(choice);
}

//classic
void hoverClassicPlayerChoice(POSITION choice, POSITION prechoice, CLASSICDATA *data) {
	if (choice.y == prechoice.y && choice.x == prechoice.x) return;
	textColorWithBackground(PURPLE, WHITE);
	if (choice.x == 0) {
		gotoXY(28, 7 + 2 * choice.y);
		cout << ">> " << data[choice.y].classicname;
	} else {
		gotoXY(75, 7 + 2 * choice.y);
		cout << ">> " << data[choice.x * 10 + choice.y].classicname;
	}
	textColorWithBackground(DARK_PINK, WHITE);
	if (prechoice.x == 0) {
		gotoXY(28, 7 + 2 * choice.y);
		cout << data[choice.y].classicname << "   ";
	} else {
		gotoXY(75, 7 + 2 * choice.y);
		cout << data[choice.x * 10 + choice.y].classicname << "   ";
	}
}

POSITION choseClassicPlayer(POSITION choice, CLASSICDATA *data) {
	POSITION prechoice;
	prechoice = choice;
	while (true) {
		if (_kbhit()) {
			switch (_getch()) {
				case 'a': case LEFT_ARROW:
					if (choice.x != 0) {
						prechoice = choice;
						choice.x--;
					}
					break;
				case 's': case DOWN_ARROW:
					if (choice.y != 9) {
						prechoice = choice;
						choice.y++;
					}
					break;
				case 'w': case UP_ARROW:
					if (choice.y != 0) {
						prechoice = choice;
						choice.y--;
					}
					break;
				case 'd': case RIGHT_ARROW:
					if (choice.x != 1) {
						prechoice = choice;
						choice.x++;
					}
					break;
				case enter:
					return choice;
			}
		}
 		hoverClassicPlayerChoice(choice, prechoice, data);
	}

}

int loadSaveClassicPlayer(CLASSICDATA *data, int playercount) {
	if (playercount <= 0) {
		gotoXY(28, 7);
		cout << "Empty Data!";
	} else {
		drawBoard(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH, YELLOW);
		POSITION choice = {0, 0};
		textColorWithBackground(DARK_PINK, WHITE);
		if (playercount <= 10) {
			for (int i = 0; i < playercount; i++) {
				gotoXY(28, 7 + 2 * i);
				cout << data[i].classicname;
			}
		}
		if (playercount > 10 && playercount <= 20) {
			for (int i = 0; i < 10; i++) {
				gotoXY(28, 7 + 2 * i);
				cout << data[i].classicname;
			}
			for (int i = 10; i < playercount; i++) {
				gotoXY(75, 7 + 2 * (i - 10));
				cout << data[i].classicname;
			}
		}
		if (playercount > 20) {
			for (int i = 0; i < 10; i++) {
				gotoXY(28, 7 + 2 * i);
				cout << data[i].classicname;
			}
			for (int i = 10; i < 20; i++) {
				gotoXY(75, 7 + 2 * (i - 10));
				cout << data[i].classicname;
			}
		}
		textColorWithBackground(PURPLE, WHITE);
		gotoXY(28, 7 + 2 * choice.y);
		cout << ">> " << data[choice.y].classicname;
		choice = choseClassicPlayer(choice, data);
		return choice.x * 10 + choice.y;
	}

}

//time rush
void hoverTimeRushPlayerChoice(POSITION choice, POSITION prechoice, TIMERUSHDATA *data) {
	if (choice.y == prechoice.y && choice.x == prechoice.x) return;
	textColorWithBackground(PURPLE, WHITE);
	if (choice.x == 0) {
		gotoXY(28, 7 + 2 * choice.y);
		cout << ">> " << data[choice.y].timerushname;
	} else {
		gotoXY(75, 7 + 2 * choice.y);
		cout << ">> " << data[choice.x * 10 + choice.y].timerushname;
	}
	textColorWithBackground(DARK_PINK, WHITE);
	if (prechoice.x == 0) {
		gotoXY(28, 7 + 2 * choice.y);
		cout << data[choice.y].timerushname << "   ";
	} else {
		gotoXY(75, 7 + 2 * choice.y);
		cout << data[choice.x * 10 + choice.y].timerushname << "   ";
	}
}

POSITION choseTimeRushPlayer(POSITION choice, TIMERUSHDATA *data) {
	POSITION prechoice;
	prechoice = choice;
	while (true) {
		if (_kbhit()) {
			switch (_getch()) {
				case 'a': case LEFT_ARROW:
					if (choice.x != 0) {
						prechoice = choice;
						choice.x--;
					}
					break;
				case 's': case DOWN_ARROW:
					if (choice.y != 9) {
						prechoice = choice;
						choice.y++;
					}
					break;
				case 'w': case UP_ARROW:
					if (choice.y != 0) {
						prechoice = choice;
						choice.y--;
					}
					break;
				case 'd': case RIGHT_ARROW:
					if (choice.x != 1) {
						prechoice = choice;
						choice.x++;
					}
					break;
			}
		}
 		hoverTimeRushPlayerChoice(choice, prechoice, data);
	}

}

int loadSaveTimeRushPlayer(TIMERUSHDATA *data, int playercount) {
	if (playercount <= 0) {
		gotoXY(28, 7);
		cout << "Empty Data!";
	} else {
		drawBoard(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH, YELLOW);
		POSITION choice = {0, 0};
		textColorWithBackground(DARK_PINK, WHITE);
		if (playercount <= 10) {
			for (int i = 0; i < playercount; i++) {
				gotoXY(28, 7 + 2 * i);
				cout << data[i].timerushname;
			}
		}
		if (playercount > 10 && playercount <= 20) {
			for (int i = 0; i < 10; i++) {
				gotoXY(28, 7 + 2 * i);
				cout << data[i].timerushname;
			}
			for (int i = 10; i < playercount; i++) {
				gotoXY(75, 7 + 2 * (i - 10));
				cout << data[i].timerushname;
			}
		}
		if (playercount > 20) {
			for (int i = 0; i < 10; i++) {
				gotoXY(28, 7 + 2 * i);
				cout << data[i].timerushname;
			}
			for (int i = 10; i < 20; i++) {
				gotoXY(75, 7 + 2 * (i - 10));
				cout << data[i].timerushname;
			}
		}
		textColorWithBackground(PURPLE, WHITE);
		gotoXY(28, 7 + 2 * choice.y);
		cout << ">> " << data[choice.y].timerushname;
		choice = choseTimeRushPlayer(choice, data);
		return choice.x * 10 + choice.y;
	}

}

//infinite
void hoverInfinitePlayerChoice(POSITION choice, POSITION prechoice, INFINITEDATA *data) {
	if (choice.y == prechoice.y && choice.x == prechoice.x) return;
	textColorWithBackground(PURPLE, WHITE);
	if (choice.x == 0) {
		gotoXY(28, 7 + 2 * choice.y);
		cout << ">> " << data[choice.y].infinitename;
	} else {
		gotoXY(75, 7 + 2 * choice.y);
		cout << ">> " << data[choice.x * 10 + choice.y].infinitename;
	}
	textColorWithBackground(DARK_PINK, WHITE);
	if (prechoice.x == 0) {
		gotoXY(28, 7 + 2 * choice.y);
		cout << data[choice.y].infinitename << "   ";
	} else {
		gotoXY(75, 7 + 2 * choice.y);
		cout << data[choice.x * 10 + choice.y].infinitename << "   ";
	}
}

POSITION choseInfinitePlayer(POSITION choice, INFINITEDATA *data) {
	POSITION prechoice;
	prechoice = choice;
	while (true) {
		if (_kbhit()) {
			switch (_getch()) {
				case 'a': case LEFT_ARROW:
					if (choice.x != 0) {
						prechoice = choice;
						choice.x--;
					}
					break;
				case 's': case DOWN_ARROW:
					if (choice.y != 9) {
						prechoice = choice;
						choice.y++;
					}
					break;
				case 'w': case UP_ARROW:
					if (choice.y != 0) {
						prechoice = choice;
						choice.y--;
					}
					break;
				case 'd': case RIGHT_ARROW:
					if (choice.x != 1) {
						prechoice = choice;
						choice.x++;
					}
					break;
			}
		}
 		hoverInfinitePlayerChoice(choice, prechoice, data);
	}

}

int loadSaveInfinitePlayer(INFINITEDATA *data, int playercount) {
	if (playercount <= 0) {
		gotoXY(28, 7);
		cout << "Empty Data!";
		cin.ignore();
		return -1;
	} else {
		drawBoard(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH, YELLOW);
		POSITION choice = {0, 0};
		textColorWithBackground(DARK_PINK, WHITE);
		if (playercount <= 10) {
			for (int i = 0; i < playercount; i++) {
				gotoXY(28, 7 + 2 * i);
				cout << data[i].infinitename;
			}
		}
		if (playercount > 10 && playercount <= 20) {
			for (int i = 0; i < 10; i++) {
				gotoXY(28, 7 + 2 * i);
				cout << data[i].infinitename;
			}
			for (int i = 10; i < playercount; i++) {
				gotoXY(75, 7 + 2 * (i - 10));
				cout << data[i].infinitename;
			}
		}
		if (playercount > 20) {
			for (int i = 0; i < 10; i++) {
				gotoXY(28, 7 + 2 * i);
				cout << data[i].infinitename;
			}
			for (int i = 10; i < 20; i++) {
				gotoXY(75, 7 + 2 * (i - 10));
				cout << data[i].infinitename;
			}
		}
		textColorWithBackground(PURPLE, WHITE);
		gotoXY(28, 7 + 2 * choice.y);
		cout << ">> " << data[choice.y].infinitename;
		choice = choseInfinitePlayer(choice, data);
		return choice.x * 10 + choice.y;
	}
}

void gameOverSign() {
	textColorWithBackground(PURPLE, WHITE);
	gotoXY(51, 15);
	cout << char(176) << char(177) << char(219) << char(223) << char(223) << char(219) << char(176) << char(219) << char(223) << char(223) << char(220) << char(176) << char(219) << char(223) << char(220) << char(223) << char(219) << char(176) << char(219) << char(223) << char(223) << char(176) << char(177) << char(219) << char(223) << char(223) << char(223) << char(219) << char(176) << char(220) << char(176) << char(176) << char(176) << char(220) << char(176) << char(219) << char(223) << char(223) << char(176) << char(219) << char(223) << char(223) << char(220);
	gotoXY(51, 16);
	cout << char(176) << char(177) << char(219) << char(176) << char(220) << char(220) << char(176) << char(219) << char(220) << char(220) << char(219) << char(176) << char(219) << char(176) << char(223) << char(176) << char(219) << char(176) << char(219) << char(223) << char(223) << char(176) << char(177) << char(219) << char(176) << char(176) << char(177) << char(219) << char(176) << char(176) << char(219) << char(220) << char(219) << char(176) << char(176) << char(219) << char(223) << char(223) << char(176) << char(219) << char(220) << char(220) << char(223);
	gotoXY(51, 17);
	cout << char(176) << char(177) << char(219) << char(220) << char(220) << char(223) << char(176) << char(223) << char(176) << char(176) << char(223) << char(176) << char(223) << char(176) << char(176) << char(177) << char(223) << char(176) << char(223) << char(223) << char(223) << char(176) << char(177) << char(219) << char(220) << char(220) << char(220) << char(219) << char(176) << char(176) << char(176) << char(223) << char(176) << char(176) << char(176) << char(223) << char(223) << char(223) << char(176) << char(223) << char(176) << char(223) << char(223);
}

string inputName() {
	drawBoard(57, 14, 30, 4, DARK_GREEN);
	gotoXY(60, 16);
	cout << "Name: ";
	textColorWithBackground(BLACK, WHITE);
	string name;
	getline(cin, name);
	return name;
}