#pragma once
#ifndef OBJECT
#define OBJECT

struct POSITION {
	int x;
	int y;

};

struct SNAKE {
	POSITION* part;
	int length;
	int speed;
	int dir;

};

#endif // OBJECT