#pragma once
#ifndef GAME
#define GAME

// game setting
#define MAX_SPEED 20
#define MAX_LENGTH 20
#define GATE_SPOT 3001

// game function
void gameSetup();

bool isValidFood(int x, int y);

bool isValidGate(int x, int y, int type);

bool eatFood();

// create game
void newClassicGame();

void newInfiniteGame();

// art
void printGate(int x, int y, int type);

#endif // GAME