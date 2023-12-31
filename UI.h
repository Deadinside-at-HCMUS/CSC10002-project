#pragma once
#ifndef UI
#define UI

// screen info
#define PLAY_SCREEN_LENGTH   92
#define PLAY_SCREEN_WIDTH    22
#define INFO_BOARD_LENGTH    23
#define INFO_BOARD_WIDTH     22
#define LEFT_SIDE_X          26
#define RIGHT_SIDE_X         118
#define TOP_SIDE_Y           5
#define BOTTOM_SIDE_Y        27

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

// art function
void drawBoard(int x, int y, int length, int width, int color);

void drawSmallLogo(int x, int y);

void drawChoiceBox(int x, int y, int length, int width);

void drawBlank(int x, int y, int length, int width);

void deathEffect(SNAKE* snake);

void pauseGameBoard(int x, int y);

void gameOverSign();

// menu function

POSITION inputMainMenu();

void loading();

void mainMenu();

POSITION inputMainMenu();

void playMenu();

POSITION inputPlayMenu();

int inputTimeChoice();

void inputMenuBoxEffect(POSITION choice, int color);

void inputPlayBoxEffect(POSITION choice, int color);

void infoBoard(int x, int y);

void infoSet(int type);

void gameTurtorial();

void aboutUs();

void renderTimeRush(SNAKE *snake, int& time);

POSITION subChoiceMenu();

POSITION infiniteSubChoiceMenu();

int choseDifficulty();

string inputName();

// load input
int loadSaveClassicPlayer(CLASSICDATA *data, int playercount);

int loadSaveTimeRushPlayer(TIMERUSHDATA *data, int playercount);

int loadSaveInfinitePlayer(INFINITEDATA *data, int playercount);

#endif // UI