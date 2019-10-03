#include <memory>
#include <thread>
#include <mutex>
#include <chrono>



using namespace std;

// unique_ptr
template <typename N>
struct Number {
public:
    Number(N num_): num(num_) {

    }
private:
    N num;
};


void uptr() {
    Number<int> i(4);
    unique_ptr<Number<int>> upr = make_unique<Number<int>>(4);
    auto p = move(upr);
    auto ncopy = p.get();
    assert(upr != 0); // fails
    assert(p != 0);
    assert(ncopy != 0);

}

// shared_ptr

struct Base
{
    Base() { cout << "  Base::Base()\n"; }
    // Note: non-virtual destructor is OK here
    ~Base() { cout << "  Base::~Base()\n"; }
};

struct Derived: public Base
{
    Derived() { cout << "  Derived::Derived()\n"; }
    ~Derived() { cout << "  Derived::~Derived()\n"; }
};

void thr(shared_ptr<Base> p)
{
    this_thread::sleep_for(chrono::seconds(1));
    shared_ptr<Base> lp = p; // thread-safe, even though the
    // shared use_count is incremented
    {
        static mutex io_mutex;
        lock_guard<mutex> lk(io_mutex);
        cout << "local pointer in a thread:\n"
             << "  lp.get() = " << lp.get()
             << ", lp.use_count() = " << lp.use_count() << '\n';
    }
}

void shared_ptr() {
    shared_ptr<Base> p = make_shared<Derived>(/* arguments for Ex constructor */);

    cout << "Created a shared Derived (as a pointer to Base)\n"
         << "  p.get() = " << p.get()
         << ", p.use_count() = " << p.use_count() << '\n';
    thread t1(thr, p), t2(thr, p), t3(thr, p);
    p.reset(); // release ownership from main
    cout << "Shared ownership between 3 threads and released\n"
         << "ownership from main:\n"
         << "  p.get() = " << p.get()
         << ", p.use_count() = " << p.use_count() << '\n';
    t1.join(); t2.join(); t3.join();
    cout << "All threads completed, the last one deleted Derived\n";
//    Base::Base()
//    Derived::Derived()
//    Created a shared Derived (as a pointer to Base)
//    p.get() = 0x761950, p.use_count() = 1
//    Shared ownership between 3 threads and released
//    ownership from main:
//    p.get() = 0, p.use_count() = 0
//    local pointer in a thread:
//    lp.get() = 0x761950, lp.use_count() = 6
//    local pointer in a thread:
//    lp.get() = 0x761950, lp.use_count() = 4
//    local pointer in a thread:
//    lp.get() = 0x761950, lp.use_count() = 2
//    Derived::~Derived()
//    Base::~Base()
//    All threads completed, the last one deleted Derived
}