#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

int main(void){
    char* p, cc[256], *word;
    int len, maxlen = 0;
    FILE * fin = fopen("input.txt", "r");
    FILE * fout = fopen("output.txt", "w");
    while((p = fgets(cc, sizeof(cc), fin)) != NULL){
        maxlen = 0;
        len = 0;
        printf("ok %s", p);
        char* pch = strtok(p, " ,.\n");
        while(pch != NULL){
            printf("\n%s", pch);
            len = strlen(pch);
            if(len > maxlen){
                maxlen = len;
                word = pch;
            }
            pch = strtok(NULL, " ,.");
    }
    fprintf(fout, "%s\n", word);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}