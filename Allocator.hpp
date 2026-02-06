#include <utility>

template <class T>
class Allocator {
    const int max_size = 4096;

    public:

        Allocator() {}
        
        T* allocate(unsigned int size) {
            if (size > max_size) {
                throw -1;
            }
            return static_cast<T*>(::operator new(sizeof(T) * size));
        }

        void deallocate(T* ptr) {
            operator delete(ptr);    
        }

        template <class... Args>
        void construct(T* ptr, Args&&... args) {
            new (ptr) T(std::forward<Args>(args)...);
        }
        
        void destroy(T* ptr) {
            ptr->~T();
        }

        T* address(T& x) {
            return &x;
        }

        const T* address(const T& x) {
            return &x;
        }

};

