#pragma once
#ifndef GAME
#define GAME

// game setting
#define MAX_SPEED 20
#define MAX_LENGTH 20

// game function
void gameSetup();

bool isValidFood(int x, int y);

bool isValidGate();

bool eatFood();

// create game
void newClassicGame();

void newInfiniteGame();

#endif // GAME