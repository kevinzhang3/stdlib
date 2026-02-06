#include <iostream>
#include "Vector/Vector.hpp"

int main (void) {
    
    Vector<int> my_vec;
    for (int i{}; i < 128; i++) {
        my_vec.push_back(i);
        std::cout << my_vec[i] << "\n";
    }

    return 0;
}
