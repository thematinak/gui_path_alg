#include <SFML/Graphics.hpp>
#include <chrono>

#include "core/Bord.hpp"
#include "core/drawBord.hpp"
#include "core/log.hpp"

#include "depthFirst.hpp"
#include "breadthFirst.hpp"
#include "dictraVect.hpp"
#include "dictraHeap.hpp"
#include "aHeap.hpp"

const int WIDTH = 500;
const int HEIGHT = 500;
const int CELL_SIZE = 10;

using namespace std;

int main() {

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
    
    Bord bord = createBord("./pr2.1.txt", WIDTH, HEIGHT, CELL_SIZE);
    DepthFirstContext depthC = depth::creteDepthFirstContext(bord);
    BreadthFirstContext breadthC = breadth::creteBreadthFirstContext(bord);
    DictraVectContext dictVecC = dictVect::creteDictraVectContext(bord);
    DictraHeapContext dictHeapC = dictHeap::creteDictraHeapContext(bord);
    AContext aC = aHeap::creteAHeapContext(bord);

    chrono::steady_clock::time_point prew_time = chrono::steady_clock::now();
    int64_t tickTime = 1000000 / 30;

    bool notFinnished = true;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        chrono::steady_clock::time_point time = chrono::steady_clock::now();
        chrono::microseconds i_duration = chrono::duration_cast<chrono::microseconds>(time - prew_time);
        if (i_duration.count() > tickTime && notFinnished) {
            // bool res = depth::nextStep(bord, depthC);
            // bool res = breadth::nextStep(bord, breadthC);
            // bool res = dictVect::nextStep(bord, dictVecC);
            // bool res = dictHeap::nextStep(bord, dictHeapC);
            bool res = aHeap::nextStep(bord, aC);
            if (res) {
                notFinnished = false;
                log("alog ended!");
            }
            prew_time = time;
        }

        drawBord(window, bord);

    }

    return 0;
}