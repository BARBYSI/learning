#include <stdio.h>
#include <ctype.h>
static char* max_word(char* s);
void out_max_words(FILE* _out, FILE* _in);

int main(void){
    FILE* fin  = fopen("input.txt",  "r");
    FILE* fout = fopen("output.txt", "w");
    out_max_words(fout, fin);
    fclose(fin);
    fclose(fout);

    return 0;
}

void out_max_words(FILE* _out, FILE* _in){
    char* p, buf[512];
    while((p = fgets(buf, sizeof(buf), _in)) != NULL){
        p = max_word(p);
        if(p != NULL)
            fprintf(_out, "%s\n", p);
    }
}

//����� ������� �����
static char* max_word(char* s){
    int   k = 0, n = 0;
    char* p = NULL;
    do {
        if(isalnum(*s) || (*s == '_'))
            ++k;
        else if(k > 0){
            if(k > n){
                p = s - k;
                n = k;
            }
            k = 0;
        }
    } while(*s++ != '\0');

    if(p != NULL)
        *(p + n) = '\0';
    return p;
}
