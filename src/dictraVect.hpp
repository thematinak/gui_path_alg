#pragma once

#include "core/Bord.hpp"
#include "core/Triplet.cpp"
#include "dataStructures/Vector.cpp"

using namespace std;

struct DictraVectContext {
    Vector<Triplet<int, int, int>> prioQueu;
};

namespace dictVect {

    DictraVectContext creteDictraVectContext(const Bord& bord);

    bool nextStep(const Bord& bord, DictraVectContext& c);

}