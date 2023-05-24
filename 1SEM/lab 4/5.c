#include <stdio.h>
 
int main (void){
    int array[10][12][30];
    int i, k, n, c, year_max, year_min;
    int local_max;
    int max = 0;
    int min = 100;
    for (i=0; i<10; i++)
    {
        year_max = 0;
        year_min = 100;
        for (k=0; k<12; k++)
        {
            for (n=0; n<30; n++){
                printf("% 2d", array[i][k][n] = rand()%100);
                if (array[i][k][n] > year_max){
                    year_max = array[i][k][n];
                } 
                if (array[i][k][n] < year_min){
                    year_min = array[i][k][n];
                }
                
            }
            printf("\n");
        }
        printf("\n");
        printf("year %d maximum: %d \n  year %d minimum: %d \n", i+1, year_max, i+1, year_min);
        if(year_max > max){
            max = year_max;
        }
        if(year_min < min){
            min = year_min;
        }
    }
    printf("10-year maximum: %d \n 10-year minimum: %d", max, min);
    printf("", local_max);
    return 0;
}

