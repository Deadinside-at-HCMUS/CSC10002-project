#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

bool gameOver;
const int width = 20;
const int length = 20;
int headX, headY, preyX, preyY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void gameSetup() {
	gameOver = false;
	headX = width / 2;
	headY = length / 2;
	preyX = rand() % width;
	preyY = rand() % length;
	score = 0;

}

void Draw() {
	system("cls");
	for (int i = 0; i < width + 2; i++) {
		cout << "# ";
	}
	cout << endl;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0) {
				cout << "# ";
			}
			
			if (i == headY && j == headX) {
				cout << "O ";
			}
			else if (i == preyY && j == preyX) {
				cout << "P ";
			}
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						cout << "o ";
						print = true;
					}
				}
				if (!print)
					cout << "  ";
			}

			if (j == width - 1)
				cout << "# ";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++) {
		cout << "# ";
	}
	cout << endl;

	cout << "Score:" << score << endl;
}
 
void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a': 
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x': 
			gameOver = true;
			break;
		}
	}
}

void gameLogic() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = headX;
	tailY[0] = headY;
	for (int i = 1; i < nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir) {
	case LEFT:
		headX--;
		break;
	case RIGHT:
		headX++;
		break;
	case UP:
		headY--;
		break;
	case DOWN:
		headY++;
		break;
	default:
		break;
	}
	/*if (headX < 0 || headX > width || headY > length || headY < 0) {
		gameOver = true;
	}*/
	if (headX >= width)
		headX = 0;
	else if (headX < 0)
		headX = width - 1;
	if (headY >= length)
		headY = 0;
	else if (headY < 0)
		headY = length - 1;
	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == headX && tailY[i] == headY)
			gameOver = true;
	}
	if (headX == preyX && headY == preyY) {
		score += 10;
		preyX = rand() % width;
		preyY = rand() % length;
		nTail++;
	}
}

int main() {
	gameSetup();
	while (!gameOver) {
		Draw();
		Input();
		gameLogic();
		Sleep(20);
	}
	return 0;
}