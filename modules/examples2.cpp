// Essential operations:
#include <bitset>
#include <iostream>
using namespace std;

class Vector {
private:
    double *elem;
    int sz;
public:
    Vector(int);

    ~Vector();

    Vector(const Vector &);

    Vector(Vector &&);

    Vector &operator=(const Vector &);

    Vector &operator=(Vector&&);

    double &operator[](int);

    const double &operator[](int i) const;

    int size() const;
};

Vector::Vector(int s) : elem(new double[s]), sz(s) {}

Vector::~Vector() { delete[] elem; }

Vector::Vector(const Vector &v) : elem(new double[v.sz]), sz(v.sz) {
    for (int i = 0; i < v.sz; i++) {
        elem[i] = v.elem[i];
    }
}
Vector::Vector(Vector&& v): elem(v.elem), sz(v.sz) {
    v.elem = nullptr;
    v.sz = 0;
}
double &Vector::operator[](int i) {
    return elem[i];
}

const double &Vector::operator[](int i) const {
    return elem[i];
}

Vector &Vector::operator=(const Vector &v) {
    double *p = new double[v.sz];
    for (int i = 0; i < v.sz; i++) {
        p[i] = v.elem[i];
    }
    delete[] elem;
    elem = p;
    sz = v.sz;
    return *this;
}
Vector& Vector::operator=(Vector &&v) {
    delete[] elem;
    elem = v.elem;
    sz = v.sz;
    v.elem = nullptr;
    v.sz = 0;
    return *this;
}
int Vector::size() const {
    return sz;
}
//    Vector a(5);
//    Vector b(7);
//    Vector c(11);
//    Vector d(c);
//    Vector e(move(c));
//    e = move(d);
//    b = a;
//    cout << b.size() << "\n"; // 5
//    cout << d.size() << "\n"; // 0
//    cout << e.size() << "\n"; // 11
//    cout << c.size() << "\n"; // 0

void print_bits(int i) {
    bitset<8*sizeof(int)> bs = i;
    cout << bs.to_string() << endl;
}

