#pragma once

#include "breadthFirst.hpp"

namespace breadth {
    void push(BreadthFirstContext& c, pair<int, int> val) {
        c.queueIn.push_back(val);
    }

    pair<int, int> pop(BreadthFirstContext& c) {
        if (c.queueOut.size() == 0) {
            for (int i = c.queueIn.size() - 1; i > -1; i--) {
                c.queueOut.push_back(c.queueIn[i]);
            }
            c.queueIn.clear();
        }
        auto res = c.queueOut[c.queueOut.size() - 1];
        c.queueOut.pop_back();
        return res;
    }

    BreadthFirstContext creteBreadthFirstContext(const Bord& bord) {
        BreadthFirstContext res;
        
        for (size_t i = 0; i < bord.xSize; i++) {
            for (size_t j = 0; j < bord.ySize; j++) {
                if (bord.data[i][j] == START) {
                    pair<int, int> start(i, j);
                    push(res, start);
                    return res;
                }
            }
        }
        return res;
    }

    bool hasNext(const BreadthFirstContext& c) {
        return c.queueOut.size() != 0 | c.queueIn.size() != 0;
    }

    bool nextStep(const Bord& bord, BreadthFirstContext& c) {
        bool next = hasNext(c);
        if(!next) {
            return true;
        }
        pair<int, int> item = pop(c);

        if (bord.data[item.first][item.second] == END) {
            return true;
        }
        if(bord.data[item.first][item.second] != START) {
            bord.data[item.first][item.second] = WISITED;
        }

        auto left = bord.data[item.first - 1][item.second];
        if (left == EMPTY || left == END) {
            if(left == EMPTY) {
                bord.data[item.first - 1][item.second] = QUEUED;
            }
            push(c, pair<int, int>(item.first - 1, item.second));
        }

        auto up = bord.data[item.first][item.second - 1];
        if (up == EMPTY || up == END) {
            if(up == EMPTY) {
                bord.data[item.first][item.second - 1] = QUEUED;
            }
            push(c, pair<int, int>(item.first, item.second-1));
        }

        auto right = bord.data[item.first + 1][item.second];
        if (right == EMPTY || right == END) {
            if(right == EMPTY) {
                bord.data[item.first + 1][item.second] = QUEUED;
            }
            push(c, pair<int, int>(item.first + 1, item.second));
        }

        auto down = bord.data[item.first][item.second + 1];
        if (down == EMPTY || down == END) {
            if(down == EMPTY) {
                bord.data[item.first][item.second + 1] = QUEUED;
            }
            push(c, pair<int, int>(item.first, item.second+1));
        }

        return false;
    }
}