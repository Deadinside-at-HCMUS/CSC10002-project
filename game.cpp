#include "Init.h"
using namespace std;

bool gameover;
int charlock;
int score;
int foodnum;
int stage;
POSITION food;
SNAKE snake;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
const char* stid = "21127175211272942112741921127693";

void gameSetup() {
	srand(time(NULL));
	score = 0;
	gameover = false;
	foodnum = 1;
	stage = 1;
	charlock = DOWN;
	snake.part = new POSITION[33];
	snake.head = {(RIGHT_SIDE_X + LEFT_SIDE_X) / 2, (BOTTOM_SIDE_Y + TOP_SIDE_Y) / 2};
	snake.size = 1;
	food.x = rand() % (PLAY_SCREEN_LENGTH - 2)+ (LEFT_SIDE_X + 1);
	food.y = rand() % (PLAY_SCREEN_WIDTH - 2) + (TOP_SIDE_Y + 1);

}

//  snake
void getDir() {
	if (_kbhit()) {
		switch (_getch()) {
			case 'w':
				if (charlock != UP) {
					dir = UP;
					charlock = DOWN;
				}
				break;
			case 'a':
				if (charlock != LEFT) {
					dir = LEFT;
					charlock = RIGHT;
				}
				break;
			case 's':
				if (charlock != DOWN) {
					dir = DOWN;
					charlock = UP;
				}
				break;
			case 'd':
				if (charlock != RIGHT) {
					dir = RIGHT;
					charlock = LEFT;
				}
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

void moving() {
	switch(dir) {
		case LEFT:
			snake.head.x--;
			break;

		case DOWN:
			snake.head.y++;
			break;

		case UP:
			snake.head.y--;
			break;	

		case RIGHT:
			snake.head.x++;
			break;
		default:
			break;
	}
}

// checking for propriate location
bool isValid(int x, int y) {
	if (snake.head.x == x && snake.head.y == y) return false;
	for (int i = 0; i < snake.size; i++) {
		if (snake.part[i].x == x && snake.part[i].y == y) {
			return false;
		}
	}
	return true;
}

// bool isValidGate() {
	
// }

// check hitting obstacles
void checkCollisionBoard(SNAKE snake) {
	if (snake.head.x <= LEFT_SIDE_X || snake.head.x >= RIGHT_SIDE_X) gameover = true;
	if (snake.head.y <= TOP_SIDE_Y || snake.head.y >= BOTTOM_SIDE_Y) gameover = true;
	
}

void checkCollisionObstacles(SNAKE snake, OBSTACLE wall) {
	
}

// check eating food
bool eatFood() {
	if (snake.head.x == food.x && snake.head.y == food.y) return true;
    return false;
}

// snake print
void clearSnake() {
	gotoXY(snake.head.x, snake.head.y);
	textColorWithBackground(WHITE, WHITE);
	cout << " ";
	for (int i = 0; i < snake.size; i++) {
		gotoXY(snake.part[i].x, snake.part[i].y);
		cout << " ";
	}
}

void printSnake() {
	gotoXY(snake.head.x, snake.head.y);
	textColorWithBackground(DARK_RED, WHITE);
	cout << stid[0];
	textColorWithBackground(DARK_BLUE, WHITE);
	for (int i = 1; i < snake.size; i++) {
		gotoXY(snake.part[i].x, snake.part[i].y);
		cout << stid[i];
	}

}

void renderSnake() {
	POSITION prevpart, prev2part;
	prevpart = snake.part[0];
	snake.part[0] = snake.head;
	for (int idx = 1; idx < snake.size; idx++) {
		prev2part = snake.part[idx];
		snake.part[idx] = prevpart;
		prevpart = prev2part;
	}
}

// food print
void clearFood() {
	gotoXY(food.x, food.y);
	cout << " ";
}

void printFood() {
	textColorWithBackground(DARK_BLUE, WHITE);
	gotoXY(food.x, food.y);
	cout << stid[snake.size + 1];
}
// obstacles print



// map print
void printMap(int stage, SNAKE snake) {
	if (stage == 1) {
		gotoXY(10, 7);
		cout << stage;
		gotoXY(10, 9);
		cout << score;
		printSnake();
		printFood();
	}
}

void resetScore() {
	textColorWithBackground(PURPLE, WHITE);
	gotoXY(10, 9);
	cout << score;
}

// create new game
void newGame() {
	gameSetup();
	printMap(stage, snake);

	while (!gameover) {
		clearSnake();
		getDir();
		moving();
		checkCollisionBoard(snake);
		if (eatFood() == true) {
			score += 10;
			resetScore();
			clearFood();
			generateFood(foodnum, food);
			printFood();
			generatePart(snake);
		}
		renderSnake();
		printSnake();
		Sleep(70);
	}
	dir = STOP;
}