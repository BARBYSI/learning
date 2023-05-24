#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHRASE_LEN 100
#define MAX_FILE_SIZE 1000000

char**  get_phrases(char* text) {
    char** phrases = malloc(sizeof(char*) * MAX_PHRASE_LEN);
    int phrase_count = 0;
    char* phrase_start = text;
    int phrase_len = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '.') {
            if (phrase_count >= MAX_PHRASE_LEN) {
                printf("Too many phrases in text.\n");
                return NULL;
            }
            phrases[phrase_count] = malloc(sizeof(char) * (phrase_len + 2));
            strncpy(phrases[phrase_count], phrase_start, phrase_len + 1);
            phrases[phrase_count][phrase_len + 1] = '\0';
            phrase_start = &text[i+1];
            phrase_len = 0;
            phrase_count++;
        }
        else {
            phrase_len++;
        }
    }

    return phrases;
}
char *longest_word(char *phrase)
{
    char *longest = NULL;
    int max_len = 0;
    char *word = strtok(phrase, " ."); // Split phrase by space and period

    while (word != NULL)
    {
        int len = strlen(word);
        if (len > max_len)
        {
            longest = word;
            max_len = len;
        }
        word = strtok(NULL, " .");
    }

    return longest;
}


int main() {
    // Open the file
    FILE *file = fopen("phrases", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Allocate a buffer to store the file contents
    char *buffer = malloc(MAX_FILE_SIZE);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Read the file contents into the buffer
    size_t num_bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file);
    if (ferror(file)) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return EXIT_FAILURE;
    }

    // Close the file
    fclose(file);

    // Print the file contents
    printf("%s", buffer);

    char* phrases[MAX_PHRASE_LEN] = { NULL };
    int num_phrases = 0;
    char* phrase = strtok(buffer, ".");
    while (phrase != NULL) {
        phrases[num_phrases++] = phrase;
        phrase = strtok(NULL, ".");
    }

    char* longest_words[MAX_PHRASE_LEN] = { NULL };
    for (int i = 0; i < num_phrases; i++) {
        char* phrase = phrases[i];
        int phrase_len = strlen(phrase);

        char* longest = phrase;
        int longest_len = 0;

        int word_start = -1;
        for (int j = 0; j <= phrase_len; j++) {
            if (j == phrase_len || phrase[j] == ' ') {
                int word_len = j - word_start;
                if (word_len > longest_len) {
                    longest = phrase + word_start;
                    longest_len = word_len;
                }
                word_start = -1;
            } else if (word_start == -1) {
                word_start = j;
            }
        }

        longest_words[i] = malloc(longest_len + 1);
        strncpy(longest_words[i], longest, longest_len);
        longest_words[i][longest_len] = '\0';
    }

    FILE *file1 = fopen("phrases2", "wb");
    if (file1 == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Write the contents of the array to the file
    for (int i = 0; i < num_phrases; i++) {
        fprintf(file1, "%s\n", longest_words[i]);
    }

    // Close the file
    fclose(file1);

    // Free memory
    free(buffer);
    for (int i = 0; i < num_phrases; i++) {
        free(longest_words[i]);
    }

    return EXIT_SUCCESS;
}