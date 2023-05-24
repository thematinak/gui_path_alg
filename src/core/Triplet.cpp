#pragma once

#include <string>
#include <sstream>

template<class T1, class T2, class T3>
class Triplet {
    public:
        T1 first;
        T2 second;
        T3 prio;
        
        Triplet() {
            first = 0;
            second = 0;
            prio = 0;
        }

        Triplet(T1 f, T2 s, T3 t) {
            first = f;
            second = s;
            prio = t;
        }

        std::string toString() const {
            std::ostringstream oss;
            oss << "(" << first << ", " << second << ", " << prio << ")";
            return oss.str();
        }

};