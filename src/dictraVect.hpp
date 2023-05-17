#pragma once

#include <utility>
#include <vector>

using namespace std;

struct Triplet {
    int first, second, prio;
};

struct DictraVectContext {
    vector<Triplet> prioQueu;
};