#pragma once
#ifndef PARAMETER
#define PARAMETER

#define enter 13
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77

void fixConsoleWindow();

void gotoXY(int x, int y);

void changeConsoleColor(int BackC);

void textColorWithBackground(int frontcolor, int backcolor);

void noCursorType();

void resizeConsole(int width, int height);

#endif // PARAMETER