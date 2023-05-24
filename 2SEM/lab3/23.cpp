#include <iostream>
using namespace std;

class Complex {
  private:
    double real;
    double imag;

  public:
    Complex(double r = 0, double i = 0) {
      real = r;
      imag = i;
    }

    Complex operator+(double num) {
      return Complex(real + num, imag);
    }

    void print() {
      cout << real << " + " << imag << "i" << endl;
    }

    friend Complex div(Complex &a, Complex &b);
    friend Complex add(Complex a, double b);
    friend Complex add(double a, Complex b);
};

Complex div(Complex &a, Complex &b) {
  double den = b.real * b.real + b.imag * b.imag;
  Complex res((a.real * b.real + a.imag * b.imag) / den,
              (a.imag * b.real - a.real * b.imag) / den);
  return res;
}

Complex add(Complex a, double b) {
  return a + b;
}

Complex add(double a, Complex b) {
  return b + a;
}

int main() {
  double real_part, imag_part, user_num;

  cout << "real part a: \n";
  cin >> real_part;

  cout << "imaginary part a: \n";
  cin >> imag_part;

  Complex a(real_part, imag_part);

  cout << "real part b: \n";
  cin >> real_part;

  cout << "imaginary part b: \n";
  cin >> imag_part;

  Complex b(real_part, imag_part);

  Complex c = div(a, b);

  cout << "a = ";
  a.print();

  cout << "b = ";
  b.print();

  cout << "c = ";
  c.print();

  cout << "double type number: \n";
  cin >> user_num;

  Complex e = add(a, user_num);
  Complex f = add(user_num, a);

  e.print();
  f.print();

  return 0;
}

