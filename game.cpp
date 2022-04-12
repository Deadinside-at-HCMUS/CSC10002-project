#include "Init.h"
using namespace std;

bool gameover;
bool save;
int charlock;
int score;
int foodnum;
int stage;
int speedcontrol;
int gametime = 360;
POSITION food;
string name;
int difficulty;
int classic_player;
CLASSICDATA *classic_data;
int timerush_player;
TIMERUSHDATA *timerush_data;
int infinite_player;
INFINITEDATA *infinite_data;
SNAKE *snake = new SNAKE;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN, STAY };
eDirection dir, temp;
const char* stid = "21127175211272942112741921127693-21127175211272942112741921127693-21127175211272942112741921127693";
int map[PLAY_SCREEN_WIDTH][PLAY_SCREEN_LENGTH][2] {};

void gameSetup() {
	dir = STAY;
	srand(time(NULL));
	score = 0;
	gameover = false;
	save = false;
	foodnum = 1;
	stage = 1;
	charlock = STOP;
	snake->part = new POSITION[100];
	snake->head = {(RIGHT_SIDE_X + LEFT_SIDE_X) / 2, (BOTTOM_SIDE_Y + TOP_SIDE_Y) / 2};
	snake->part[0].y = snake->head.y;
	snake->part[0].x = snake->head.x + 1;
	snake->size = 1;
}

//  snake
void getDir() {
	if (_kbhit()) {
		switch (_getch()) {
			case 'w': case UP_ARROW:
				if (charlock != UP) {
					dir = UP;
					charlock = DOWN;
				}
				break;
			case 'a': case LEFT_ARROW:
				if (charlock != LEFT) {
					dir = LEFT;
					charlock = RIGHT;
				}
				break;
			case 's': case DOWN_ARROW:
				if (charlock != DOWN) {
					dir = DOWN;
					charlock = UP;
				}
				break;
			case 'd': case RIGHT_ARROW:
				if (charlock != RIGHT) {
					dir = RIGHT;
					charlock = LEFT;
				}
				break;
			case 'p':
				temp = dir;
				dir = STOP;
				break;
			default:
				break;
		}
	}
}

void moving(int type) {
	switch(dir) {
		case LEFT:
			snake->head.x--;
			break;

		case DOWN:
			snake->head.y++;
			break;

		case UP:
			snake->head.y--;
			break;	

		case RIGHT:
			snake->head.x++;
			break;

		case STOP:
			pauseGameBoard(60, 13);
			pauseGameInput(60, 13, type);
			break;
			
		default:
			break;
	}
}

void pauseGameInput(int x, int y, int type) {
	bool input = false;
	while (input != true) {
		if (_kbhit()) {
			switch (_getch()) {
				case 'c':
					for (int i = 0; i < 9; i++) {
						gotoXY(x, y + i);
						for (int j = 0; j < 23; j++) {
							textColorWithBackground(map[y + i - TOP_SIDE_Y][x + j - LEFT_SIDE_X][1], WHITE);
							if (map[y + i - TOP_SIDE_Y][x + j - LEFT_SIDE_X][0] != 0) {
								cout << char(map[y + i - TOP_SIDE_Y][x + j - LEFT_SIDE_X][0]);
							} else {
								cout << ' ';
							}
						}
					}
					printSnake(snake);
					printFood(food);
					dir = temp;
					moving(1);
					input = true;
					break;
				case 's':
					if (type == 1) {
						CLASSICDATA player;
						player.classicname = name;
						player.difficulty = difficulty;
						player.snake = snake;
						player.score = score;
						player.stage = stage;
						classic_data = pushClassicData(classic_data, player, classic_player);
						save = true;
						gameover = true;
					} else if (type == 2) {
						TIMERUSHDATA player;
						player.timerushname = name;
						player.score = score;
						player.stage = stage;
						player.time = gametime;
						player.difficulty = difficulty;
						player.snake = snake;
						timerush_data = pushTimeRushData(timerush_data, player, timerush_player);
						save = true;
						gameover = true;
					} else {
						INFINITEDATA player;
						player.infinitename = name;
						player.score = score;
						player.snake = snake;
						infinite_data = pushInfiniteData(infinite_data, player, infinite_player);
						save = true;
						gameover = true;
					}
					input = true;
					break;
				case 'x':
					gameover = true;
					input = true;
					break;
				default:
					break;
			}
		}
	}
}

void swapSide() {
	if (snake->head.x >= RIGHT_SIDE_X) {
		snake->head.x = LEFT_SIDE_X + 1;
	} else if (snake->head.x <= LEFT_SIDE_X) {
		snake->head.x = RIGHT_SIDE_X - 1;
	}

	if (snake->head.y >= BOTTOM_SIDE_Y) {
		snake->head.y = TOP_SIDE_Y + 1;
	} else if (snake->head.y <= TOP_SIDE_Y) {
		snake->head.y = BOTTOM_SIDE_Y - 1;
	}	
}

// checking for propriate location
bool isValidSpawn(int x, int y) {
	if (x == snake->head.x && y == snake->head.y) return false;
	for (int idx = 0; idx < snake->size; idx++) {
		if (snake->part[idx].x == x && snake->part[idx].y == y) return false;
	}
	return true;
}

bool isValidFood(int x, int y) {
	if (snake->head.x == x && snake->head.y == y) return false;
	for (int i = 0; i < snake->size; i++) {
		if (snake->part[i].x == x && snake->part[i].y == y) {
			return false;
		}
	}
	if (map[y - TOP_SIDE_Y][x - LEFT_SIDE_X][0] == BLOCK
	|| map[y - TOP_SIDE_Y][x - LEFT_SIDE_X][0] == UPPER_BLOCK
	|| map[y - TOP_SIDE_Y][x - LEFT_SIDE_X][0] == BOTTOM_BLOCK) return false;
	return true;
}

bool isValidGate(int x, int y, int type) {
	switch (type) {
		case 0:
			for (int i = 0; i < 4; i++) {
				if (map[y - TOP_SIDE_Y - 1][x - LEFT_SIDE_X - 1 + i][0] != 0
				|| map[y - TOP_SIDE_Y - 1][x - LEFT_SIDE_X - 1 + i][0] == TOP_SIDE_Y + 1
				|| !isValidSpawn(x - 1 + i, y - 1)) return false;
				if (map[y - TOP_SIDE_Y][x - LEFT_SIDE_X - 1 + i][0] != 0
				|| map[y - TOP_SIDE_Y][x - LEFT_SIDE_X - 1 + i][0] == LEFT_SIDE_X + 1
				|| map[y - TOP_SIDE_Y][x - LEFT_SIDE_X - 1 + i][0] == RIGHT_SIDE_X) return false;
				if (map[y - TOP_SIDE_Y + 1][x - LEFT_SIDE_X - 1 + i][0] != 0
				|| map[y - TOP_SIDE_Y + 1][x - LEFT_SIDE_X - 1 + i][0] == BOTTOM_SIDE_Y - 1
				|| !isValidSpawn(x + i - 1, y + 1)) return false;
			}
			break;
		case 1:
			for (int i = 0; i < 3; i++) {
				if (map[y - TOP_SIDE_Y - 1][x - LEFT_SIDE_X - 1 + i][0] != 0
				|| map[y - TOP_SIDE_Y - 1][x - LEFT_SIDE_X - 1 + i][0] == TOP_SIDE_Y + 1
				|| !isValidSpawn(x - 1 + i, y - 1)) return false;
				if (map[y - TOP_SIDE_Y][x - LEFT_SIDE_X - 1 + i][0] != 0
				|| map[y - TOP_SIDE_Y][x - LEFT_SIDE_X - 1 + i][0] == LEFT_SIDE_X + 1
				|| map[y - TOP_SIDE_Y][x - LEFT_SIDE_X - 1 + i][0] == RIGHT_SIDE_X) return false;
				if (map[y - TOP_SIDE_Y + 1][x - LEFT_SIDE_X - 1 + i][0] != 0
				|| map[y - TOP_SIDE_Y + 1][x - LEFT_SIDE_X - 1 + i][0] == BOTTOM_SIDE_Y - 1
				|| !isValidSpawn(x - 1 + i, y + 1)) return false;
			}
			break;
		default: 
			break;
	}
	return true;
}

bool isFoodInBush(POSITION food) {
	if (map[food.y - TOP_SIDE_Y][food.x - LEFT_SIDE_X][0] <= BUSH_LV3 && map[food.y - TOP_SIDE_Y][food.x - LEFT_SIDE_X][0] >= BUSH_LV1) return true;
	return false;
}

// check hitting obstacles
void checkCollisionBoard(SNAKE *snake) {
	if (snake->head.x <= LEFT_SIDE_X || snake->head.x >= RIGHT_SIDE_X) gameover = true;
	if (snake->head.y <= TOP_SIDE_Y || snake->head.y >= BOTTOM_SIDE_Y) gameover = true;
	
}

void checkCollisionObstacles(SNAKE *snake) {
	if (map[snake->head.y - TOP_SIDE_Y][snake->head.x - LEFT_SIDE_X][0] == BLOCK
	|| map[snake->head.y - TOP_SIDE_Y][snake->head.x - LEFT_SIDE_X][0] == UPPER_BLOCK
	|| map[snake->head.y - TOP_SIDE_Y][snake->head.x - LEFT_SIDE_X][0] == BOTTOM_BLOCK)
	gameover = true;
}

void checkSelfHitting(SNAKE *snake) {
	for (int i = 0; i < snake->size; i++) {
		if (snake->head.x == snake->part[i].x && snake->head.y == snake->part[i].y) gameover = true;
	}
}

// check eating food
bool eatFood(POSITION food) {
	if (snake->head.x == food.x && snake->head.y == food.y) return true;
    return false;
}

bool getInGate(POSITION pos) {
	if (map[pos.y - TOP_SIDE_Y][pos.x - LEFT_SIDE_X][0] == GATE_SPOT) {
		return true;
	}
	return false;
}

// snake print
void clearTail() {
	if (map[snake->part[snake->size - 1].y - TOP_SIDE_Y][snake->part[snake->size - 1].x - LEFT_SIDE_X][0] != BUSH_LV1
	 && map[snake->part[snake->size - 1].y - TOP_SIDE_Y][snake->part[snake->size - 1].x - LEFT_SIDE_X][0] != BUSH_LV2
	 && map[snake->part[snake->size - 1].y - TOP_SIDE_Y][snake->part[snake->size - 1].x - LEFT_SIDE_X][0] != BUSH_LV3) {
		textColorWithBackground(WHITE, WHITE);
		gotoXY(snake->part[snake->size - 1].x, snake->part[snake->size - 1].y);
		cout << " ";
	}
}

void printSnake(SNAKE *snake) {
	if (map[snake->head.y - TOP_SIDE_Y][snake->head.x - LEFT_SIDE_X][0] != BUSH_LV1
	 && map[snake->head.y - TOP_SIDE_Y][snake->head.x - LEFT_SIDE_X][0] != BUSH_LV2
	 && map[snake->head.y - TOP_SIDE_Y][snake->head.x - LEFT_SIDE_X][0] != BUSH_LV3) {
		gotoXY(snake->head.x, snake->head.y);
		textColorWithBackground(DARK_RED, WHITE);
		cout << stid[0];
	}
	textColorWithBackground(DARK_YELLOW, WHITE);
	for (int i = 1; i < snake->size; i++) {
		if (map[snake->part[i].y - TOP_SIDE_Y][snake->part[i].x - LEFT_SIDE_X][0] != BUSH_LV1
		 && map[snake->part[i].y - TOP_SIDE_Y][snake->part[i].x - LEFT_SIDE_X][0] != BUSH_LV2
		 && map[snake->part[i].y - TOP_SIDE_Y][snake->part[i].x - LEFT_SIDE_X][0] != BUSH_LV3) {
			gotoXY(snake->part[i].x, snake->part[i].y);
			cout << stid[i];
		}
	}

}

void renderSnake(POSITION head) {
	POSITION prevpart, prev2part;
	prevpart = snake->part[0];
	snake->part[0] = head;
	for (int idx = 1; idx < snake->size; idx++) {
		prev2part = snake->part[idx];
		snake->part[idx] = prevpart;
		prevpart = prev2part;
	}
}

// food print
void clearFood(POSITION food) {
	gotoXY(food.x, food.y);
	if (map[food.y - TOP_SIDE_Y][food.x - LEFT_SIDE_X][0] <= BUSH_LV3 && map[food.y - TOP_SIDE_Y][food.x - LEFT_SIDE_X][0] >= BUSH_LV1) {
		textColorWithBackground(DARK_GREEN, WHITE);
		cout << char(map[food.y - TOP_SIDE_Y][food.x - LEFT_SIDE_X][0]);
	} else {
		textColorWithBackground(WHITE, WHITE);
		cout << " ";
	}
}

void printFood(POSITION food) {
	textColorWithBackground(DARK_YELLOW, WHITE);
	gotoXY(food.x, food.y);
	if (!isFoodInBush(food)) {
		cout << char(FOOD);
	} else {
		cout << char(map[food.y - TOP_SIDE_Y][food.x - LEFT_SIDE_X][0]);
	}
}

void printTimeFood(POSITION timefood) {
	textColorWithBackground(PURPLE, WHITE);
	gotoXY(timefood.x, timefood.y);
	if (!isFoodInBush(timefood)) {
		cout << char(TIME_FOOD);
	} else {
		cout << char(map[food.y - TOP_SIDE_Y][food.x - LEFT_SIDE_X][0]);
	}
}

// gate print
void printGate(int x, int y, int type) {
	switch (type) {
		case 0:
			textColorWithBackground(DARK_YELLOW, WHITE);
			gotoXY(x - 1, y - 1);
			for (int i = 0; i < 4; i++) {
				cout << char(BOTTOM_BLOCK);
			}
			textColorWithBackground(DARK_YELLOW, BLACK);
			gotoXY(x - 1, y);
			cout << char(BLOCK) << "  " << char(BLOCK);
			break;
		case 1:
			textColorWithBackground(DARK_YELLOW, WHITE);
			gotoXY(x - 1, y - 1);
			cout << char(BOTTOM_BLOCK) << char(BOTTOM_BLOCK);
			textColorWithBackground(DARK_YELLOW, BLACK);
			gotoXY(x - 1, y);
			cout << char(BLOCK) << ' ';
			textColorWithBackground(DARK_YELLOW, WHITE);
			gotoXY(x - 1, y + 1);
			cout << char(UPPER_BLOCK) << char(UPPER_BLOCK);
			break;
	}
}

// map
void castMapBase() {
	for (int i = 0; i < PLAY_SCREEN_WIDTH; i++) {
		for (int j = 0; j < PLAY_SCREEN_LENGTH; j++) {
			map[i][j][0] = 0;
			map[i][j][1] = WHITE;
		}
	}
}

void castMap1() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 20; j++) {
			map[i + 4][j + 16][0] = BLOCK;
			map[i + 4][j + 16][1] = GREY;
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
		map[i + 12][32][1] = GREY;
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
		map[6][75 - i][0] = BLOCK;
		map[6][75 - i][1] = GREY;
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
		map[19 - i][49][0] = BLOCK;
		map[19 - i][49][1] = GREY;
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

void graphSet(int stage, SNAKE *snake) {
	castMapBase();
	gotoXY(10, 7);
	cout << stage;
	gotoXY(10, 9);
	cout << score;
	printSnake(snake);
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

// gate
void drawDesGate(int type, int x, int y) {
	textColorWithBackground(DARK_YELLOW, WHITE);
	if (type == 1) {
		gotoXY(x - 1, y);
		cout << char(214) << 'O' << char(183);
		gotoXY(x - 1, y + 1);
		cout << char(186) << ' ' << char(186);
		gotoXY(x - 1, y+ 1);
		cout << char(189) << ' ' << char(211);
	} else {
		gotoXY(x, y - 1);
		cout << char(213) << char(205) << char(190);
		gotoXY(x, y);
		cout << 'O';
		gotoXY(x, y + 1);
		cout << char(212) << char(205) << char(184);
	}
}

void desGate(int stage) {
	switch (stage) {
		case 1:
		case 2: 
			drawDesGate(1, LEFT_SIDE_X + 2, TOP_SIDE_Y + 1);
			snake->head = {LEFT_SIDE_X + 2, TOP_SIDE_Y + 2};
			for (int i = 0; i < snake->size; i++) {
				snake->part[i] = snake->head;
			}
			dir = DOWN;
			charlock = UP;
			break;
		case 3:
			drawDesGate(2, LEFT_SIDE_X + 1, TOP_SIDE_Y + 4);
			snake->head = {LEFT_SIDE_X + 2, TOP_SIDE_Y + 4};
			for (int i = 0; i < snake->size; i++) {
				snake->part[i] = snake->head;
			}
			dir = RIGHT;
			charlock = LEFT;
			break;
		case 4:
			drawDesGate(1, RIGHT_SIDE_X - 5, TOP_SIDE_Y + 1);
			snake->head = {RIGHT_SIDE_X - 5, TOP_SIDE_Y + 2};
			for (int i = 0; i < snake->size; i++) {
				snake->part[i] = snake->head;
			}
			dir = DOWN;
			charlock = UP;
			break;
		case 5:
			drawDesGate(2, LEFT_SIDE_X + 1, TOP_SIDE_Y + 14);
			snake->head = {LEFT_SIDE_X + 2, TOP_SIDE_Y + 14};
			for (int i = 0; i < snake->size; i++) {
				snake->part[i] = snake->head;
			}
			dir = RIGHT;
			charlock = LEFT;
			break;
	}
}

void removeDesGate(int stage, bool &cleargate) {
	switch(stage) {
		case 1:
		case 2:
			if (snake->part[snake->size - 1].x != LEFT_SIDE_X + 2 && snake->part[snake->size - 1].y != TOP_SIDE_Y + 2) {
				cleargate = true;
				drawBlank(LEFT_SIDE_X + 1, TOP_SIDE_Y + 1, 3, 3);
			}
			break;
		case 3:
			if (snake->part[snake->size - 1].x != LEFT_SIDE_X + 1 && snake->part[snake->size - 1].y != TOP_SIDE_Y + 4) {
				cleargate = true;
				drawBlank(LEFT_SIDE_X + 1, TOP_SIDE_Y + 3, 3, 3);
			}
			break;
		case 4:
			if (snake->part[snake->size - 1].x != RIGHT_SIDE_X - 5 && snake->part[snake->size - 1].y != TOP_SIDE_Y + 2) {
				cleargate = true;
				drawBlank(RIGHT_SIDE_X - 6, TOP_SIDE_Y + 1, 3, 3);
			}
			break;
		case 5:
			if (snake->part[snake->size - 1].x != LEFT_SIDE_X + 2 && snake->part[snake->size - 1].y != TOP_SIDE_Y + 14) {
				cleargate = true;
				drawBlank(LEFT_SIDE_X + 1, TOP_SIDE_Y + 13, 3, 3);
			}
			break;
	}
}

void renderNewStage(int &gatecount, int &maxpoint, bool &cleargate) {
	POSITION temp;
	temp = snake->head;
	drawBlank(27, 6, 89, 19);
	stage++;
	graphSet(stage % 5 + 1, snake);
	gatecount = 0;
	maxpoint += 100;
	desGate(stage % 5 + 1);
	cleargate = false;
	gotoXY(temp.x, temp.y);
	textColorWithBackground(map[temp.y - TOP_SIDE_Y][temp.x - LEFT_SIDE_X][1], WHITE);
	if (map[temp.y - TOP_SIDE_Y][temp.x - LEFT_SIDE_X][0] == 0) cout << " ";
	else cout << char(map[temp.y - TOP_SIDE_Y][temp.x - LEFT_SIDE_X][0]);
	
}

void snakeDisappear(POSITION head, int speedcontrol) {
	int temp = 0;
	while (!getInGate(snake->part[snake->size - 1])) {
		renderSnake(head);
		clearTail();
		textColorWithBackground(DARK_YELLOW, BLACK);
		gotoXY(snake->part[temp].x, snake->part[temp].y);
		cout << stid[temp];
		textColorWithBackground(DARK_YELLOW, WHITE);
		for (int i = temp + 1; i < snake->size - 1; i++) {
			if (map[snake->part[i].y - TOP_SIDE_Y][snake->part[i].x - LEFT_SIDE_X][0] != BUSH_LV3
			&& map[snake->part[i].y - TOP_SIDE_Y][snake->part[i].x - LEFT_SIDE_X][0] <= BUSH_LV2
			&& map[snake->part[i].y - TOP_SIDE_Y][snake->part[i].x - LEFT_SIDE_X][0] <= BUSH_LV1){
				gotoXY(snake->part[i].x, snake->part[i].y);
				cout << stid[i];
			}

		}
		Sleep(speedcontrol);
		temp++;
	}

}

// reset
void resetScore() {
	textColorWithBackground(DARK_YELLOW, WHITE);
	gotoXY(10, 9);
	cout << score;
}

void resetSpeed() {
	textColorWithBackground(DARK_YELLOW, WHITE);
	gotoXY(10, 7);
	if (speedcontrol < 14)
		cout << speedcontrol + 1;
	else
		cout << "MAX";
}

// load data into game play
void loadClassicDataIntoGame(CLASSICDATA data) {
	if (data.snake->part[0].x == data.snake->part[1].x) {
		if (data.snake->part[0].y - data.snake->part[1].y > 0) {
			dir = DOWN;
			charlock = UP;
		}
		else {
			dir = UP;
			charlock = DOWN;
		}
	}
	else if (data.snake->part[0].x - data.snake->part[1].x > 0) {
		dir = RIGHT;
		charlock = LEFT;
	}
	else {
		dir = LEFT;
		charlock = RIGHT;
	}
	score = data.score;
	gameover = false;
	save = false;
	difficulty = data.difficulty;
	snake->part = new POSITION[100];
	snake->head = data.snake->head;
	snake->size = data.snake->size;
	for (int i = 0; i < snake->size; i++) {
		snake->part[i] = data.snake->part[i];
	}
	stage = data.stage;
}

void loadTimeRushDataIntoGame(TIMERUSHDATA data) {
	if (data.snake->part[0].x == data.snake->part[1].x) {
		if (data.snake->part[0].y - data.snake->part[1].y > 0) {
			dir = DOWN;
			charlock = UP;
		}
		else {
			dir = UP;
			charlock = DOWN;
		}
	}
	else if (data.snake->part[0].x - data.snake->part[1].x > 0) {
		dir = RIGHT;
		charlock = LEFT;
	}
	else {
		dir = LEFT;
		charlock = RIGHT;
	}
	score = data.score;
	gameover = false;
	save = false;
	difficulty = data.difficulty;
	gametime = data.time;
	snake->part = new POSITION[100];
	snake->head = data.snake->head;
	snake->size = data.snake->size;
	for (int i = 0; i < snake->size; i++) {
		snake->part[i] = data.snake->part[i];
	}
	stage = data.stage;
}

void loadInfiniteDataIntoGame(INFINITEDATA data) {
	if (data.snake->part[0].x == data.snake->part[1].x) {
		if (data.snake->part[0].y - data.snake->part[1].y > 0) {
			dir = DOWN;
			charlock = UP;
		}
		else {
			dir = UP;
			charlock = DOWN;
		}
	}
	else if (data.snake->part[0].x - data.snake->part[1].x > 0) {
		dir = RIGHT;
		charlock = LEFT;
	}
	else {
		dir = LEFT;
		charlock = RIGHT;
	}
	score = data.score;
	gameover = false;
	save = false;
	snake->part = new POSITION[100];
	snake->head = data.snake->head;
	snake->size = data.snake->size;
	for (int i = 0; i < snake->size; i++) {
		snake->part[i] = data.snake->part[i];
	}
}

// create new game
void newClassicGame(int difficulty) {
	switch (difficulty) {
		case 0:
			speedcontrol = 200;
			break;
		case 1:
			speedcontrol = 90;
			break;
		case 2:
			speedcontrol = 30;
			break;
		default:
			break;
	}
	drawBlank(27, 6, 89, 19);
	graphSet(stage, snake);
	generateFood(foodnum, food);
	printFood(food);
	bool visit = false;
	bool cleargate = false;
	int gatecount = 0;
	int maxpoint = stage * 100;

	while (!gameover) {
		temp = dir;
		getDir();
		moving(1);
		clearTail();
		if (snake->size > 1 && !getInGate(snake->head)) checkSelfHitting(snake);
		checkCollisionBoard(snake);
		checkCollisionObstacles(snake);
		if (score == maxpoint && gatecount == 0) {
			generateGate(map);
			gatecount++;
		} else if (score == maxpoint && gatecount == 1) {
			if (getInGate(snake->head) == true)  {
				snakeDisappear(snake->head, speedcontrol);
				renderNewStage(gatecount, maxpoint, cleargate);
			}
		} else if (eatFood(food) == true) {
			score += 10;
			resetScore();
			clearFood(food);
			if (score != maxpoint) {
				generateFood(foodnum, food);
				printFood(food);
			} else {
				removeFood(food);
			}
			generatePart(snake);
		}
		if (cleargate == false) {
			removeDesGate(stage % 5 + 1, cleargate);
			if (cleargate == true) {
				generateFood(foodnum, food);
				printFood(food);
			}
		}
		renderSnake(snake->head);
		printSnake(snake);
		Sleep(speedcontrol);
	}
	if (save == false) deathEffect(snake);
	drawBoard(1, 5, INFO_BOARD_LENGTH + 1, INFO_BOARD_WIDTH, PURPLE);
	for (int i = 0; i < 25; i++) {
		gotoXY(0, i);
		cout << ' ';
	}
	dir = STOP;
}

void newTimeRushGame(int stage, int difficulty) {
	switch (difficulty) {
	case 0:
		speedcontrol = 200;
		break;
	case 1:
		speedcontrol = 90;
		break;
	case 2:
		speedcontrol = 30;
		break;
	default:
		break;
	}
	drawBlank(27, 6, 89, 19);
	POSITION timefood;
	graphSet(stage, snake);
	generateFood(foodnum, food);
	printFood(food);
	generateTimeFood(foodnum, timefood);
	printTimeFood(timefood);
	
	while (!gameover) {
		temp = dir;
		getDir();
		moving(2);
		clearTail();
		if (snake->size > 1 && !getInGate(snake->head)) checkSelfHitting(snake);
		checkCollisionBoard(snake);
		checkCollisionObstacles(snake);
		if (eatFood(food) == true) {
			score += 10;
			resetScore();
			clearFood(food);
			generateFood(foodnum, food);
			printFood(food);
			generatePart(snake);
		}
		if (eatFood(timefood) == true) {
			if (gametime > 310) {
				gametime = 360;
			} else {
				gametime += 50;
			}
			clearFood(timefood);
			generateTimeFood(foodnum, timefood);
			printTimeFood(timefood);
		}
		renderSnake(snake->head);
		printSnake(snake);
		gametime--;
		if (gametime == 0) gameover = true;
		renderTimeRush(snake, gametime);
		Sleep(speedcontrol);
	}
	if (save == false) deathEffect(snake);
	drawBoard(1, 5, INFO_BOARD_LENGTH + 1, INFO_BOARD_WIDTH, PURPLE);
	for (int i = 0; i < 25; i++) {
		gotoXY(0, i);
		cout << ' ';
	}
	dir = STOP;
}

void newInfiniteGame() {
	castMapBase();
	textColorWithBackground(PURPLE, WHITE);
	drawChoiceBox(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH + 1);
	speedcontrol = 0;
	textColorWithBackground(DARK_YELLOW, WHITE);
	gotoXY(3, 7);
	cout << "Speed: ";
	gotoXY(10, 7);
	cout << speedcontrol + 1;
	gotoXY(10, 9);
	cout << score;
	printSnake(snake);
	generateFood(foodnum, food);
	printFood(food);

	while (!gameover) {
		getDir();
		moving(3);
		clearTail();
		if (snake->size > 1) checkSelfHitting(snake);
		swapSide();
		if (eatFood(food) == true) {
			score += 10;
			if (speedcontrol < 14) speedcontrol++;
			resetScore();
			resetSpeed();
			clearFood(food);
			generateFood(foodnum, food);
			textColorWithBackground(BLACK, WHITE);
			printFood(food);
			generatePart(snake);
		}
		renderSnake(snake->head);
		printSnake(snake);
		Sleep(150 - speedcontrol * 10);
	}
	deathEffect(snake);
	textColorWithBackground(PURPLE, WHITE);
	drawChoiceBox(1, 5, INFO_BOARD_LENGTH + 1, INFO_BOARD_WIDTH + 1);
	dir = STOP;
}

void openGame() {
	setlocale(LC_CTYPE, ".OCP");
	fixConsoleWindow();
	noCursorType();
	changeConsoleColor(WHITE);
	//loading();
	loadClassicFile(classic_data, classic_player);
	loadTimeRushFile(timerush_data, timerush_player);
	loadInfiniteFile(infinite_data, infinite_player);
	while (true) {
		mainMenu();
		POSITION choice = inputMainMenu();
		if (choice.x == 0 && choice.y == 0) {
			system("cls");
			playMenu();
			POSITION sub_choice = inputPlayMenu();
			if (sub_choice.x == 1) {
				// ve lai menu
			} else if (sub_choice.y == 0) {
				POSITION minichoice = subChoiceMenu();
				if (minichoice.x == 1) {
					//ve lai menu
				} else if (minichoice.y == 0) {
					difficulty = choseDifficulty();
					if (difficulty != -1) {
						drawBlank(40, 11, 40, 9);
						name = inputName();
						gameSetup();
						// che do choi classic
						infoBoard(1, 5);
						drawBoard(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH, PURPLE);
						infoSet(1);
						// goi game
						newClassicGame(difficulty);
						textColorWithBackground(CYAN, WHITE);
						drawBoard(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH, PURPLE);
						drawBlank(27, 6, 89, 19);
						gameOverSign();
						Sleep(1000);
					}
				} else {
					gameSetup();
					int idx = loadSaveClassicPlayer(classic_data, classic_player);
					if (idx != -1) {
						loadClassicDataIntoGame(classic_data[idx]);
						// che do choi classic
						infoBoard(1, 5);
						drawBoard(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH, PURPLE);
						infoSet(1);
						// goi game
						newClassicGame(difficulty);
						textColorWithBackground(CYAN, WHITE);
						drawBoard(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH, PURPLE);
						drawBlank(27, 6, 89, 19);
						gameOverSign();
						Sleep(1000);
					}
				}

			} else if (sub_choice.y == 1) {
				//che do time rush
				POSITION minichoice = subChoiceMenu();
				if (minichoice.x == 1) {
					//ve lai menu
				} else if (minichoice.y == 0) {
					difficulty = choseDifficulty();
					if (difficulty != -1) {
						gametime = 360;
						drawBlank(40, 11, 40, 9);
						name = inputName();
						gameSetup();
						infoBoard(1, 5);
						drawBoard(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH, PURPLE);
						infoSet(1);
						// goi game
						newTimeRushGame(inputTimeChoice(), difficulty);
						drawBoard(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH, PURPLE);
						drawBlank(27, 6, 89, 19);
						gameOverSign();
						Sleep(1000);
					}
				} else {
					gameSetup();
					int idx = loadSaveTimeRushPlayer(timerush_data, timerush_player);
					if (idx != -1) {
						loadTimeRushDataIntoGame(timerush_data[idx]);
						infoBoard(1, 5);
						drawBoard(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH, PURPLE);
						infoSet(1);
						// goi game
						newTimeRushGame(stage, difficulty);
						drawChoiceBox(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH + 1);
						drawBlank(27, 6, 89, 19);
						gameOverSign();
						Sleep(1000);
					}
				}
			} else {
				//che do choi infinitie
				POSITION minichoice = infiniteSubChoiceMenu();
				drawBlank(1, 5, INFO_BOARD_LENGTH, INFO_BOARD_WIDTH);
				if (minichoice.x == 1) {
					//ve lai menu
				} else if (minichoice.y == 0) {
					textColorWithBackground(PURPLE, WHITE);
					drawChoiceBox(1, 5, INFO_BOARD_LENGTH + 1, INFO_BOARD_WIDTH + 1);
					infoSet(3);
					gameSetup();
					newInfiniteGame();
					drawChoiceBox(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH + 1);
					drawBlank(27, 6, 89, 19);
					gameOverSign();
					Sleep(1000);
				} else {
					gameSetup();
					infoSet(3);
					textColorWithBackground(PURPLE, WHITE);
					drawChoiceBox(1, 5, INFO_BOARD_LENGTH + 1, INFO_BOARD_WIDTH + 1);
					int idx = loadSaveInfinitePlayer(infinite_data, infinite_player);
					if (idx != -1) {
						loadInfiniteDataIntoGame(infinite_data[idx]);
						drawBlank(27, 6, 89, 19);
						newInfiniteGame();
						drawChoiceBox(26, 5, PLAY_SCREEN_LENGTH, PLAY_SCREEN_WIDTH + 1);
						drawBlank(27, 6, 89, 19);
						gameOverSign();
					}
					Sleep(1000);
				}

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
			saveClassicFile(classic_data, classic_player);
			freeClassicData(classic_data, classic_player);
			saveInfiniteFile(infinite_data, infinite_player);
			freeInfiniteData(infinite_data, infinite_player);
			saveTimeRushFile(timerush_data, timerush_player);
			freeTimeRushData(timerush_data, timerush_player);
			break;
		}
	}
}