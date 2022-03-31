#pragma once
#ifndef OBJECT
#define OBJECT

// struct
struct POSITION {
	int x;
	int y;

};

// snake
struct PART {
	POSITION part;
	// int length;
	// int speed;
	// int dir;
	// PART *nextPart;

};
struct SNAKE {
	PART *body;
	int size;
};


// obstacle


// support function




#endif // OBJECT