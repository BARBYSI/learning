#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char filename [32];

struct flight
{
    int id;
    char destination[16];
    char time[16];
    int price;
    int seats;
};

void add(){
    FILE* fp = fopen(filename, "rb+");
    struct flight f;
    printf("Input flight's ID: \n");
    scanf("%d", &f.id);
    struct flight tmp;
    rewind(fp);
    while (fread(&tmp, sizeof(struct flight), 1, fp)) {
        if (tmp.id == f.id) {
            printf("Flight with this ID already exists!\n");
            return;
        }
    }
    printf("Enter the destination point: ");
    scanf("%s", &f.destination);
    printf("Enter the departure time: ");
    scanf("%s", &f.time);
    printf("Enter the price: ");
    scanf("%d", &f.price);
    printf("Enter the amount of seats left: ");
    scanf("%d", &f.seats);
    fseek(fp, 0, SEEK_END);
    fwrite(&f, sizeof(struct flight), 1, fp);
    printf("Flight has been added!\n");
    printf("id: %d\ndestionation: %s\ndeparture time: %s\nprice: %d\nseats left: %d\n");
    
    fclose(fp);
}

void update() {
    FILE* fp = fopen(filename, "rb+");
    int id, found = 0;
    printf("Input flight's ID: ");
    scanf("%d", &id);
    struct flight f;
    while (fread(&f, sizeof(struct flight), 1, fp)) {
        if (f.id == id) {
            found = 1;
            printf("Enter flight details: \n");
            printf("Destination point: ");
            scanf("%s", f.destination);
            printf("Time: ");
            scanf("%s", &f.time);
            printf("Ticket price: ");
            scanf("%d", &f.price);
            printf("Seats available: ");
            scanf("%d", &f.seats);
            fseek(fp, ftell(fp) - sizeof(struct flight), SEEK_SET);
            fwrite(&f, sizeof(struct flight), 1, fp);
            break;
        }
    }
    fclose(fp);
    if (!found) {
        printf("Flight with ID %d not found.\n", id);
    }
}

void buy(){
    FILE* fp = fopen(filename, "rb+");
    int id;
    printf("Input flight's ID: ");
    scanf("%d", &id);
    struct flight f;
    while (fread(&f, sizeof(struct flight), 1, fp)) {
        if (f.id == id) {
            if (f.seats > 0) {
                long int pos = ftell(fp) - sizeof(struct flight);
                fseek(fp, pos, SEEK_SET);
                f.seats--;
                fwrite(&f, sizeof(struct flight), 1, fp);
                fseek(fp, pos, SEEK_SET);
                printf("Ticket has been bought successfully!\n");
            } else {
                printf("No available seats!\n");
            }
            fclose(fp);
            return;
        }
    }
    printf("Flight with this ID does not exist!\n");
    fclose(fp);
}

void delete() {
    FILE* fp = fopen(filename, "rb");
    FILE* tmpfp = fopen("tmp.bin", "wb");
    int id;
    printf("Input flight's ID: ");
    scanf("%d", &id);
    struct flight f;
    while (fread(&f, sizeof(struct flight), 1, fp)) {
        if (f.id == id) {
            printf("Flight with id %d has been deleted.\n", id);
            continue;
        }
        fwrite(&f, sizeof(struct flight), 1, tmpfp);
    }
    fclose(fp);
    fclose(tmpfp);
    remove(filename);
    rename("tmp.bin", filename);
}

void print_flight_by_id() {
    FILE* fp = fopen(filename, "rb");
    int id;
    printf("Input flight's ID: ");
    scanf("%d", &id);
    struct flight f;
    int found = 0;
    while (fread(&f, sizeof(struct flight), 1, fp)) {
        if (f.id == id) {
            printf("id: %d\n", f.id);
            printf("destination point: %s\n", f.destination);
            printf("time: %s\n", f.time);
            printf("ticket price: %d\n", f.price);
            printf("seats available: %d\n\n", f.seats);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found) {
        printf("Flight with id %d not found.\n", id);
    }
}

void print_all_flights() {
    FILE* fp = fopen(filename, "rb");
    rewind(fp);
    struct flight f;
    while (fread(&f, sizeof(struct flight), 1, fp)) {
        printf("id: %d\n", f.id);
        printf("destination point: %s\n", f.destination);
        printf("time: %s\n", f.time);
        printf("ticket price: %d\n", f.price);
        printf("seats available: %d\n\n", f.seats);
    }
    fclose(fp);
}

int menu(){
    int user_choice;
    printf("Print the number: \n\n1. Add flight\n2. Update flight\n3. Delete flight\n4. Show Flight\n5. Show all flights\n6. Buy ticket\n7. Exit\n\n");
    scanf("%d", &user_choice);

    switch (user_choice)
    {
    case 1:
        add();
        break;
    case 2:
        update();
        break;
    case 3:
        delete();
        break;
    case 4:
        print_flight_by_id();
        break;
    case 5:
        print_all_flights();
        break;
    case 6:
        buy();
        break;
    case 7:
        exit(1);
    default:
        printf("Unknown command!\n\nEnter a number between 1 and 5\n");
        break;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc == 2) strcpy(filename, argv[1]);
    else {
        printf("Input file name! - ");
        scanf("%s", &filename);
    }
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fp = fopen(filename, "wb");
        if (fp == NULL) {
            printf("Failed to create file.\n");
            exit(1);
        }
        printf("File %s created.\n", filename);
    } else {
        printf("File %s found.\n", filename);
    }
    fclose(fp);
    while (menu(fp) != 0) {
        menu(fp);
    }
}