#pragma once

#include <utility>
#include <vector>

#include "core/Bord.hpp"

using namespace std;

struct Triplet {
    int first, second, prio;
};

struct DictraVectContext {
    vector<Triplet> prioQueu;
};

namespace dictVect {

    DictraVectContext creteDictraVectContext(const Bord& bord);

    bool nextStep(const Bord& bord, DictraVectContext& c);

}