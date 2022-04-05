#pragma once
#ifndef OBJECT
#define OBJECT

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


// obstacle
struct OBSTACLE {
	POSITION *contain;
};


// support function
void generatePart(SNAKE &snake);

void generateFood(int foodnum, POSITION &food);


#endif // OBJECT