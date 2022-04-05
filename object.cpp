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
		} while (isValid(x, y) == false);
	}
	food = {x, y};
}

// obstacle
void generateObstacle() {

}

//gate
void generateGate() {
	int x = 0, y = 0;
	srand(time(NULL));
	int type = rand() % 1;
	if (type == 1) {
		do {
			x = rand() % (PLAY_SCREEN_LENGTH - 2)+ (LEFT_SIDE_X + 1);
			y = rand() % (PLAY_SCREEN_WIDTH - 2) + (TOP_SIDE_Y + 1);
		} while (!isValidGate(x, y));
	}

}