#include <cassert>
#include <iostream>
#include "Vector/Vector.hpp"
#include "Error/Option.hpp"

int main (void) {

    // basic ctor test 
    Option<int> o1;
    assert(!o1);
    assert(o1.dummy == 0);
    
    Option<int> o2(15);
    assert(*o2 == 15);
    
    // copy ctor
    Option<std::string> o3("hi");
    Option<std::string> o4(o3);
    assert(*o3 == "hi");
    assert(*o4 == "hi");
    assert(*o3 == *o4);

    // move ctor 
    Option<std::string> o5("hello");
    Option<std::string> o6(::move(o5));
    assert(!o5 && o6);
    assert(*o6 == "hello");

    
    // emplace

    std::cout << "All tests completed.\n";

    return 0;
}
