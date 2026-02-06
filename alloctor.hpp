template <class T>
class Allocator {
    T value_type;
    T* pointer;
    T& reference;
    const T* const_pointer;
    const T& const_reference;
    const int max_size = 4096;

    void* allocate(unsigned int size) {
        if (size > max_size) {
            throw -1;
        }
        return operator new(sizeof(value_type) * size);
    }
    
    void deallocate(T* ptr) {
        delete ptr;    
    }

    T* construct(void* ptr) {
        return static_cast<T>(ptr);
    }

    int address(const T* ptr) {
        return static_cast<int>(ptr);
    }

    Allocator() {}

};

