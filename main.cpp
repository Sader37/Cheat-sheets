#include <iostream>
#include <chrono>
#include <unistd.h>
#include <cmath>
#include <iomanip>
#include <type_traits>

struct D{};

using namespace std;
int main() {
    bool a_ = is_class<D>();
    bool a = is_arithmetic<int>();
    cout << a_ << endl;
    cout << a << endl;
//    bool a = is_arithmetic<int>(1);
    return 0;
}