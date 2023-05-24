#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *text = "3 -5 6 9 2 0 12 -2 0";

    // Открыть бинарный файл для записи
    FILE *file = fopen("phrases", "wb");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Записать содержимое переменной text в файл
    size_t bytes_written = fwrite(text, sizeof(char), strlen(text), file);
    if (bytes_written != strlen(text)) {
        perror("Error writing to file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Закрыть файл
    fclose(file);

    return EXIT_SUCCESS;
}