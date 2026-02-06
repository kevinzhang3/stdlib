template <typename T> 

class Vector {
    private:
        T* container;
        int index = -1; 
        int size = 0;
    public:
        /* ITERATOR CLASS */
        class Iterator {
            private:
                T* index;
        };

        /* VECTOR DEFINITIONS */

        Vector(T type) {
        }

        ~Vector() {
            delete container;
        }

        Iterator begin() {
            return container;
        }

        Iterator end() {
            return container + size;
        }

        void push_back(const T& val) {
            if (size == 0 || index == size) {
                size += 32;
                index++;
                container = new T[size];
            } else {
                container[index] = val;
                index++;
            }
        }




        
        
};
