#pragma once

#include <string>
#include "Vector.cpp"

template<typename T>
class Stack {
    private:
        Vector<T> _stack;
    public:
    Stack() {}

    ~Stack() {}

    void push(const T item) {
        _stack.add(item);
    }

    T pop() {
        return _stack.popLast();
    }

    bool hasNext() const {
        return _stack.size() != 0;
    }

    int size() const {
        return _stack.size();
    }

    void clean() {
        _stack.clean();
    }

    std::string toString() const {
        return "Stack: " + _stack.toString();
    }
};