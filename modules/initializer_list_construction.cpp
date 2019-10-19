#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

template <class T>
struct S {
    vector<T> v;
    S(initializer_list<T> l) : v(l) {
        cout << "constructed with a " << l.size() << "-element list\n";
    }
    void append(initializer_list<T> l) {
        v.insert(v.end(), l.begin(), l.end());
    }
    pair<const T*, size_t> c_arr() const {
        return {&v[0], v.size()};  // copy list-initialization in return statement
        // this is NOT a use of initializer_list
    }
};

template <typename T>
void templated_fn(T) {}

int main()
{
    S<int> s = {1, 2, 3, 4, 5}; // copy list-initialization
    s.append({6, 7, 8});      // list-initialization in function call

    cout << "The vector size is now " << s.c_arr().second << " ints:\n";

    for (auto n : s.v)
        cout << n << ' ';
    cout << '\n';

    cout << "Range-for over brace-init-list: \n";

    for (int x : {-1, -2, -3}) // the rule for auto makes this ranged-for work
        cout << x << ' ';
    cout << '\n';

    auto al = {10, 11, 12};   // special rule for auto

    cout << "The list bound to auto has size() = " << al.size() << '\n';

//    templated_fn({1, 2, 3}); // compiler error! "{1, 2, 3}" is not an expression,
    // it has no type, and so T cannot be deduced
    templated_fn<initializer_list<int>>({1, 2, 3}); // OK
    templated_fn<vector<int>>({1, 2, 3});           // also OK
}