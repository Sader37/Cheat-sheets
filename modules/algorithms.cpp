#include <algorithms>
#include <string>
#include <iterator>

using namespace std;


int main() {
    unique_copy(begin(o), end(o), /* container iterator */ begin(c) /*, [](T previous, T current){} */); // copies only adjacent unique values
}

void alg_copy_n() {
    string in = "1234567890";
    string out;

    copy_n(begin(in), 4, out);
    // out == "1234"
}