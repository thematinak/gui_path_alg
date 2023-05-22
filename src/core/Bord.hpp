#pragma once

#include <string>

const int WALL = 0;
const int EMPTY = 1;
const int WISITED = 2;
const int START = 3;
const int END = 4;
const int QUEUED = 5;

struct Bord {
    int xSize;
    int ySize;
    int squerSize;
    int** data;
};

Bord createBord(const int sizeX, const int sizeY, const int squerSize);

Bord createBord(const std::string& pathToFile, const int width, const int height, const int squerSize);