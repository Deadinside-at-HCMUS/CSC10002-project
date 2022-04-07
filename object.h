#pragma once
#ifndef OBJECT
#define OBJECT

#define UPPER_BLOCK 223
#define BOTTOM_BLOCK 220
#define BLOCK 219
#define BUSH_LV1 176
#define BUSH_LV2 177
#define BUSH_LV3 178
#define FOOD 254
#define TIME_FOOD 233

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

// support function
void generatePart(SNAKE &snake);

void generateFood(int foodnum, POSITION &food);


#endif // OBJECT