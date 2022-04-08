#include "Init.h"
using namespace std;

bool gameover;
int charlock;
int score;
int foodnum;
int stage;
int speedcontrol;
POSITION food;
SNAKE snake;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
const char* stid = "21127175211272942112741921127693-21127175211272942112741921127693-21127175211272942112741921127693";
int map[PLAY_SCREEN_WIDTH][PLAY_SCREEN_LENGTH][2] {};

void gameSetup() {
	srand(time(NULL));
	score = 0;
	gameover = false;
	foodnum = 1;
	charlock = DOWN;
	snake.part = new POSITION[100];
	snake.head = {(RIGHT_SIDE_X + LEFT_SIDE_X) / 2, (BOTTOM_SIDE_Y + TOP_SIDE_Y) / 2};
	snake.part[0].y = snake.head.y;
	snake.part[0].x = snake.head.x + 1;
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

void swapSide() {
	if (snake.head.x >= RIGHT_SIDE_X) {
		snake.head.x = LEFT_SIDE_X + 1;
	} else if (snake.head.x <= LEFT_SIDE_X) {
		snake.head.x = RIGHT_SIDE_X - 1;
	}

	if (snake.head.y >= BOTTOM_SIDE_Y) {
		snake.head.y = TOP_SIDE_Y + 1;
	} else if (snake.head.y <= TOP_SIDE_Y) {
		snake.head.y = BOTTOM_SIDE_Y - 1;
	}	
}

// checking for propriate location
bool isValidFood(int x, int y) {
	if (snake.head.x == x && snake.head.y == y) return false;
	for (int i = 0; i < snake.size; i++) {
		if (snake.part[i].x == x && snake.part[i].y == y) {
			return false;
		}
	}
	if (map[y - TOP_SIDE_Y][x - LEFT_SIDE_X][1] != 0) return false;
	return true;
}

// bool isValidGate() {
	
// }

// check hitting obstacles
void checkCollisionBoard(SNAKE snake) {
	if (snake.head.x <= LEFT_SIDE_X || snake.head.x >= RIGHT_SIDE_X) gameover = true;
	if (snake.head.y <= TOP_SIDE_Y || snake.head.y >= BOTTOM_SIDE_Y) gameover = true;
	
}

void checkCollisionObstacles(SNAKE snake) {
	if (map[snake.head.y - TOP_SIDE_Y][snake.head.x - LEFT_SIDE_X][0] == BLOCK
	|| map[snake.head.y - TOP_SIDE_Y][snake.head.x - LEFT_SIDE_X][0] == UPPER_BLOCK
	|| map[snake.head.y - TOP_SIDE_Y][snake.head.x - LEFT_SIDE_X][0] == BOTTOM_BLOCK)
	gameover = true;
}

void checkSelfHitting(SNAKE snake) {
	for (int i = 0; i < snake.size; i++) {
		if (snake.head.x == snake.part[i].x && snake.head.y == snake.part[i].y) 
			gameover = true;
	}
}

// check eating food
bool eatFood() {
	if (snake.head.x == food.x && snake.head.y == food.y) return true;
    return false;
}

// snake print
void clearTail() {
	if (map[snake.part[snake.size - 1].y - TOP_SIDE_Y][snake.part[snake.size - 1].x - LEFT_SIDE_X][0] != BUSH_LV1
	 && map[snake.part[snake.size - 1].y - TOP_SIDE_Y][snake.part[snake.size - 1].x - LEFT_SIDE_X][0] != BUSH_LV2
	 && map[snake.part[snake.size - 1].y - TOP_SIDE_Y][snake.part[snake.size - 1].x - LEFT_SIDE_X][0] != BUSH_LV3) {
		textColorWithBackground(WHITE, WHITE);
		gotoXY(snake.part[snake.size - 1].x, snake.part[snake.size - 1].y);
		cout << " ";
	}
}

void printSnake() {
	if (map[snake.head.y - TOP_SIDE_Y][snake.head.x - LEFT_SIDE_X][0] != BUSH_LV1
	 && map[snake.head.y - TOP_SIDE_Y][snake.head.x - LEFT_SIDE_X][0] != BUSH_LV2
	 && map[snake.head.y - TOP_SIDE_Y][snake.head.x - LEFT_SIDE_X][0] != BUSH_LV3) {
		gotoXY(snake.head.x, snake.head.y);
		textColorWithBackground(DARK_RED, WHITE);
		cout << stid[0];
	}
	textColorWithBackground(DARK_YELLOW, WHITE);
	for (int i = 1; i < snake.size; i++) {
		if (map[snake.part[i].y - TOP_SIDE_Y][snake.part[i].x - LEFT_SIDE_X][0] != BUSH_LV1
		 && map[snake.part[i].y - TOP_SIDE_Y][snake.part[i].x - LEFT_SIDE_X][0] != BUSH_LV2
		 && map[snake.part[i].y - TOP_SIDE_Y][snake.part[i].x - LEFT_SIDE_X][0] != BUSH_LV3) {
			gotoXY(snake.part[i].x, snake.part[i].y);
			cout << stid[i];
		}
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
	textColorWithBackground(DARK_YELLOW, WHITE);
	gotoXY(food.x, food.y);
	cout << char(254);
}

// map
void castMapBase() {
	for (int i = 0; i < PLAY_SCREEN_LENGTH; i++) {
		for (int j = 0; j < PLAY_SCREEN_WIDTH; j++) {
			map[i][j][0] = 0;
			map[i][j][1] = WHITE;
		}
	}
}

void castMap1() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 20; j++) {
			map[i + 4][j + 16][0] = BLOCK;
			map[i + 4][j + 16][1] = BLACK;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 35; j++) {
			map[i + 6][j + 9][0] = BLOCK;
			map[i + 6][j + 9][1] = GREY;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 15; j++) {
			map[i + 11][j + 9][0] = BLOCK;
			map[i + 11][j + 9][1] = GREY;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 11; j++) {
			map[i + 7][j + 70][0] = BOTTOM_BLOCK;
			map[i + 7][j + 70][1] = GREY;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 11; j++) {
			if (j % 2) {
				map[i + 9][j + 70][0] = BUSH_LV2;
			} else {
				map[i + 9][j + 70][0] = BUSH_LV3;
			}
			map[i + 9][j + 70][1] = DARK_GREEN;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 11; j++) {
			map[i + 14][j + 70][0] = UPPER_BLOCK;
			map[i + 14][j + 70][1] = GREY;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			if (j % 2) {
				map[i + 17][j + 51][0] = BUSH_LV2;
			} else {
				map[i + 17][j + 51][0] = BUSH_LV3;
			}
			map[i + 17][j + 51][1] = DARK_GREEN;
		}
	}
}

void castMap2() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 21; j++) {
			map[i + 5][j + 8][0] = BLOCK;
			map[i + 5][j + 8][1] = GREY;
		}
	}
	map[5][9][0] = 15;
	map[16][9][0] = 15;
	map[5][27][0] = 15;
	map[16][27][0] = 15;
	map[5][8][0] = 15;
	map[16][8][0] = 15;
	map[5][28][0] = 15;
	map[16][28][0] = 15;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 14; j++) {
			if (j % 2) {
				map[i + 3][j + 42][0] = BUSH_LV2;
			} else {
				map[i + 3][j + 42][0] = BUSH_LV3;
			}
			map[i + 3][j + 42][1] = DARK_GREEN;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 8; j++) {
			if (j % 2){
				map[i + 17][j + 33][0] = BUSH_LV3;
			} else {
				map[i + 17][j + 33][0] = BUSH_LV2;
			}
			map[i + 17][j + 33][1] = DARK_GREEN;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			map[i + 15][j + 48][0] = BLOCK;
			map[i + 15][j + 48][1] = GREY;
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 9; j++) {
			if (j % 2) {
				map[i + 14][j + 64][0] = BUSH_LV2;
			} else {
				map[i + 14][j + 64][0] = BUSH_LV3;
			}
			map[i + 14][j + 64][1] = DARK_GREEN;
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 11; j++) {
			if (j % 2) {
				map[i + 4][j + 77][0] = UPPER_BLOCK;
			} else {
				map[i + 4][j + 77][0] = BOTTOM_BLOCK;
			}
			map[i + 4][j + 77][1] = BLACK;
		}
	}
}

void castMap3() {
	for (int i = 0; i < 8; i++) {
		map[i + 4][14][0] = BLOCK;
		map[i + 4][14][1] = GREY;
	}
	for (int i = 0; i < 30; i++) {
		map[4][i + 14][0] = BLOCK;
		map[4][i + 14][1] = GREY;
	}
	for (int i = 0; i < 27; i++) {
		map[7][i + 17][0] = BLOCK;
		map[7][i + 17][1] = GREY;
	}
	for (int i = 0; i < 5; i++) {
		map[i + 7][17][0] = BLOCK;
		map[i + 7][17][1] = GREY;
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (j % 2) {
				map[i + 7][j + 65][0] = BUSH_LV2;
			} else {
				map[i + 7][j + 65][0] = BUSH_LV3;
			}
			map[i + 7][j + 65][1] = DARK_GREEN;
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (j % 2) {
				map[i + 12][j + 23][0] = BUSH_LV2;
			} else {
				map[i + 12][j + 23][0] = BUSH_LV3;
			}
			map[i + 12][j + 23][1] = DARK_GREEN;
		}
	}
	for (int i = 0; i < 41; i++) {
		map[18][i + 42][0] = BLOCK;
		map[18][i + 42][1] = GREY;
	}
	for (int i = 0; i < 38; i++) {
		map[15][i + 42][0] = BLOCK;
		map[15][i + 42][1] = GREY;
	}
	for (int i = 0; i < 15; i++) {
		map[i + 4][83][0] = BLOCK;
		map[i + 4][83][1] = GREY;
	}
	for (int i = 0; i < 12; i++) {
		map[i + 4][80][0] = BLOCK;
		map[i + 4][80][1] = GREY;
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			if (j % 2) {
				map[i + 12][j + 32][0] = BUSH_LV2;
			} else {
				map[i + 12][j + 32][0] = BUSH_LV3;
			}
			map[i + 12][j + 32][1] = DARK_GREEN;
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			map[i + 12][j + 29][0] = BLOCK;
			map[i + 12][j + 29][1] = DARK_BLUE;
		}
	}
}

void castMap4() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (j % 2) {
				map[i + 6][j + 13][0] = BUSH_LV2;
			} else {
				map[i + 6][j + 13][0] = BUSH_LV3;
			}
			map[i + 6][j + 13][1] = DARK_GREEN;
		}
	}
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (j % 2) {
				map[i + 6][j + 75][0] = BUSH_LV2;
			} else {
				map[i + 6][j + 75][0] = BUSH_LV3;
			}
			map[i + 6][j + 75][1] = DARK_GREEN;
		}
	}
	for (int i = 0; i < 7; i++) {
		map[i + 1][15][0] = BLOCK;
		map[i + 1][15][1] = GREY;
		map[i + 1][16][0] = BLOCK;
		map[i + 1][16][1] = GREY;
	}
	for (int i = 0; i < 7; i++) {
		map[i + 15][15][0] = BLOCK;
		map[i + 15][15][1] = GREY;
		map[i + 15][16][0] = BLOCK;
		map[i + 15][16][1] = GREY;
	}
	for (int i = 0; i < 7; i++) {
		map[i + 1][77][0] = BLOCK;
		map[i + 1][77][1] = GREY;
		map[i + 1][78][0] = BLOCK;
		map[i + 1][78][1] = GREY;
	}
	for (int i = 0; i < 7; i++) {
		map[i + 15][77][0] = BLOCK;
		map[i + 15][77][1] = GREY;
		map[i + 15][78][0] = BLOCK;
		map[i + 15][78][1] = GREY;
	}
// ngat
	for (int i = 0; i < 6; i++) {
		map[9][i + 29][0] = BLOCK;
		map[9][i + 29][1] = GREY;
		map[10][i + 29][0] = BLOCK;
		map[10][i + 29][1] = GREY;
	}
	for (int i = 0; i < 6; i++) {
		map[13][i + 29][0] = BLOCK;
		map[13][i + 29][1] = GREY;
		map[14][i + 29][0] = BLOCK;
		map[14][i + 29][1] = GREY;
	}
	for (int i = 0; i < 7; i++) {
		map[9][i + 38][0] = BLOCK;
		map[9][i + 38][1] = GREY;
		map[10][i + 38][0] = BLOCK;
		map[10][i + 38][1] = GREY;
	}
	for (int i = 0; i < 7; i++) {
		map[13][i + 38][0] = BLOCK;
		map[13][i + 38][1] = GREY;
		map[14][i + 38][0] = BLOCK;
		map[14][i + 38][1] = GREY;
	}
// ngat
	for (int i = 0; i < 7; i++) {
		map[9][i + 48][0] = BLOCK;
		map[9][i + 48][1] = GREY;
		map[10][i + 48][0] = BLOCK;
		map[10][i + 48][1] = GREY;
	}
	for (int i = 0; i < 7; i++) {
		map[13][i + 48][0] = BLOCK;
		map[13][i + 48][1] = GREY;
		map[14][i + 48][0] = BLOCK;
		map[14][i + 48][1] = GREY;
	}
	for (int i = 0; i < 6; i++) {
		map[9][i + 58][0] = BLOCK;
		map[9][i + 58][1] = GREY;
		map[10][i + 58][0] = BLOCK;
		map[10][i + 58][1] = GREY;
	}
	for (int i = 0; i < 6; i++) {
		map[13][i + 58][0] = BLOCK;
		map[13][i + 58][1] = GREY;
		map[14][i + 58][0] = BLOCK;
		map[14][i + 58][1] = GREY;
	}
}

void castMap5() {
	for (int i = 0; i < 32; i++) {
		map[7][i + 10][0] = BLOCK;
		map[7][i + 10][1] = GREY;
	}
	for (int i = 0; i < 10; i++) {
		map[i + 4][17][0] = BLOCK;
		map[i + 4][17][1] = GREY;
	}
	for (int i = 0; i < 7; i++) {
		map[i + 1][41][0] = BLOCK;
		map[i + 1][41][1] = GREY;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			map[i + 1][j + 16][0] = BUSH_LV2;
			map[i + 1][j + 16][1] = DARK_GREEN;
		}
	}

	for (int i = 0; i < 23; i++) {
		map[18][i + 1][0] = BLOCK;
		map[18][i + 1][1] = GREY;
	}
	for (int i = 0; i < 11; i++) {
		map[i + 12][32][0] = BLOCK;
		map[i  +12][32][1] = GREY;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 8; j++) {
			map[i + 17][j + 24][0] = BLOCK;
			map[i + 17][j + 24][0] = BLACK;
		}
	}

	for (int i = 0; i < 10; i++) {
		map[i + 1][54][0] = BLOCK;
		map[i + 1][54][1] = GREY;
	}
	for (int i = 21; i > 1; i--) {
		map[6][74 - i][0] = BLOCK;
		map[6][74 - i][1] = GREY;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			map[i + 11][j + 53][0] = BUSH_LV3;
			map[i + 11][j + 53][1] = DARK_GREEN;
		}
	}

	for (int i = 0; i < 38; i++) {
		map[14][i + 42][0] = BLOCK;
		map[14][i + 42][1] = GREY;
	}
	for (int i = 5; i > 1; i--) {
		map[18 - i][49][0] = BLOCK;
		map[18 - i][49][1] = GREY;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 8; j++) {
			map[i + 17][j + 24][0] = BUSH_LV3;
			map[i + 17][j + 24][1] = DARK_GREEN;
		}
	}

	for (int i = 0; i < 11; i++) {
		map[18][i + 60][0] = BLOCK;
		map[18][i + 60][1] = GREY;
	}
	for (int i = 0; i < 5; i++) {
		map[i + 18][60][0] = BLOCK;
		map[i + 18][60][1] = GREY;
	}

	for (int i = 0; i < 11; i++) {
		map[11][i + 79][0] = BLOCK;
		map[11][i + 79][1] = GREY;
	}
	for (int i = 0; i < 8; i++) {
		map[i + 11][79][0] = BLOCK;
		map[i + 11][79][1] = GREY;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			map[i + 17][j + 80][0] = BUSH_LV2;
			map[i + 17][j + 80][1] = DARK_GREEN;
		}
	}
	for (int i = 0; i < 5; i++) {
		map[18][i + 87][0] = BLOCK;
		map[18][i + 87][1] = GREY;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			map[i + 1][j + 83][0] = BUSH_LV3;
			map[i + 1][j + 83][1] = DARK_GREEN;
		}
	}
	for (int i = 0; i < 6; i++) {
		map[i + 5][84][0] = BLOCK;
		map[i + 5][84][1] = GREY;
	}
}

void castBonusRound() {

}
void printMap() {
	for (int i = 0; i < PLAY_SCREEN_WIDTH; i++) {
		for (int j = 0; j < PLAY_SCREEN_LENGTH; j++) {
			if (map[i][j][0] != 15) {
				textColorWithBackground(map[i][j][1], WHITE);
				gotoXY(j + LEFT_SIDE_X, i + TOP_SIDE_Y);
				cout << char(map[i][j][0]);
			}
		}
	}
}

void graphSet(int stage, SNAKE snake) {
	gotoXY(10, 7);
	cout << stage;
	gotoXY(10, 9);
	cout << score;
	printSnake();
	printFood();
	switch (stage) {
		case 1:
			castMap1();
			printMap();
			break;
		case 2:
			castMap2();
			printMap();
			break;
		case 3:
			castMap3();
			printMap();
			break;
		case 4:
			castMap4();
			printMap();
			break;
		case 5:
			castMap5();
			printMap();
			break;
		default:
			break;
	}
}

void resetScore() {
	textColorWithBackground(DARK_YELLOW, WHITE);
	gotoXY(10, 9);
	cout << score;
}

void resetSpeed() {
	textColorWithBackground(DARK_YELLOW, WHITE);
	gotoXY(10, 7);
	if (speedcontrol < 18)
		cout << speedcontrol + 1;
	else
		cout << "MAX";
}

// create new game
void newClassicGame() {
	gameSetup();
	stage = 5;
	graphSet(stage, snake);
	bool visit = false;
	
	while (!gameover) {
		clearTail();
		getDir();
		moving();
		if (snake.size > 1) checkSelfHitting(snake);
		checkCollisionBoard(snake);
		checkCollisionObstacles(snake);
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

void newInfiniteGame() {
	textColorWithBackground(PURPLE, WHITE);
	drawChoiceBox(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH + 1);
	gameSetup();
	speedcontrol = 0;
	textColorWithBackground(DARK_YELLOW, WHITE);
	gotoXY(3, 7);
	cout << "Speed: ";
	gotoXY(10, 7);
	cout << speedcontrol + 1;
	gotoXY(10, 9);
	cout << score;
	printSnake();
	printFood();

	while (!gameover) {
		clearTail();
		getDir();
		moving();
		if (snake.size > 1) checkSelfHitting(snake);
		swapSide();
		if (eatFood() == true) {
			score += 10;
			if (speedcontrol < 18) speedcontrol++;
			resetScore();
			resetSpeed();
			clearFood();
			generateFood(foodnum, food);
			printFood();
			generatePart(snake);
		}
		renderSnake();
		printSnake();
		Sleep(200 - speedcontrol * 10);
	}
	dir = STOP;
}