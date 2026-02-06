#include "../Allocator.hpp"
#include <iostream>

template <class T, class Alloc = Allocator<T>> 

class Vector {
    /* ITERATOR CLASS */

    class Iterator {
        T* ptr;

    public:
        Iterator(T* p) : ptr(p) {}

        Iterator operator+(int val) {
            return Iterator(ptr + val);
        }

        Iterator& operator+=(int val) {
            ptr += val;
            return *this;
        }

        //pre
        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        //post 
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++ptr;
            return tmp;
        }

        T* operator->() const {
            return ptr;
        }

        T& operator*() const {
            return *ptr;
        }

    };

    /* VECTOR DEFINITIONS */
    
    T* container;
    Alloc alloc;
    int size;
    int capacity;
    Iterator it;

    void init() {
        try {
            container = alloc.allocate(capacity);
        }
        catch (int) {
            std::cout << "max reached";
        }
        it = Iterator(container);
        for (int i{}; i < capacity; i++) {
            alloc.construct(container + i);
        }
    }

public:

    Vector() : container(nullptr), size(0), capacity(0), it(nullptr) {}

    ~Vector() {
        alloc.deallocate(container);
    }

    Iterator begin() {
        return Iterator(container);
    }

    Iterator end() {
        return Iterator(container + size);
    }

    void push_back(T val) {
        if (capacity == 0) {
            capacity += 32;
            init();
        }
        *it++ = val;
        size++;
    }

    void empty() {
        it = this->begin();

        for (int i{}; i < capacity; i++) {
            alloc.destroy(container + i);
        }

        alloc.deallocate(container);
        size = 0;
        capacity = 0;
    }

    const T& at(int idx) {
        return (idx < size) ? container[idx] : throw -1;
    }

}; 
