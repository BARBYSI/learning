#include <stdio.h>
#include <locale.h>
char stroka[1500];


int main(void){
    setlocale( LC_ALL, "ru-RU" );
    printf("Input your string - ");
    fgets(stroka, 50000, stdin);
    for (int i = 0; stroka[i] != "."[0]; i++){
        if (stroka[i] != "a"[0] && 
        stroka[i] != "a"[0] && 
        stroka[i] != "b"[0] && 
        stroka[i] != "c"[0] && 
        stroka[i] != "d"[0] && 
        stroka[i] != "e"[0] && 
        stroka[i] != "f"[0] && 
        stroka[i] != "g"[0] && 
        stroka[i] != "h"[0] && 
        stroka[i] != "i"[0] && 
        stroka[i] != "j"[0] && 
        stroka[i] != "k"[0] && 
        stroka[i] != "l"[0] && 
        stroka[i] != "m"[0] && 
        stroka[i] != "n"[0] && 
        stroka[i] != "o"[0] && 
        stroka[i] != "p"[0] && 
        stroka[i] != "q"[0] && 
        stroka[i] != "r"[0] && 
        stroka[i] != "s"[0] && 
        stroka[i] != "t"[0] && 
        stroka[i] != "u"[0] && 
        stroka[i] != "v"[0] && 
        stroka[i] != "w"[0] && 
        stroka[i] != "x"[0] && 
        stroka[i] != "y"[0] && stroka[i] != "z"[0]&& stroka[i] != " "[0]){
            else
            stroka[i] -= 32;
        }
    }
    printf("\n");
    
    puts(stroka);
    return 0;
}