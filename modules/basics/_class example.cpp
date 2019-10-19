#include <iostream>
using namespace std;

// Class
    class Vector {
    private:
        double *elem;
        int sz;
    public:
        Vector (int s);
        ~Vector() {
            delete[] elem;
        }
        Vector (const Vector &a) {}
        Vector& operator=(const Vector& a);
        double& operator[](int i);
        const double& operator[](int i) const;
        int size() const;
    };
