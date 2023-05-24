#include <stdio.h>
#include <math.h>

long double E = 0;

long double const_E(void) {
    long double E = pow(10.0, (-4));
    return E;
}

int factorial (int i) {
    int score;
    score = i;

    while (score > 1) {
        i = i * (score - 1);
        score -= 1;
    }
    return i;
}

long double calc(float x) {1
    static int degree = 1;
    static int divider = 1;
    static long double S = 1;
    static long double element = 0;

    if (abs((pow(x, degree)/factorial(divider))) < E){
        return S;
    } else {
        element = (pow(x, degree)/factorial(divider));
        S += element;
        degree += 1;
        divider += 1;
        calc(x);
    }
}

int main(void) {
    float x; 
    printf("input x: \n");
    scanf("%f", &x);
    long double test = exp(x);
    if (x >= 1 && x <= 2) {
        printf("\n%g", calc(x));
        printf("\n%g", test);
    }
    else {
        printf("x out of range");
    }
}