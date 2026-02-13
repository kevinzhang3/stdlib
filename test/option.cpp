#include <cassert>
#include <iostream>
#include "Vector/Vector.hpp"
#include "Error/Option.hpp"

int main (void) {

    // basic ctor test 
    Option<int> o1;
    assert(!o1);
    assert(o1.dummy == 0);
    
    // const ctor 
    const int x = 5;
    Option<const int> o2(x);
    assert(o2.has_value && std::is_const<decltype(*o2)>::value);


    std::cout << "All tests completed.\n";

    return 0;
}
