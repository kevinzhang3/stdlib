#include "../Allocator.hpp"

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

    void init() {
        container = alloc.allocate(capacity);
    }

    void grow() {
        int new_capacity = 2;
        T* tmp = alloc.allocate(capacity);
        for (int i{}; i < capacity; i++) {
            alloc.construct(tmp + i);
        }

        for (int i{}; i < capacity; i++) {
            alloc.destroy(container + i);
        }

        alloc.deallocate(container);
        container = tmp;
        capacity = new_capacity;
    }

public:

    // default constructor
    Vector() : container(nullptr), size(0), capacity(0) {}

    // std style inits: vector<int> v(size)
    Vector(int sz) : container(nullptr), capacity(0) {
        size = sz;
    }

    // vector<int> v(size, val)
    Vector(int sz, T val) {
        size = sz;
        capacity = sz;
        
        container = alloc.allocate(capacity);
        for (int i{}; i < capacity; i++) {
            alloc.construct(container + i);
        }
    }

    ~Vector() {
        alloc.deallocate(container);
    }

    T& operator[](int idx) {
        return container[idx];
    }

    Iterator begin() {
        return Iterator(container);
    }

    Iterator end() {
        return Iterator(container + size);
    }

    void push_back(const T& val) {
        if (capacity == 0) {
            capacity += 32;
            init();
        }
        alloc.construct(container + size++, val);
    }

    void push_back(T&& val) {
        if (capacity == 0) {
            capacity += 32;
            init();
        }
        alloc.construct(container + size++, val);
    }


    void empty() {

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
