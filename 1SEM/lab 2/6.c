#include <stdio.h>
#include <math.h>
int main(void) {
    int n; 
    printf("input n: ");
    scanf("%d", &n);
    int high = n;
    while(high / 10 != 0) {
        high = high / 10;
    }
    int low = n % 10;
    printf("%d, %d\n", high, low);
    if (high > low) {
        printf("%d > %d", high, low);
    }
    else if (high < low) {
        printf("%d < %d", high, low);
    }
    else {
        printf("%d = %d", high, low);
    }


}