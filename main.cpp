#include <iostream>
#include "Vector/Vector.hpp"

int main (void) {
    
    Vector<int> my_vec;
    my_vec.push_back(5);

    std::cout << my_vec.at(0) << "\n";

    return 0;
}
