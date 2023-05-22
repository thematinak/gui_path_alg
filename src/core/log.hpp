#pragma once

#include <string>
#include <utility>
#include "Bord.hpp"
#include "../depthFirst.hpp"
#include "../breadthFirst.hpp"

using namespace std;

void log(const string& msg);

void log(const Bord& bord);

void log(const pair<int, int>& c, bool end);

void log(int val);

void log(const pair<int, int>& pair);

void log(const DepthFirstContext& c);

void log(const BreadthFirstContext& c);
