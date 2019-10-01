#include <iostream>

using namespace std;

// value type aliasing
template<typename T>
using Value_type = typename T::value_type;


template<typename T>
using Iterator = typename T::iterator;

template<typename C, typename V>
vector<Iterator<C>> find_all (C &c, V v) {
    vector<Iterator<C>> res;
    // ..
    return res;
}

template<typename T, typename ... Args>
unique_ptr<T> make_unique(Args&& ...args) {
    return unique_ptr<T> { new T(forward<Args>(args)...)};
}