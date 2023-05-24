#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f1(double x){
    double F = log(pow(x,2) + 1);
    return F;
}

double f2(double x){
    double F = (pow(x, 2) - 2*x - 1);
    return F;
}

double integral(int a, int b, int n, double (*F)(double)){
    float h, S, x;
    h = (b - a) * 1.0 / n;
    S = 0;
    for(int i = 0; i < n; i++){
        x = a + i *h;
        S = S + F(x);
    }
    S = h*S;
    return S;
}

void main(){
    int n;
    float y;
    y = integral(1, 4, 20, f1);
    printf("%f\n", y);
    y = integral(-2, 2, 20, f2);
    printf("%f\n", y);
}