#pragma once

#include "core/Bord.hpp"
#include "core/Pair.cpp"
#include "core/Triplet.cpp"
#include "dataStructures/Heap.cpp"

using namespace std;

struct AContext {
    Heap<Triplet<int, int, int>> minHeap;
    Pair<int, int> end;
};

namespace aHeap {

    AContext creteAHeapContext(const Bord& bord);

    bool nextStep(const Bord& bord, AContext& c);

}