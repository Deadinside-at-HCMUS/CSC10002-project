#pragma once
#ifndef OBJECT
#define OBJECT
#include <string>
using namespace std;
#define UPPER_BLOCK 223
#define BOTTOM_BLOCK 220
#define BLOCK 219
#define BUSH_LV1 176
#define BUSH_LV2 177
#define BUSH_LV3 178
#define FOOD 254
#define TIME_FOOD 235

// struct
struct POSITION {
	int x;
	int y;

};

// snake
struct SNAKE {
	POSITION head;
	POSITION *part;
	int size;
};

// player
struct CLASSICDATA {
	string classicname;
	int score;
	int difficulty;
	int stage;
	SNAKE *snake;
};

struct TIMERUSHDATA {
	string timerushname;
	int score;
	int stage;
	int difficulty;
	int time;
	SNAKE *snake;
};

struct INFINITEDATA {
	string infinitename;
	int score;
	SNAKE *snake;
};


// support function
void generatePart(SNAKE *snake);

void generateFood(int foodnum, POSITION &food);

void generateTimeFood(int foodnum, POSITION &food);

void generateGate(int map[22][92][2]);

void removeFood(POSITION &food);

#endif // OBJECT