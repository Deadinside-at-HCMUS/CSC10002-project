#pragma once
#ifndef PARAMETER
#define PARAMETER

#define ENTER 13
#define ESC 27
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

void drawChar(int x, int y, int color, int character);

#endif // PARAMETER