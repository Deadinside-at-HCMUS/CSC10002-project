#include "Init.h"
using namespace std;

//classic
void saveClassicFile(CLASSICDATA *data, int playercount) {
    ofstream fOut;
    fOut.open("classicData.txt", ios::out);
    fOut << playercount << endl;

    for (int i = 0; i < playercount; i++) {
        fOut << "Player: " << data[i].classicname << endl;
        fOut << "Stage: " << data[i].stage << endl;
        fOut << "Score: " << data[i].score << endl;
        fOut << "Difficulty: " << data[i].difficulty << endl;
        fOut << "Head: " << data[i].snake->head.x << ' ' << data[i].snake->head.y << endl;
        fOut << "Part:";
        int j = 0;
        for ( ; j < data[i].snake->size - 1; j++) {
            fOut << ' ' << data[i].snake->part[j].x << ' ' << data[i].snake->part[j].y << ',';
        }
        fOut << ' ' << data[i].snake->part[j].x << ' ' << data[i].snake->part[j].y << '.' << endl;
        fOut << endl;
    }
    fOut.close();
}

void loadClassicFile(CLASSICDATA *&data, int &playercount) {
    ifstream fIn;
    fIn.open("classicData.txt", ios::in);
    fIn >> playercount;
    if (playercount != 0) {
        data = new CLASSICDATA[playercount];
        for (int i = 0; i < playercount; i++) {
            fIn.ignore(100, ' ');
            getline(fIn, data[i].classicname);
            fIn.ignore(100, ':');
            fIn >> data[i].stage;
            fIn.ignore(100, ':');
            fIn >> data[i].score;
            fIn.ignore(100, ':');
            fIn >> data[i].difficulty;
            fIn.ignore(100, ':');
            data[i].snake = new SNAKE;
            fIn >> data[i].snake->head.x >> data[i].snake->head.y;
            fIn.ignore(100, ':');
            data[i].snake->size = data[i].score / 10 + 1;
            data[i].snake->part = new POSITION[data[i].snake->size];
            for (int j = 0; j < data[i].snake->size; j++) {
                fIn >> data[i].snake->part[j].x >> data[i].snake->part[j].y;
                fIn.ignore();
            }
            fIn.ignore(2);
        }
    }
    fIn.close();
}

void moveClassicData(CLASSICDATA *des, CLASSICDATA *src, int playercount) {
    if (src == nullptr || des == nullptr) return;
    for (int i = 0; i < playercount; i++) {
        des[i] = src[i];
    }
}

CLASSICDATA *pushClassicData(CLASSICDATA *data, CLASSICDATA player, int &playercount) {
    CLASSICDATA* temp = new CLASSICDATA[playercount + 1];
    if (data != nullptr) {
        moveClassicData(temp, data, playercount);
        playercount++;
        temp[playercount] = player;
        freeClassicData(data, playercount - 1);
    }
    else {
        playercount++;
        temp[0] = player;
    }
    return temp;
}

void freeClassicData(CLASSICDATA *data, int playercount) {
    for (int i = 0; i < playercount; i++) {
        delete[] data[i].snake->part;
        delete data[i].snake;
    }
    delete[] data;
}

// infinite
void saveInfiniteFile(INFINITEDATA *data, int playercount) {
    ofstream fOut;
    fOut.open("infiniteData.txt", ios::out);
    fOut << playercount << endl;

    for (int i = 0; i < playercount; i++) {
        fOut << "Player: " << data[i].infinitename << endl;
        fOut << "Score: " << data[i].score << endl;
        fOut << "Head: " << data[i].snake->head.x << ' ' << data[i].snake->head.y << endl;
        fOut << "Part:";
        int j = 0;
        for ( ; j < data[i].snake->size - 1; j++) {
            fOut << ' ' << data[i].snake->part[j].x << ' ' << data[i].snake->part[j].y << ',';
        }
        fOut << ' ' << data[i].snake->part[j].x << ' ' << data[i].snake->part[j].y << '.' << endl;
        fOut << endl;
    }
    fOut.close();
}

void loadInfiniteFile(INFINITEDATA *&data, int &playercount) {
    ifstream fIn;
    fIn.open("infiniteData.txt", ios::in);
    fIn >> playercount;
    if (playercount != 0) {
        data = new INFINITEDATA[playercount];
        for (int i = 0; i < playercount; i++) {
            fIn.ignore(100, ' ');
            getline(fIn, data[i].infinitename);
            fIn.ignore(100, ':');
            fIn >> data[i].score;
            fIn.ignore(100, ':');
            data[i].snake = new SNAKE;
            fIn >> data[i].snake->head.x >> data[i].snake->head.y;
            fIn.ignore(100, ':');
            data[i].snake->size = data[i].score / 10 + 1;
            data[i].snake->part = new POSITION[data[i].snake->size];
            for (int j = 0; j < data[i].snake->size; j++) {
                fIn >> data[i].snake->part[j].x >> data[i].snake->part[j].y;
                fIn.ignore();
            }
            fIn.ignore(2);
        }
    }
    fIn.close();
}

void moveInfiniteData(INFINITEDATA *des, INFINITEDATA *src, int playercount) {
    if (src == nullptr || des == nullptr) return;
    for (int i = 0; i < playercount; i++) {
        des[i] = src[i];
    }
}

INFINITEDATA *pushInfiniteData(INFINITEDATA *data, INFINITEDATA player, int &playercount) {
    INFINITEDATA* temp = new INFINITEDATA[playercount + 1];
    if (data != nullptr) {
        moveInfiniteData(temp, data, playercount);
        playercount++;
        temp[playercount] = player;
        freeInfiniteData(data, playercount - 1);
    }
    else {
        playercount++;
        temp[0] = player;
    }
    return temp;
}

void freeInfiniteData(INFINITEDATA *data, int playercount) {
    for (int i = 0; i < playercount; i++) {
        delete[] data[i].snake->part;
        delete data[i].snake;
    }
    delete[] data;
}


//time rush
void saveTimeRushFile(TIMERUSHDATA *data, int playercount) {
    ofstream fOut;
    fOut.open("timeRushData.txt", ios::out);
    fOut << playercount << endl;

    for (int i = 0; i < playercount; i++) {
        fOut << "Player: " << data[i].timerushname << endl;
        fOut << "Stage: " << data[i].stage << endl;
        fOut << "Score: " << data[i].score << endl;
        fOut << "Time: " << data[i].time << endl;
        fOut << "Head: " << data[i].snake->head.x << ' ' << data[i].snake->head.y << endl;
        fOut << "Part:";
        int j = 0;
        for ( ; j < data[i].snake->size - 1; j++) {
            fOut << ' ' << data[i].snake->part[j].x << ' ' << data[i].snake->part[j].y << ',';
        }
        fOut << ' ' << data[i].snake->part[j].x << ' ' << data[i].snake->part[j].y << '.' << endl;
        fOut << endl;
        
    }
    fOut.close();
}

void loadTimeRushFile(TIMERUSHDATA *&data, int &playercount) {
    ifstream fIn;
    fIn.open("timeRushData.txt", ios::in);
    fIn >> playercount;
    if (playercount != 0) {
        data = new TIMERUSHDATA[playercount];
        for (int i = 0; i < playercount; i++) {
            fIn.ignore(100, ' ');
            getline(fIn, data[i].timerushname);
            fIn.ignore(100, ':');
            fIn >> data[i].stage;
            fIn.ignore(100, ':');
            fIn >> data[i].score;
            fIn.ignore(100, ':');
            fIn >> data[i].time;
            fIn.ignore(100, ':');
            fIn >> data[i].difficulty;
            fIn.ignore(100, ':');
            data[i].snake = new SNAKE;
            fIn >> data[i].snake->head.x >> data[i].snake->head.y;
            fIn.ignore(100, ':');
            data[i].snake->size = data[i].score / 10 + 1;
            data[i].snake->part = new POSITION[data[i].snake->size];
            for (int j = 0; j < data[i].snake->size; j++) {
                fIn >> data[i].snake->part[j].x >> data[i].snake->part[j].y;
                fIn.ignore();
            }
            fIn.ignore(2);
        }
    }
    fIn.close();
}

void moveTimeRushData(TIMERUSHDATA *des, TIMERUSHDATA *src, int playercount) {
    if (src == nullptr || des == nullptr) return;
    for (int i = 0; i < playercount; i++) {
        des[i] = src[i];
    }
}

TIMERUSHDATA *pushTimeRushData(TIMERUSHDATA *data, TIMERUSHDATA player, int &playercount) {
    TIMERUSHDATA* temp = new TIMERUSHDATA[playercount + 1];
    if (data != nullptr) {
        moveTimeRushData(temp, data, playercount);
        playercount++;
        temp[playercount] = player;
        freeTimeRushData(data, playercount - 1);
    }
    else {
        playercount++;
        temp[0] = player;
    }
    return temp;
}

void freeTimeRushData(TIMERUSHDATA *data, int playercount) {
    for (int i = 0; i < playercount; i++) {
        delete[] data[i].snake->part;
        delete data[i].snake;
    }
    delete[] data;
}