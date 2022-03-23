#pragma once
#ifndef UI
#define UI

// screen info
#define PLAY_SCREEN_LENGTH   92
#define PLAY_SCREEN_WIDTH    22
#define INFO_BOARD_LENGTH    23
#define INFO_BOARD_WIDTH     22

// color info
#define BLACK			0
#define DARK_BLUE		1
#define DARK_GREEN		2
#define DARK_CYAN		3
#define DARK_RED		4
#define DARK_PINK		5
#define DARK_YELLOW		6
#define DARK_WHITE		7
#define GREY			8
#define BLUE			9
#define GREEN			10
#define CYAN			11
#define PINK			12
#define PURPLE			13
#define YELLOW			14
#define WHITE			15

void DrawBoard(int x, int y, int length, int width, int color);

void DrawSmallLogo(int x, int y);

void DrawChoiceBox(int x, int y, int length, int width);

POSITION InputMainMenu();

void Loading();

void MainMenu();

POSITION InputMainMenu();

void PlayMenu();

POSITION InputPlayMenu();

void InputMenuBoxEffect(POSITION choice, int color);

void InputPlayBoxEffect(POSITION choice, int color);

void InfoBoard(int x, int y);

void GameTurtorial();

void AboutUs();

#endif // UI