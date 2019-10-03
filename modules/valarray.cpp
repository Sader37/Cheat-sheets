#include <valarray>

using namespace std;

// In additions to arithmetic operations,
// valarray offers stride access to help implement multidimensional computations.
valarray<double> f(valarray<double>& a1, valarray<double>& a2) {
    valarray<double> a = a1*3.14+a2/a1;
    return a;
}