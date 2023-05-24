#include <stdio.h>
#include <math.h>
int main(void) {
    int sum;
    for (int i = 10; i < 100; i++) {
        sum = i/10 + i%10;
        if((sum + sum * sum) == i) {
            printf("sum = %d, i = %d\n", sum, i);
        }
    }
}