#include <string>

struct Greater_than {
    int val;
    Greater_than(int val_): val(val_) {}
    bool operator()(const pair<string, int> &p) const {
        return get<int>(p) > val;
    }
};