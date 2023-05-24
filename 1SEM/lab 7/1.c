#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

// int longestWord(char* s){
//     char* longest_word = NULL;
//     char *word = strtok(s, " ,.!?");
//     int len, maxlen;
//     while(word != NULL) {
//         len = strlen(word);
//         printf("len = %d\n", len);
//         if(len > maxlen){
//             maxlen = len;
//             printf("maxlen = %d\n", maxlen);
//         }
//         word = strtok(NULL, " ,.!?");
//     }
//     printf("maxlen = %d\n", maxlen);
//     return maxlen;
// }

static char* phrase(char* s){
    int k = 0, n = 0;
    char* lp;
    do{
        if(isalnum(*s)){
            k++;
            printf("%d\n", k);
        }
        if(k > n) {
            printf("%s\n", lp);
            lp = s - k;
            printf("-- %s\n", lp);
            n = k;
        }
        k = 0;
    } while(*s++ != '\0');

    if(lp != NULL){
        *(lp + n) = '\0';
    }
    printf("nig %s nig\n", lp);
    return lp;
}   

void output(FILE* fout, FILE* fin){
    char* p, cc[256];
    while((p = fgets(cc, sizeof(cc), fin)) != NULL){
        // longestWord(p);
        printf("output func %s\n", p);
        p = phrase(p);
        if(p != NULL){
            fprintf(fout, "%s\n", p);
            printf(" end of output func %s", p);
        }
    }
}

int main(void){

    // char *locale = setlocale(LC_ALL, "");
    // char cc[256];
    FILE * fin = fopen("input.txt", "r");
    FILE * fout = fopen("output.txt", "w");
    // while((fgets(cc, 256, fin)) != NULL){
    //     fputs(cc, fout);
    //     printf("%s", cc);
    // }
    output(fout, fin);
    fclose(fin);
    fclose(fout);
    return 0;
}