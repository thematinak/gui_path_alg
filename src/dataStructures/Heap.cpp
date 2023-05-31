#pragma once

#include <string>
#include <iostream>
#include "Vector.cpp"

template<typename T>
class HeapNode {
    public:
        int _priority;
        T _data;

        HeapNode() {
        }

        HeapNode(int priority, T data) {
            _priority = priority;
            _data = data;
        }

        std::string toString() const {
            std::ostringstream oss;
            oss << "HeapNode [" << _priority << ", data: " << _data.toString() << "]";
            return oss.str();
        }
};

template<typename T>
class Heap {
    private:
        Vector<HeapNode<T>> _data;
    public:

        void push(int priority, T data) {
            _data.add(HeapNode<T>(priority, data));
            bubleUp(_data.size() - 1);
        }

        T pop() {
            T res = _data[0]._data;
            _data.swap(0, _data.size() - 1);
            _data.popLast();
            bubleDown(0);
            return res;
        }

        bool hasNext() const {
            return _data.size() != 0;
        }

        void bubleUp(int index) {
            if (index == 0) {
                return;
            }
            int parent = parentIndex(index);
            if (_data[index]._priority < _data[parent]._priority) {
                _data.swap(index, parent);
                bubleUp(parent);
            }
        }

        void bubleDown(int index) {
            int left = leftChild(index);
            int right = rightChild(index);

            if (left < _data.size()) {
                int smaller = left;
                if (right < _data.size() && _data[right]._priority < _data[left]._priority) {
                    smaller = right;
                }
                if (_data[smaller]._priority < _data[index]._priority) {
                    _data.swap(smaller, index);
                    bubleDown(smaller);
                }
            }

        }

        int leftChild(int index) const {
            return (index * 2) + 1;
        }

        int rightChild(int index) const {
            return (index * 2) + 2;
        }

        int parentIndex(int index) const {
            return (index - 1) / 2;
        }

        std::string toString() const {
            std::ostringstream oss;
            oss << "Heap: size " << _data.size() << '\n';
            int inRow = 0;
            int width = 1;
            for(int i = 0; i < _data.size(); i++) {
                if (inRow == width) {
                    oss << '\n';
                    inRow = 0;
                    width *= 2;
                }
                oss << _data[i].toString() << " ";
                inRow++;
            }
            return oss.str();
        }

        
};