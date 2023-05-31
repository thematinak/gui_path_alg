#pragma once

#include "core/Bord.hpp"
#include "core/Triplet.cpp"
#include "dataStructures/Heap.cpp"

using namespace std;

struct DictraHeapContext {
    Heap<Triplet<int, int, int>> minHeap;
};

namespace dictHeap {

    DictraHeapContext creteDictraHeapContext(const Bord& bord);

    bool nextStep(const Bord& bord, DictraHeapContext& c);

}