#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>

using namespace std;

template <typename T>
using Iter = typename T::iterator;

template <typename T> /* Iter<T> */
void unique_copy_values(Iter<T> b, Iter<T> e, Iter<T> to) {
    using Type = typename Iter<T>::value_type;
    unordered_map<Type, Type> map;
    for (; b != e; b++) {
        if (!map[*b]) {
            map[*b] = *b;
            *to = *b;
            to++;
        }

    }
}