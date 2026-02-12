#include <cassert>
#include <iostream>
#include "Vector/Vector.hpp"
#include "Error/Option.hpp"

int main (void) {
    
    std::cout << "<Option.hpp>\n";
    
    Option<int> o1;
    assert(!o1);

    Option<const char *> o2 = "hello";
    assert(o2 && *o2);

    // move into Option 
    std::string str = "hey";
    Option<std::string> o3 = ::move(str);
    assert(str.size() == 0);

    // copy constructor 
    auto o4 = o3;
    assert(*o4 == "hey" && o3.value().size());

    return 0;
}
