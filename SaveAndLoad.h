#pragma once
#ifndef SAVEANDLOAD
#define SAVEANDLOAD

//classic
void saveClassicFile(CLASSICDATA *data, int playercount);

void loadClassicFile(CLASSICDATA *&data, int &playercount);

CLASSICDATA *pushClassicData(CLASSICDATA *data, CLASSICDATA player, int &playercount);

void freeClassicData(CLASSICDATA *data, int playercount);

//infinite
void saveInfiniteFile(INFINITEDATA *data, int playercount);

void loadInfiniteFile(INFINITEDATA *data, int &playercount);

INFINITEDATA *pushInfiniteData(INFINITEDATA *data, INFINITEDATA player, int &playercount);

void freeInfiniteData(INFINITEDATA *data, int playercount);

//timerush
void saveTimeRushFile(TIMERUSHDATA *data, int playercount);

void loadTimeRushFile(TIMERUSHDATA *data, int &playercount);

TIMERUSHDATA *pushTimeRushData(TIMERUSHDATA *data, TIMERUSHDATA player, int &playercount);

void freeTimeRushData(TIMERUSHDATA *data, int playercount);

#endif // SAVEANDLOAD