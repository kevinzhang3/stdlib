#include "../Utilities.hpp"

template<typename T>
class Option {
public:
    bool has_value = false;
    union {
        char dummy; 
        T val;
    };

    Option() : dummy(0), has_value(false) {}

    // const ctor
    Option(const T& t) : val(t), has_value(true) {}

    // rvalue ctor
    Option(T&& t) : has_value(true) {
        new (&val) T(::move(t));
    }

    // copy ctor
    Option(const Option& o) : has_value(o.has_value) {
        if (has_value) {
            new (&val) T(o.val);
        }
    }

    // ::move ctor
    Option(Option&& o) : has_value(o.has_value) {
        if (has_value) {
            new (&val) T(::move(o.val));
            o.reset();
        }
    }

    ~Option() {
        if (has_value) {
            val.~T();
        }
    }

    template<class... Args>
    void emplace(Args&&... args) {
        if (has_value) {
            val.~T();
        }
        new (&val) T(forward(args...));
        has_value = true;
    }

    void reset() {
        if (has_value) {
            has_value = false;
            val.~T();
        }
    }
    
    /* value() overloads */

    T& value() & {
        return val; 
    }

    const T& value() const & {
        return val;
    }

    T&& value() && {
        return ::move(val); 
    }

    const T&& value() const && {
        return ::move(val);
    }  

    /******************/

    bool has() const {
        return has_value; 
    }

    Option& operator= (const T& t) {
        emplace(t); 
        return *this;
    }

    Option& operator= (T&& t) {
        emplace(::move(t));
        return *this;
    }

    // copy assign 
    Option& operator= (Option& o) {
        if (o.has_value) {
            emplace(*o);
        } else {
            reset();
        }
        return *this;
    }

    // ::move assign 
    Option& operator= (Option&& o) {
        if (o.has_value) {
            emplace(::move(*o));
            o.reset();
        } else {
            reset();
        }
        return *this;
    }

    T& operator* () & {
        return val;
    }

    const T& operator* () const & {
        return val; 
    }

    T&& operator* () && {
        return ::move(val);
    }

    const T&& operator* () const && {
        return ::move(val);
    }

    explicit operator bool() const {
        return has_value;
    }

};
