template<typename T>
T add(T val) {
    return val;
}

template<typename T, typename... Args>
T add(T first, Args... args) {
    return first + add(args...);
};
