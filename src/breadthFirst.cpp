
#include "breadthFirst.hpp"
#include "core/log.hpp"

namespace breadth {
    void push(BreadthFirstContext& c, Pair<int, int> val) {
        c.queue.push(val);
    }

    Pair<int, int> pop(BreadthFirstContext& c) {
        return c.queue.pop();
    }

    bool hasNext(const BreadthFirstContext& c) {
        return c.queue.hasNext();
    }

    BreadthFirstContext creteBreadthFirstContext(const Bord& bord) {
        BreadthFirstContext res;
        
        for (int i = 0; i < bord.xSize; i++) {
            for (int j = 0; j < bord.ySize; j++) {
                if (bord.data[i][j] == START) {
                    Pair<int, int> start(i, j);
                    push(res, start);
                    return res;
                }
            }
        }
        return res;
    }

    bool nextStep(const Bord& bord, BreadthFirstContext& c) {
        bool next = hasNext(c);
        if(!next) {
            return true;
        }
        Pair<int, int> item = pop(c);

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
            push(c, Pair<int, int>(item.first - 1, item.second));
        }

        auto up = bord.data[item.first][item.second - 1];
        if (up == EMPTY || up == END) {
            if(up == EMPTY) {
                bord.data[item.first][item.second - 1] = QUEUED;
            }
            push(c, Pair<int, int>(item.first, item.second-1));
        }

        auto right = bord.data[item.first + 1][item.second];
        if (right == EMPTY || right == END) {
            if(right == EMPTY) {
                bord.data[item.first + 1][item.second] = QUEUED;
            }
            push(c, Pair<int, int>(item.first + 1, item.second));
        }

        auto down = bord.data[item.first][item.second + 1];
        if (down == EMPTY || down == END) {
            if(down == EMPTY) {
                bord.data[item.first][item.second + 1] = QUEUED;
            }
            push(c, Pair<int, int>(item.first, item.second+1));
        }

        return false;
    }
}