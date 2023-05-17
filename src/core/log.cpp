#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Bord.cpp"
#include "../depthFirst.hpp"
#include "../breadthFirst.hpp"

using namespace std;

void log(const string& msg) {
    cout<< msg << endl;
}

void log(const Bord& bord) {
    cout<< "xSize: " << bord.xSize << " ySize: " << bord.ySize << " squerSize: " << bord.squerSize << endl;
    cout<< "data: " << endl;
    for (size_t j = 0; j < bord.ySize; j++) {
        char a[] = {0, 0, 0, 0, 0, 0, 0};
        sprintf(a, "%2d", j);
        cout << a << ": " << bord.data[0][j];
        for (size_t i = 1; i < bord.xSize; i++) {
            cout << ", " << bord.data[i][j];
        }
        cout << endl;
    }
}

void log(const pair<int, int>& c, bool end) {
    cout <<"(" << c.first << ", " << c.second;
    if(end) {
        cout << endl;
    }
}

void log(int val) {
    cout << val << "\n";
}

string pairToString(const pair<int, int>& pair) {
    string firstStr = to_string(pair.first);
    string secondStr = to_string(pair.second);
    return "(" + firstStr + ", " + secondStr + ")";
}

void log(const pair<int, int>& pair) {
    cout << pairToString(pair) << endl;
}

string vectorPairToString(const vector<pair<int, int>>& vec) {
    string result;
    
    for (const auto& pair : vec) {
        result += pairToString(pair) + " ";
    }
    
    return result;
}

void log(const DepthFirstContext& c) {
    cout << "Queue: " << vectorPairToString(c.stack) << endl;
}

void log(const BreadthFirstContext& c) {
    cout << "In: " << vectorPairToString(c.queueIn) << endl;
    cout << "Out: " << vectorPairToString(c.queueOut) << endl;
    
}
