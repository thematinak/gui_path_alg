#pragma once

#include <utility>
#include <vector>

#include "core/Bord.hpp"

using namespace std;

struct DepthFirstContext {
    vector<pair<int, int>> stack;
};

namespace depth {

    DepthFirstContext creteDepthFirstContext(const Bord& bord);

    bool nextStep(const Bord& bord, DepthFirstContext& c);
}