#include <iostream>
using namespace std;

// Friend function example for class
    class FriendEx {
    private:
        int val = 0;
        friend ostream& operator<<(ostream& out, const FriendEx& o);
    };
    ostream& operator<<(ostream& out, const FriendEx& o) {
        return out << o.val;
    }
    //MyClass c;
    //cout << c;

    // Perhaps the most common use case for friend functions is overloading << and >> for I/O

// Constructors. Abstract parts of interface. Polymorphic logic using pointers.
    class Monster {
    protected:
        int AP = 0;
    public:
        explicit Monster(int ap): AP(ap) {};
        virtual void attack() = 0;
        void set_AP(int am);
    };


    void Monster::set_AP(int am) {
        AP = am;
    };

    class Ninja : public Monster {
    public:
        explicit Ninja(int ap): Monster(ap) {};
        void attack() {
            cout << "Ninja is attacking with Attack Power of " << AP << "." << endl;
        }
    };

    class Slime : public Monster {
    public:
        explicit Slime(int ap): Monster(ap) {};
        void attack() {
            cout << "Slime is attacking with Attack Power of " << AP << "." << endl;
        }
    };
    //Ninja a(12);
    //Slime b(4);
    //Monster* ptr1 = &a;
    //Monster* ptr2 = &b;
    //ptr1->attack(); // or a.attack();
    //ptr2->attack(); // or b.attack();

// Template example
    template <typename T>
    class Pair {
        T first, second;
    public:
        Pair(T a, T b);
        T bigger();
    };

    template <typename T>
    Pair<T>::Pair(T a, T b): first(a), second(b) {}

    template <typename T>
    T Pair<T>::bigger() {
        if (first > second)
            return first;
        return second;
    }

// Error handling
    // try {} catch (...) {} // catches any error
    // try {} catch (const std::exception& e) {}

// fstream
    // ofstream|ifstream|fstream file;
    // ios::app - append to end of file,
    // ios::ate - go to end of file on opening,
    // ios::binary - open file in binary mode,
    // ios::in - open file for reading only,
    // ios::out - open file fro writing only,
    // ios::trunc - delete the contents of the file if it exists
    // file.open("file.ext", ios::out | ios::trunc); `|` stands for binary AND
        // ofstream
        // ofstream hw_txt;
        // hw_txt.open("hello_world.txt", ios::app | ios::out);
        // hw_txt << "Hello world!";
        // hw_txt.close();
        // ifstream
        // ifstream hw_txt;
        //  string get_file_contents(ifstream &file, const string fn) {
        //      file.open(fn);
        //      string contents, tmpl;
        //          while (getline(file, tmpl)) {
        //              contents += tmpl + "\n";
        //          }
        //      file.close();
        //      return contents;
        //  }

// Enum
    enum class Color {
        red, blue, green
    };
    enum class TrafficLight {
        red, yellow, green
    };
    // Color red = Color::red;
    // TrafficLight light = TrafficLight::red;

// Namespaces
    namespace MyCode {
        class Complex {
        public:
            Complex(int);
        };

        Complex sqrt(Complex);

        int main();
    }
    // MyCode::main() {} - implementation

// Scructured binding
   // auto [n, v] = read_entry(is);

// Abstract interfaces
    class Shape {
    public:
        virtual Point center() center = 0;
        virtual void move(Point to) = 0;
        virtual void draw() const = 0;
        virtual void rotate(int angle) const = 0;
        virtual ~Shape();
    };

// Explicit stands for no implicit conversion of types in constructor.
    class Vector {
    public:
        explicit Vector(int s);
    };

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

// override keyword in inherited methods omits their implementation