#include <iostream>
#include <cmath>

using namespace std;

class complex {
private:
    double re, im;
public:
    complex() : re(0), im(0) {}
    complex(double r, double i) : re(r), im(i) {}

    double real() const { return re; }
    double imag() const { return im; }
    double abs() const { return sqrt(re*re + im*im); }
    double arg() const { return atan2(im, re); }
    complex conj() const { return complex(re, -im); }

    friend complex operator+(const complex& a, const complex& b);
    friend complex operator-(const complex& a, const complex& b);
    friend complex operator*(const complex& a, const complex& b);
    friend complex operator/(const complex& a, const complex& b);
};

complex operator+(const complex& a, const complex& b) {
    return complex(a.re + b.re, a.im + b.im);
}

complex operator-(const complex& a, const complex& b) {
    return complex(a.re - b.re, a.im - b.im);
}

complex operator*(const complex& a, const complex& b) {
    double r = a.re*b.re - a.im*b.im;
    double i = a.re*b.im + a.im*b.re;
    return complex(r, i);
}

complex operator/(const complex& a, const complex& b) {
    double d = b.re*b.re + b.im*b.im;
    double r = (a.re*b.re + a.im*b.im) / d;
    double i = (a.im*b.re - a.re*b.im) / d;
    return complex(r, i);
}

int main() {
    complex a(4, 7.3);
    complex b(4, 2);

    complex c = a + b;
    complex d = a - b;
    complex e = a * b;
    complex f = a / b;

    cout << "a + b = " << c.real() << " + " << c.imag() << "i" << endl;
    cout << "a - b = " << d.real() << " + " << d.imag() << "i" << endl;
    cout << "a * b = " << e.real() << " + " << e.imag() << "i" << endl;
    cout << "a / b = " << f.real() << " + " << f.imag() << "i" << endl;

    return 0;
}
