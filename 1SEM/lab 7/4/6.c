#include <stdio.h>
#include <string.h>



void main() {
FILE *file;
char id[500], to[500], time[500], price[500], seats[500];
    printf("ID - ");
    char num[500];
    scanf("%s", &num);
    file = fopen("tickets", "r+b");
    fread(&id, sizeof(id), 1, file);
    printf("id %s\n", id);
    fread(&to, sizeof(to), 1, file);
    printf("to %s\n", to);
    fread(&time, sizeof(time), 1, file);
    printf("time %s\n", time);
    fread(&price, sizeof(price), 1, file);
    printf("price %s\n", price);
    int res = fread(&seats, sizeof(seats), 1, file);
    printf("seats %s\n", seats);
    long counter = 0;
    int check = 0;
    while (res!=0){
        counter += 5;
        // if (strcmp(num, id) == 0) {check++; break;}
        res = fread(&id, sizeof(id), 1, file);
        if(strcmp(num, id) == 0) {
            break;
        }
        printf("id %s\n", id);
        fread(&to, sizeof(to), 1, file);
        printf("to %s\n", to);
        fread(&time, sizeof(time), 1, file);
        printf("time %s\n", time);
        fread(&price, sizeof(price), 1, file);
        printf("price %s\n", price);
        fread(&seats, sizeof(seats), 1, file);
        printf("seats %s\n", seats);
    }
    fseek(file, 1, SEEK_CUR);
    fread(&to, sizeof(to), 1, file);
    printf("to %s\n", to);
    fread(&time, sizeof(time), 1, file);
    printf("time %s\n", time);
    fread(&price, sizeof(price), 1, file);
    printf("price %s\n", price);
    fread(&seats, sizeof(seats), 1, file);
    printf("seats %s\n", seats);
}  