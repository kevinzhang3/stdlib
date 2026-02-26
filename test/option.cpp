#include <cassert>
#include <cstdlib>
#include <string>
#include "Vector/Vector.hpp"
#include "Error/Option.hpp"

struct Data {
    Data(int val1, int val2) : x(val1), y(val2) {};
    int x;
    int y;
};

struct Probe {
    int code; // 1 = lvalue 2 = rvalue 3 = copy ctor 4 = move ctor 

    Probe(int&) {
        code = 1; 
    }

    Probe(int&&) {
        code = 2;
    }

    Probe(const Probe&) {
        code = 3;
    }

    Probe(Probe&&) {
        code = 4;
    }
};

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
    Data d(5, 6);
    Option<Data> o7;
    o7.emplace(d);
    assert(o7->x == 5 && o7->y == 6);

    // forwarding tests
    
    // 1: lvalue
    Option<Probe> o9;
    int x = rand();
    o9.emplace(x);
    assert(o9->code == 1);

    // 2: rvalue 
    Option<Probe> o10;
    o10.emplace(rand());
    assert(o10->code == 2);

    // 3: copy ctor
    Option<Probe> o11;
    Probe probe(rand());
    o11.emplace(probe);
    assert(o11->code == 3);
     
    // 4: move ctor 
    Option<Probe> o12;
    Probe probe2(rand());
    o12.emplace(::move(probe2));
    assert(o12->code == 4);

    
    return 0;
}
