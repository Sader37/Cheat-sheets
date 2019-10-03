#include <iostream>
#include <cmath>

using namespace std;

void any_radical_case();

void no_radical_case();

void one_linear_radical_case(double, double);

void one_square_radical_case(double, double);

void two_square_radicals_case(double, double, double disc);

void call_equation();

void sqrt_equation(double a, double b, double c);


void call_equation() {
    double a, b, c;
    cin >> a >> b >> c;
    if (a != 0)
        return sqrt_equation(a, b, c);
    if (b == 0 && c != 0)
        return no_radical_case();
    if (a == 0 && b == 0 && c == 0)
        return any_radical_case();
    return one_linear_radical_case(b, c);
}

void any_radical_case() {
    cout << "Корнем уравления будет являться любое число\n";
}

void no_radical_case() {
    cout << "Уравнение не имеет действительных корней\n";
}

void one_linear_radical_case(double a, double b) {
    double x = -b / a;
    cout << "Корень уравнения x = " << x << "\n";
}

void one_square_radical_case(double a, double b) {
    double x = -b / 2 * a;
    cout << "Корень уравнения: x = " << x << "\n";
}

void two_square_radicals_case(double a, double b, double disc) {
    double x1 = (-b - sqrt(disc)) / 2 * a;
    double x2 = (-b + sqrt(disc)) / 2 * a;
    cout << "Корни уравнения: x1 = " << x1 << " и " << "x2 = " << x2 << "\n";
}

void sqrt_equation(double a, double b, double c) {
    double disc = b * b - 4 * a * c;
    if (disc < 0)
        return no_radical_case();
    else if (disc == 0)
        return one_square_radical_case(a, b);
    return two_square_radicals_case(a, b, disc);
}

// input : a = 0, b = 0, c = 1
// output: Уравнение не имеет действительных корней
// input : a = 1, b = 0, c = -4
// output: Корни — x1 = -2, x2 = 2
// input: a = 0, b = 1, c = 4
// output Корень — x = -4
// input a = 0, b = 0, c = 0
// output Решением уравнения является любое значение
