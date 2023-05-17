#pragma once

#include <utility>
#include <vector>
#include "core/Bord.hpp"


using namespace std;

struct BreadthFirstContext {
    vector<pair<int, int>> queueIn;
    vector<pair<int, int>> queueOut;
};
