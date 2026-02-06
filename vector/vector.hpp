template <typename T> class vector {
    private:
        T* container;
        int size;
        int index; 
    public:
        /* ITERATOR CLASS */
        class iterator {
            private:
                int* index;
        };

        /* VECTOR DEFINITIONS */

        vector(T type) {
            this->size = 0;
        }

        ~vector() {
            delete this->container;
        }

        iterator begin() {
            return this->container;
        }

        iterator end() {
            return this->container + this->size;
        }


        
        
};
