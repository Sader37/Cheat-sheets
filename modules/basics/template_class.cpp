// Template example
template <typename T>
class Pair {
    T first, second;
public:
    Pair(T a, T b);
    T bigger();
};

template <typename T>
Pair<T>::Pair(T a, T b): first(a), second(b) {}

template <typename T>
T Pair<T>::bigger() {
    if (first > second)
        return first;
    return second;
}
