#include <stdio.h>
#include <math.h>

long double E = 0;

long double const_E(void) {
    long double E = pow(10.0, (-5));
    return E;
}


long double calc(float x) {
    static int degree = 1;
    static int divider = 1;
    static long double S = 2;
    static long double element = 0;

    if ((abs((1 / divider*pow(x, degree)))) < E) {
        return (S * 2);
    } else {
        element = (1 / divider*pow(x, degree));
        S += element;
        degree += 2;
        divider += 2;
        calc(x);
    }
}

int main(void) {
    float x; 
    printf("input x: \n");
    scanf("%f", &x);
    long double test = log10(x + 1 / x - 1);
    if (abs(x) > 1) {
        printf("\n%g", calc(x));
        printf("\n%g", test);
    }
    else {
        printf("x out of range");
    }
}