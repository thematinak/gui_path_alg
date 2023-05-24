#pragma once

#include "dataStructures/Queue.cpp"
#include "core/Bord.hpp"
#include "core/Pair.cpp"


using namespace std;

struct BreadthFirstContext {
    Queue<Pair<int, int>> queue;
};

namespace breadth {

    BreadthFirstContext creteBreadthFirstContext(const Bord& bord);

    bool nextStep(const Bord& bord, BreadthFirstContext& c);

}
