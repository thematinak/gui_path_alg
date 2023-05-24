#pragma once

#include "core/Bord.hpp"
#include "core/Pair.cpp"
#include "dataStructures/Stack.cpp"

using namespace std;

struct DepthFirstContext {
    Stack<Pair<int, int>> stack;
};

namespace depth {

    DepthFirstContext creteDepthFirstContext(const Bord& bord);

    bool nextStep(const Bord& bord, DepthFirstContext& c);
}