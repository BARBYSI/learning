#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include "bingen.c"

int write(char * filename, char message[], int n){
    FILE * fp;
    if((fp= fopen(filename, "w"))==NULL){
        perror("Error occured while opening file");
        return 1;
    }
     
    // посимвольно записываем в файл
    for(int i=0; i<n; i++){
        putc(message[i], fp);
    }
     
    fclose(fp);
    return 0;
};

int read(char * filename){
    FILE * fp;
    char c;
    if((fp = fopen(filename, "r")) == NULL){
        perror("Error occured while opening file");
        return 1;
    }
    // после записи считываем посимвольно из файла
    while((c = getc(fp)) != EOF){
        printf("%c", c);
    }
    printf("\n");
    fclose(fp);
    return 0;
};

// int pnumbers(char * filename, char array[], int n){
//     FILE * fp;
//     char c;
//     if((fp= fopen(filename, "r"))==NULL){
//         perror("Error occured while opening file");
//         return 1;
//     }
//     while((c = getc(fp) != EOF)){
//         if(c - '0' >= 0){
//             n++;
//             array[n-1] = c;
//         }
//     }
//     for(int i = 0; i < n; i++){
//         printf("%c", array[i]);
//     }
//     fclose(fp);
// }

int main(){
    char* p;
    char buf[256];
    int n, k = 0, removed;
    char * numbers = "numbers.bin";
    printf("input the amount of numbers: ");
    scanf("%d", &n);
    char* positive_numbers[n];
    binary(n);
    read(numbers);
    // p = fgets(buf, sizeof(buf), fp)
    while((p = fgets(buf, sizeof(buf), fopen("numbers.bin", "rb"))) != NULL){
        FILE * fp = fopen("numbers.bin", "w+b");
        char* pch = strtok(p, " \n");
        while(pch != NULL){
            if(pch[0] != '-'){
                k++;
                positive_numbers[k] = pch;
                fputs(pch, fp);
                fputs(" ", fp);
                printf("%s", pch);
            }
        pch = strtok(NULL, " ,.");
        }
        p = NULL;
        removed = n - k;
        fputs("   ", fp);
        fputs(itoa(removed, buf, 10), fp);
    }
    read(numbers);
}