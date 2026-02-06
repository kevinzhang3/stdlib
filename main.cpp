#include <iostream>
#include "Vector/Vector.hpp"

int main (void) {
    
    Vector<int> my_vec;
    my_vec.push_back(6);
    my_vec.push_back(7);

    std::cout << my_vec.at(1) << "\n";

    return 0;
}
