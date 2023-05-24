#pragma once

#include <string>
#include "Vector.cpp"

template<typename T>
class Queue {
    private:
        Vector<T> _queueIn;
        Vector<T> _queueOut;

    public:

        void push(const T data) {
            _queueIn.add(data);
        }

        T pop() {
            if (_queueOut.size() == 0) {
                for (int i = _queueIn.size() - 1; i > -1; i--) {
                    _queueOut.add(_queueIn[i]);
                }
                _queueIn.clear();
            }
            return _queueOut.popLast();
        }

        bool hasNext() const {
            return _queueIn.size() != 0 || _queueOut.size() != 0;
        }

        std::string toString() const {
            return "QueueIn: " + _queueIn.toString() + "\nQueueOn: " + _queueOut.toString();
        }
};