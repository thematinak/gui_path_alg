#pragma once

#include <cstring>
#include <string>
#include <sstream>

template<typename T>
class Vector {
    private:
        int _capacity;
        int _size;
        T* _data;
    public:
        Vector() {
            _capacity = 10;
            _size = 0;
            _data = new T[_capacity];
        }
    
        ~Vector() {
            free(_data);
        }
        
        void add(const T item) {
            if (_capacity > _size + 1) {
                _data[_size] = item;
            } else {
                int newCapacity = _capacity * 2;
                T* newData = new T[newCapacity];

                std::memcpy(newData, _data, _capacity * sizeof(T));
                free(_data);

                _data = newData;
                _capacity = newCapacity;

                _data[_size] = item;
            }
            _size += 1;
        }
        
        T popLast() {
            T res = _data[_size - 1];
            _size -= 1; 
            return res;
        }
        
        std::string toString() const {
            std::ostringstream oss;
            oss << "Vector [";
            for(int i = 0; i < _size; i++) {
                if (i != 0) {
                    oss << ", ";
                }
                oss << _data[i].toString();
            }
            oss << "]";
            return oss.str();
        }
        
        int size() const {
            return _size;
        }
        
        void clear() {
            _size = 0;
        }

        void swap(int idx1, int idx2) {
            T tmp = _data[idx1];
            _data[idx1] = _data[idx2];
            _data[idx2] = tmp;
        }
        
        T& operator[](int index) const {
            return _data[index];
        }
};


    
    

