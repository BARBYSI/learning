#include <stdio.h>
#include <math.h>
int main(void) {
    //number 1
    int m, n;
    int z;
    printf("input m: ");
    scanf("%d", &m);
    printf("input n: ");
    scanf("%d", &n);
    if (n < 0 && m > 0){
        z = m + pow(n, 2);
        printf("z = %d", z);
    }
    else if (m <= 0 && n < 0) {
        z = m + 2*n;
        printf("z = %d", z);
    }
    else {
        z = m + 1;
        printf("z = %d\n", z);    
    }
    return 0;
}