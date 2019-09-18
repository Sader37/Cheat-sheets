template<Forward_iterator Iter>
    requires requires(Iter p, int i) {
        p[i];
        p + i;
}
void advance(Iter p, int n) {
    p += n;
}
// A requires-expression is a predicate that is true
// if the statement in it are valid code and false if they are not.

template<typename S>
concept Sequence = requires(S a) {
    typename Value_type<S>
    typename Iterator_type<S>
        { a.begin() } -> Iterator_type<S>;
        { a.end() } -> Iterator_type<S>;
        requires Same_type<Value_type<S>, Value_type<Iterator_type<S>>>;
        requires Input_iterator<Iterator_type<S>>;
}
// custom concept

template<typename T, typename ... Tail>
void print(T head, Tail ... tail) {
    cout << head << ' ';
    if constexpr(sizeof...(tail) > 0) {
        print(tail...);
    }
}
// variadic template

template<typename ...T>
int sum (T... v) {
    return (v + ... + 0);
}
// Fold Expression

