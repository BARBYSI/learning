#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

char filename[500];

int noCopy(char *new_id){
    FILE *file;
    char id[500];
    file = fopen(filename, "rb");
    fread(&id, sizeof(id), 1, file);

    int check = 0;
    while (id != new_id){
        if (strcmp(new_id, id) == 0) {
            printf("this id already exists!\n");
            check++;
            break;
            }else {break;}
    } 
    if(check == 0){
        printf("test");
        return 1;
    }
    else{
        return 0;
    }
}

void print(){
    FILE *file;
    char id[500], to[500], time[500], price[500], seats[500];
    printf("ID - ");
    char num[500];
    scanf("%s", &num);
    file = fopen(filename, "rb");
    fread(&id, sizeof(id), 1, file);
    fread(&to, sizeof(to), 1, file);
    fread(&time, sizeof(time), 1, file);
    fread(&price, sizeof(price), 1, file);
    int res = fread(&seats, sizeof(seats), 1, file);
    int check = 0;
    while (res!=0){
        if (strcmp(num, id) == 0) {check++; break;}
        fread(&id, sizeof(id), 1, file);
        fread(&to, sizeof(to), 1, file);
        fread(&time, sizeof(time), 1, file);
        fread(&price, sizeof(price), 1, file);
        res = fread(&seats, sizeof(seats), 1, file);
    }
    if (check == 0) printf("NOT FOUND!\n\n");
    else printf("SUCCESS:\nID: %s\nTo: %s\nTime: %s\nPrice: %s\nSeats: %s\n\n", id, to, time, price, seats);
    fclose(file);
}

void insert(){
    FILE *file;
    char id[500], to[500], time[500], price[500], seats[500];
    printf("Id: ");
    scanf("%s", &id);
    printf("To: ");
    scanf("%s", &to);
    printf("Time: ");
    scanf("%s", &time);
    printf("Price: ");
    scanf("%s", &price);
    printf("Seats: ");
    scanf("%s", &seats);
    file = fopen(filename, "a+b");
    if(noCopy(id) == 1){
        fseek(file, 0, SEEK_END);
        fwrite(&id, sizeof(id), 1, file);
        fwrite(&to, sizeof(to), 1, file);
        fwrite(&time, sizeof(time), 1, file);
        fwrite(&price, sizeof(price), 1, file);
        fwrite(&seats, sizeof(seats), 1, file);
        fclose(file);
        printf("DONE!\n\n");
    } else {printf("Enter the unique id!\n\n");}
    
}

void delete(){
    FILE *file;
    char id[500], to[500], time[500], price[500], seats[500];
    printf("ID - ");
    char num[500];
    scanf("%s", &num);
    file = fopen(filename, "rb");
    fread(&id, sizeof(id), 1, file);
    fread(&to, sizeof(to), 1, file);
    fread(&time, sizeof(time), 1, file);
    fread(&price, sizeof(price), 1, file);
    int res = fread(&seats, sizeof(seats), 1, file);
    int count = 0;
    while (res!=0){
        count++;
        fread(&id, sizeof(id), 1, file);
        fread(&to, sizeof(to), 1, file);
        fread(&time, sizeof(time), 1, file);
        fread(&price, sizeof(price), 1, file);
        res = fread(&seats, sizeof(seats), 1, file);
    }
    if (count == 0) {printf("NOT FOUND\n\n"); return;}
    char ***arr = (char***)calloc(count, sizeof(char**));
    for (int i = 0; i<count; i++){
        arr[i] = (char**)calloc(5, sizeof(char*));
        for (int j = 0; j<5; j++) {
            
            arr[i][j] = (char*)calloc(500, sizeof(char));
            for (int k = 0; k<500; k++){
                arr[i][j][k] = "\0"[0];
            }
        }
    }
    // arr[0][1] = "adf"; arr[1][1] = "jkl";
    printf("%s\t%s\t", arr[0][1], arr[1][1]);
    fclose(file);
    file = fopen(filename, "rb");
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i<count; i++){
        //fseek(file, 0, SEEK_END);
        fread(&id, sizeof(id), 1, file);
        fread(&to, sizeof(to), 1, file);
        fread(&time, sizeof(time), 1, file);
        fread(&price, sizeof(price), 1, file);
        fread(&seats, sizeof(seats), 1, file);
        //printf("i - %d\t id - %s", i, to);
        arr[i][0] = id;
        arr[i][1] = to;
        arr[i][2] = time;
        arr[i][3] = price;
        arr[i][4] = seats;
    }    
    //printf("%s\t%s\t", arr[0][1], arr[1][1]);
    fclose(file);
}
void update(){
    FILE *file;
}

int menu(){
    int choose;
    printf("Select your point: \n\n1 - insert\n2 - update\n3 - delete\n4 - found\n5 - quit\n\n");
        scanf("%d", &choose);
        if (choose == 1) insert();
        else if (choose == 2) update();
        else if (choose == 3) delete();
        else if (choose == 4) print();
        else if (choose == 5) return 0;
        else {
            printf("UNKNOWN COMMAND!\n\n");
            return 0;
        };
    return 1;
}

void main(int argc, char* argv[]){
    if (argc == 2) strcpy(filename, argv[1]);
    else {
        printf("Input file name! - ");
        scanf("%s", &filename);
    }
    while(menu() != 0){
        menu();
    };
    
    // int choose;
    // while (1){
    //     printf("Select your point: \n\n1 - insert\n2 - update\n3 - delete\n4 - found\n5 - quit\n\n");
    //     scanf("%d", &choose);
    //     if (choose == 1) insert();
    //     else if (choose == 2) update();
    //     else if (choose == 3) delete();
    //     else if (choose == 4) print();
    //     else if (choose == 5) break;
    //     else printf("UNKNOWN COMMAND!\n\n");
    // }   
}