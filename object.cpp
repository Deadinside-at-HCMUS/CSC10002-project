#include "Init.h"
using namespace std;

// snake
void generatePart(SNAKE &snake) {
	snake.size++;	
}

// food
void generateFood(int foodnum, POSITION &food) {
	int x = 0, y = 0;
	srand(time(NULL));
	for (int i = 0; i < foodnum; ++i) {
		do {
			x = rand() % (PLAY_SCREEN_LENGTH - 2)+ (LEFT_SIDE_X + 1);
			y = rand() % (PLAY_SCREEN_WIDTH - 2) + (TOP_SIDE_Y + 1);
		} while (isValidFood(x, y) == false);
	}
	food = {x, y};
}

// gate
void generateGate(int map[22][92][2]) {
	int x = 0, y = 0;
	srand(time(NULL));
	int type = rand() % 1;
	do {
		x = rand() % (PLAY_SCREEN_LENGTH - 2)+ (LEFT_SIDE_X + 1);
		y = rand() % (PLAY_SCREEN_WIDTH - 2) + (TOP_SIDE_Y + 1);
	} while (!isValidGate(x, y, type));
	switch (type) {
		case 0:
			for (int i = 0; i < 4; i++) {
				map[y - TOP_SIDE_Y - 1][x - LEFT_SIDE_X - 1 + i][0] = UPPER_BLOCK;
			}
			map[y - TOP_SIDE_Y][x - LEFT_SIDE_X - 1][0] = BLOCK;
			map[y - TOP_SIDE_Y][x - LEFT_SIDE_X][0] = GATE_SPOT;
			map[y - TOP_SIDE_Y][x - LEFT_SIDE_X][0] = GATE_SPOT;
			map[y - TOP_SIDE_Y][x - LEFT_SIDE_X + 2][0] = BLOCK;
			break;

		case 1:
			map[y - TOP_SIDE_Y - 1][x - LEFT_SIDE_X - 1][0] = BOTTOM_BLOCK;
			map[y - TOP_SIDE_Y - 1][x - LEFT_SIDE_X][0] = BOTTOM_BLOCK;
			map[y - TOP_SIDE_Y][x - LEFT_SIDE_X - 1][0] = BLOCK;
			map[y - TOP_SIDE_Y][x - LEFT_SIDE_X][0] = GATE_SPOT;
			map[y - TOP_SIDE_Y + 1][x - LEFT_SIDE_X - 1][0] = UPPER_BLOCK;
			map[y - TOP_SIDE_Y + 1][x - LEFT_SIDE_X][0] = UPPER_BLOCK;
			break;
	}
	printGate(x, y, type);
}