#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int isOdd(int num);

int main() {
    char str[MAX_LEN];
    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = 0; // Removing newline character from input string
    char newStr[MAX_LEN] = "";
    char *token = strtok(str, " ");
    while (token != NULL) {
        if (!isOdd(strlen(token))) {
            strcat(newStr, token);
            strcat(newStr, " ");
        }
        token = strtok(NULL, " ");
    }
    printf("New string: %s\n", newStr);
    return 0;
}

int isOdd(int num) {
    return num % 2 != 0;
}
