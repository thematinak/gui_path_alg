#pragma once

#include <string>
#include <sstream>

template<class T1, class T2>
class Pair {
    public:
        T1 first;
        T2 second;

        Pair() {
            first = 0;
            second = 0;
        }

        Pair(T1 f, T2 s) {
            first = f;
            second = s;
        }

        std::string toString() const {
            std::ostringstream oss;
            oss << "(" << first << ", " << second << ")";
            return oss.str();
        }

};