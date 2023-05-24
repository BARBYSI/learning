#include <stdio.h>
#include <math.h>
#include<stdlib.h>

int main(void) {
    int n = 10, i; 
    double x, m = 0.2, a, b, p, h;
    printf("input b: \n");
    scanf("%lf", &b);
    h =( 2 * b ) / 10;
    x =- b;
    p = x;
    i = 0;
    while (x <= b){
        p = x;
        printf("x = %.1lf  ", x);
        m = 0.2;
        for(i = 1; i < n; i++){
            p *= (x + m);
            m+= 0.2; 
        }

        printf("p = %lf\n", p);
        x += h;
    }

    return 0;
}