
#include <cmath>
#include "aHeap.hpp"

namespace aHeap {

    void push(AContext& c, int priority, Triplet<int, int, int> val) {
        c.minHeap.push(priority, val);
    }

    Triplet<int, int, int> pop(AContext& c) {
        return c.minHeap.pop();
    }

    int aproxPriority(AContext& c, Triplet<int, int, int> position) {
        int x = abs(c.end.first - position.first);
        int y = abs(c.end.second - position.second);
        int res = position.prio + x + y;
        return res;
    }

    bool hasNext(const AContext& c) {
        return c.minHeap.hasNext();
    }

    AContext creteAHeapContext(const Bord& bord) {
        AContext res;
        for (int i = 0; i < bord.xSize; i++) {
            for (int j = 0; j < bord.ySize; j++) {
                if (bord.data[i][j] == START) {
                    Triplet<int, int, int> start(i, j, 0);
                    push(res, 0, start);
                }
                if (bord.data[i][j] == END) {
                    Pair<int, int> end(i, j);
                    res.end = end;
                }
            }
        }
        return res;
    }

    bool nextStep(const Bord& bord, AContext& c) {
        bool next = hasNext(c);
        if(!next) {
            return true;
        }
        Triplet<int, int, int> item = pop(c);

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
            Triplet<int, int, int> nextItem(item.first - 1, item.second, item.prio);
            nextItem.prio = aproxPriority(c, nextItem);
            push(c, nextItem.prio, nextItem);
        }

        auto up = bord.data[item.first][item.second - 1];
        if (up == EMPTY || up == END) {
            if(up == EMPTY) {
                bord.data[item.first][item.second - 1] = QUEUED;
            }
            Triplet<int, int, int> nextItem(item.first, item.second - 1, item.prio);
            nextItem.prio = aproxPriority(c, nextItem);
            push(c, nextItem.prio, nextItem);
        }

        auto right = bord.data[item.first + 1][item.second];
        if (right == EMPTY || right == END) {
            if(right == EMPTY) {
                bord.data[item.first + 1][item.second] = QUEUED;
            }
            Triplet<int, int, int> nextItem(item.first + 1, item.second, item.prio);
            nextItem.prio = aproxPriority(c, nextItem);
            push(c, nextItem.prio, nextItem);
        }

        auto down = bord.data[item.first][item.second + 1];
        if (down == EMPTY || down == END) {
            if(down == EMPTY) {
                bord.data[item.first][item.second + 1] = QUEUED;
            }
            Triplet<int, int, int> nextItem(item.first, item.second + 1, item.prio);
            nextItem.prio = aproxPriority(c, nextItem);
            push(c, nextItem.prio, nextItem);
        }

        return false;
    }
}