#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <wctype.h>

int main() {
    char *locale = setlocale(LC_ALL, "");
    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);
    // system("chcp 65001");

    // Read input string from user
    char inputString[100];
    printf("Enter input string:\n");
    fgets(inputString, 100, stdin);

    // Convert Russian letters to uppercase
    for (int i = 0; inputString[i] != '\0'; i++) {
        if (iswlower(inputString[i]) && iswalpha(inputString[i])) {
            inputString[i] = towupper(inputString[i]);
        }
    }

    // Print modified string
    printf("Modified string:\n%s", inputString);

    return 0;
}