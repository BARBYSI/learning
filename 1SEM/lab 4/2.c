#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *block;
    int n;

    printf("Size of array = ");
    scanf("%d", &n);

    block = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        block[i] = (rand()%10);
        printf("%d ", block[i]);
    }

    for (int i = 0; i<n; i++){
        for(int x = i + 1; x < n; x++){
            if (block[i] == block[x]){
                for(int j = x; j < n - 1; j++){
                    block[j] = block[j+1];
                }
                block[n] = 0;
                --n;
            }
        }
    }
    printf("The unique numbers array: \n");
    for (int i = 0; i < n; i++){
        printf("%d ", block[i]);
    }
}

    
