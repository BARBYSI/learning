#include <stdio.h>
#include <math.h>
int main(void){
//number 2
    int r;
    printf("Second program\n acceptable range: r > 0 \n r=\n");
    scanf("%d", &r);
    if (r > 0){
        printf("S = %f\n", expf(((log(r) - cos(pow(r, 2)))/(pow(sin(r), 2) + tan(3 * r)))));
    }
    else printf("Not in acceptable range");
}