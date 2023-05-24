#include <stdio.h>
#include <math.h>
int main(void) {
    float a, b;
    printf("A = ");
    scanf("%f", &a);
    printf("B =  ");
    scanf("%f", &b);
    if (a > 1 && b > 1 && a > b) {
        int m = 1;
        for (m = 1; ; m++){
            if (pow(b, m) > (m * a)) {
                printf("min m = %d", m);
                break;
            }
        }
    } 
}