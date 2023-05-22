#pragma once

#include "dictraVect.hpp"

namespace dictVect {

    void swap(Triplet& a, Triplet& b) {
        auto tmp = a;
        a = b;
        b = tmp;

    }

    void push(DictraVectContext& c, Triplet val) {
        c.prioQueu.push_back(val);
    }

    Triplet pop(DictraVectContext& c) {
        int idx = 0;
        int prio = c.prioQueu[0].prio;
        for (int i = 0; i < c.prioQueu.size(); i++) {
            if (c.prioQueu[i].prio < prio) {
                idx = i;
                prio = c.prioQueu[i].prio;
            }
        }

        auto res = c.prioQueu[idx];
        swap(c.prioQueu[idx], c.prioQueu[c.prioQueu.size() - 1]);
        c.prioQueu.pop_back();
        return res;
    }

    DictraVectContext creteDictraVectContext(const Bord& bord) {
        DictraVectContext res;
        for (int i = 0; i < bord.xSize; i++) {
            for (int j = 0; j < bord.ySize; j++) {
                if (bord.data[i][j] == START) {
                    Triplet start = {i, j, 0};
                    push(res, start);
                    return res;
                }
            }
        }
        return res;
    }

    bool hasNext(const DictraVectContext& c) {
        return c.prioQueu.size() != 0;
    }

    bool nextStep(const Bord& bord, DictraVectContext& c) {
        bool next = hasNext(c);
        if(!next) {
            return true;
        }
        Triplet item = pop(c);

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
            Triplet toPush = {item.first - 1, item.second, item.prio + 1};
            push(c, toPush);
        }

        auto up = bord.data[item.first][item.second - 1];
        if (up == EMPTY || up == END) {
            if(up == EMPTY) {
                bord.data[item.first][item.second - 1] = QUEUED;
            }
            Triplet toPush = {item.first, item.second - 1, item.prio + 1};
            push(c, toPush);
        }

        auto right = bord.data[item.first + 1][item.second];
        if (right == EMPTY || right == END) {
            if(right == EMPTY) {
                bord.data[item.first + 1][item.second] = QUEUED;
            }
            Triplet toPush = {item.first + 1, item.second, item.prio + 1};
            push(c, toPush);
        }

        auto down = bord.data[item.first][item.second + 1];
        if (down == EMPTY || down == END) {
            if(down == EMPTY) {
                bord.data[item.first][item.second + 1] = QUEUED;
            }
            Triplet toPush = {item.first, item.second + 1, item.prio + 1};
            push(c, toPush);
        }

        return false;
    }
}