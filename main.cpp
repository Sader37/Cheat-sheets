#include <iostream>
#include <chrono>
#include "hello.hpp"
#include <xdevapi.h>

using ::std::move;
using ::std::forward;
using ::std::cout;
using ::std::endl;
using ::std::cerr;
//using namespace mysqlx;

//template <typename H, typename ...T>
//void fc(H h , T...) {
//    cout << h << endl;
//    fc(T...);
//
//}

//void accept_connection(Session *sess) {
//    cout << "Session accepted, creating collection..." << endl;
//    Schema sch = sess->getSchema("test");
//    Collection coll = sch.createCollection("c1", true);
//}

int main() {
    hello::say_hello();
    void *ptr = malloc(sizeof(uint32_t));
    //    try {
//        const char *url = "mysqlx://root@127.0.0.1";
//        cout << "Creating session on " << url
//             << " ..." << endl;
//        Session sess(url);
//
//        cout << "Done!" << endl;
//        return 0;
//    } catch (...) {
//        cerr << "Unexpected error.";
//    }
//
    return 0;
}