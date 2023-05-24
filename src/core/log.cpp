
#include "log.hpp"
#include <iostream>

using namespace std;

void log(const string& msg) {
    cout << msg << endl;
}

void log(const Bord& bord) {
    cout << "xSize: " << bord.xSize << " ySize: " << bord.ySize << " squerSize: " << bord.squerSize << endl;
    cout << "data: " << endl;
    for (int j = 0; j < bord.ySize; j++) {
        char a[] = {0, 0, 0, 0, 0, 0, 0};
        sprintf(a, "%2d", j);
        cout << a << ": " << bord.data[0][j];
        for (int i = 1; i < bord.xSize; i++) {
            cout << ", " << bord.data[i][j];
        }
        cout << endl;
    }
}

void log(int val) {
    cout << val << "\n";
}

void log(const Pair<int, int>& pair, bool end) {
    cout << pair.toString();
    if(end) {
        cout << endl;
    }
}

void log(const Pair<int, int>& pair) {
    log(pair, true);
}

void log(const DepthFirstContext& c) {
    cout << c.stack.toString() << endl;
}

void log(const BreadthFirstContext& c) {
    cout << c.queue.toString() << endl;
    
}
