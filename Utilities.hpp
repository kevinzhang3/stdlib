#pragma once

template <typename T>
constexpr bool is_lvalue(T&) { 
    return true;  // lvalue binds to T&
}

template <typename T>
constexpr bool is_lvalue(T&&) { 
    return false; // rvalue binds to T&&
}

template<class T>
struct remove_reference { typedef T type; };

template<class T>
struct remove_reference<T&> { typedef T type; };

template<class T>
struct remove_reference<T&&> { typedef T type; };

template<class T>
typename remove_reference<T>::type&& move(T&& t) noexcept {
    return static_cast<typename remove_reference<T>::type&&>(t);
}

template <class T>
inline T&& forward(typename remove_reference<T>::type& t) noexcept {
    return static_cast<T&&>(t);
}

template <class T>
inline T&& forward(typename remove_reference<T>::type&& t) noexcept {
    static_assert(!is_lvalue(t), "Can not forward lvalue as rvalue");

    return static_cast<T&&>(t);
}
