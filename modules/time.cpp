#include <chrono>

using namespace std::chrono;

auto t = high_resolution_clock::now();
//    do_work();
auto t2 = high_resolution_clock::now();
cout << duration_cast<milliseconds>(t2-t).count() << " ms\n";