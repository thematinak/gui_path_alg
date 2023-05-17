#pragma once

#include <string.h>

int WALL = 0;
int EMPTY = 1;
int WISITED = 2;
int START = 3;
int END = 4;
int QUEUED = 5;

struct Bord {
    int xSize;
    int ySize;
    int squerSize;
    int** data;
};

Bord createBord(const int sizeX, const int sizeY, const int squerSize);

Bord createBord(const std::string& pathToFile, const int width, const int height, const int squerSize);