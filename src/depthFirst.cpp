#pragma once

#include "depthFirst.hpp"

using namespace std;

namespace depth {
    void push(DepthFirstContext& c, pair<int, int> val) {
        c.stack.push_back(val);
    }

    DepthFirstContext creteDepthFirstContext(const Bord& bord) {
        DepthFirstContext res;

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

    pair<int, int> pop(DepthFirstContext& c) {
        pair<int, int> res = c.stack[c.stack.size() - 1];
        c.stack.pop_back();
        return res;
    }

    bool hasNext(const DepthFirstContext& c) {
        return c.stack.size() != 0;
    }

    bool nextStep(const Bord& bord, DepthFirstContext& c) {
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