#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main()
{
    int n = 7,k;
    int i,j;
    int *matrix, temp;
    
    
    printf("k = ");
    scanf("%d", &k);
    
    if(k < 0 || k > n-1)
        return 1;
    
    matrix = malloc(n*n*(sizeof *matrix));
 

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            matrix[i*n + j] = rand()%100;
            printf("%3d ", matrix[i*n + j]);
        }
        printf("\n");
    }
    
    for(i = 0; i < n; i++)
    {
        temp = matrix[i*n + k];
        matrix[i*n + k] = matrix[k*n + i];
        matrix[k*n + i] = temp;
    }
    
    printf("New matrix:\n");
    
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%3d ", matrix[i*n + j]);
        printf("\n");
    }       
    
    free(matrix);
    
    return 0;
}
