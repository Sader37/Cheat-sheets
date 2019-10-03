#include <iterator>

template <typename T>
class Vector2 {
public:
    using value_type = T;
    template <typename Iter>
    Vector2(Iter a_, Iter b_) {
    }
};


template<typename Iter>
Vector2(Iter, Iter) -> Vector2<typename Iter::value_type>;

int main() {
    vector<int> vd = { /* */};
    Vector2 a(vd.begin(), vd.end());
    return 0;
}