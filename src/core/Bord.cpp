
#include <fstream>

#include "Bord.hpp"
#include "log.hpp"

int getType(char a) {
    if(a == '#') {
        return WALL;
    } else if (a == '.') {
        return EMPTY;
    } else if (a == '0') {
        return START;
    } else if (a == '1') {
        return END;
    } else {
        return WALL;
    }
}

Bord createBord(const int sizeX, const int sizeY, const int squerSize) {
    Bord b;
    b.xSize = sizeX;
    b.ySize = sizeY;
    b.squerSize = squerSize;

    b.data = new int*[sizeX];
    for(int i = 0; i < sizeX; i++) {
        b.data[i] = new int[sizeY];
        for (int j = 0; j < sizeY; j++) {
            b.data[i][j] = EMPTY;
        }
    }

    return b;
}

Bord createBord(const std::string& pathToFile, const int width, const int height, const int squerSize) {
    std::ifstream myfile; 
    myfile.open(pathToFile);
    if (myfile.is_open()) {
        log("file opened");
        std::string line;
        int x, y;
        myfile >> x >> y;
        std::getline(myfile, line);
        Bord bord = createBord(x, y, std::min(width / x, height / y));
        for(int i = 0; i < y; i++) {
            std::getline(myfile, line);
            for(int j = 0; j < x; j++) {
                bord.data[j][i] = getType(line[j]);
            }
        }
        log(bord);
        return bord;
    } else {
        log("file not opend");
        Bord bord;
        return bord;
    }
}