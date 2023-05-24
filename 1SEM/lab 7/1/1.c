#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Failed to open input file '%s'.\n", argv[1]);
        return 1;
    }

    FILE* output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Failed to open output file '%s'.\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    rewind(input_file);

    char* input_buffer = (char*)malloc(input_file_size);
    if (input_buffer == NULL) {
        printf("Failed to allocate memory for input buffer.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    size_t bytes_read = fread(input_buffer, 1, input_file_size, input_file);
    if (bytes_read != input_file_size) {
        printf("Failed to read input file '%s'.\n", argv[1]);
        free(input_buffer);
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    char* input_buffer_end = input_buffer + input_file_size;
    char* input_ptr = input_buffer;
    while (input_ptr < input_buffer_end) {
        char* end_ptr = input_ptr;
        while (end_ptr < input_buffer_end && *end_ptr != '\n') {
            end_ptr++;
        }
        size_t phrase_size = end_ptr - input_ptr;

        char* phrase_buffer = (char*)malloc(phrase_size + 1);
        if (phrase_buffer == NULL) {
            printf("Failed to allocate memory for phrase buffer.\n");
            free(input_buffer);
            fclose(input_file);
            fclose(output_file);
            return 1;
        }

        memcpy(phrase_buffer, input_ptr, phrase_size);
        phrase_buffer[phrase_size] = '\0';

        char* longest_word = NULL;
        char* word = strtok(phrase_buffer, " ");
        while (word != NULL) {
            size_t word_len = strlen(word);
            if (longest_word == NULL || word_len > strlen(longest_word)) {
                longest_word = word;
            }
            word = strtok(NULL, " ");
        }

        if (longest_word != NULL) {
            fwrite(longest_word, 1, strlen(longest_word), output_file);
            fwrite("\n", 1, 1, output_file);
        }

        free(phrase_buffer);

        input_ptr = end_ptr + 1;
    }

    free(input_buffer);
    fclose(input_file);
    fclose(output_file);
