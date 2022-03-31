#include <iostream>
#include "Init.h"
using namespace std;

bool gameover;
int charlock;
int score;
int foodnum;
POSITION food;
SNAKE snake;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void GameSetup() {
	srand(time(NULL));
	ChangeConsoleColor(WHITE);
	Loading();
	score = 0;
	gameover = false;
	foodnum = 1;
	snake.body = new PART[33];
	snake.body[0].part = {PLAY_SCREEN_LENGTH / 2, PLAY_SCREEN_WIDTH / 2};
	food.x = rand() % PLAY_SCREEN_LENGTH;
	food.y = rand() % PLAY_SCREEN_WIDTH;

}

//  snake

void GetDir() {
	if (_kbhit) {
		switch (_getch()) {
			case 'w':
				dir = UP;
				break;
			case 'a':
				dir = LEFT;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'p':
				dir = STOP;
				break;
			case 'x':
				dir = STOP;
				gameover = true;
				break;
		}
	}
}

void Moving() {
	switch(dir) {
		case LEFT:
			snake.body->part.x--;
			break;

		case DOWN:
			snake.body->part.y++;
			break;

		case UP:
			snake.body->part.y--;
			break;	

		case RIGHT:
			snake.body->part.x++;
			break;
		default:
			break;
	}
}

void GeneratePart() {

}

bool CheckHitting() {

}

// food

bool IsValid(int x, int y) {
	for (int i = 0; i < snake.size; i++) {
		if (snake.body[i].part.x == x && snake.body[i].part.y == y) {
			return false;
		}
	}
	return true;
}

void GenerateFood() {
	int x, y;
	srand(time(NULL));
	for (int i = 0; i < foodnum; ++i) {
		do {
			int x = rand() % (PLAY_SCREEN_LENGTH - 1) + 1;
			int y = rand() % (PLAY_SCREEN_WIDTH - 1) + 1;
		} while (IsValid(x, y) == false);
	}
	food = {x, y};
}

// obstacle

void GenerateWall() {

}

void PrintMap(int stage) {
	
}