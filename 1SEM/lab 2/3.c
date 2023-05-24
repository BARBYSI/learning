#include <stdio.h>
#include <math.h>

int main (void){
    //number 3
    int a, b;
    printf("input a: ");
    scanf("%d", &a);
    printf("input b: ");
    scanf("%d", &b);
    if ((a % 2) == 0 && (b % 2) == 0){
        if (a > b) {
            a = (a / 2);
            printf("a = %d, b = %d", a, b);
        }
        else {
            b = b / 2;
            printf("a = %d, b = %d", a, b);
        } 

    }
    else if ((a % 2) != 0 && (b % 2) != 0) {
        a *= 2;
        b *= 2;
        printf("a = %d, b = %d", a, b);
    }
    else {
        if (a % 2 == 0) {
            b += 1; 
            printf("a = %d, b = %d", a, b);
        }
        else {
            a +=1;
            printf("a = %d, b = %d", a, b);
        }
    }
}