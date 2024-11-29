#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the text using Caesar cipher
void caesar_cipher(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Check if the character is an uppercase letter
        if (isupper(ch)) {
            text[i] = ((ch - 'A' + shift) % 26) + 'A';
        }
        // Check if the character is a lowercase letter
        else if (islower(ch)) {
            text[i] = ((ch - 'a' + shift) % 26) + 'a';
        }
    }
}

int main(int argc, const char *argv[]) {
    // Check for correct number of arguments
    if (argc < 3) {
        printf("Usage: %s <text> <shift>\n", argv[0]);
        return 1;
    }

    // Allocate memory for the text
    size_t len = 0;
    for (int i = 1; i < argc - 1; i++) {
        len += strlen(argv[i]) + 1;  
    }

    char *text = malloc(len + 1);  
    if (!text) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Concatenate all arguments except the last one (the shift value)
    text[0] = '\0';
    for (int i = 1; i < argc - 1; i++) {
        strcat(text, argv[i]);
        if (i < argc - 2) {
            strcat(text, " ");  
        }
    }

    // Get the shift value
    char *endptr;
    int shift = strtol(argv[argc - 1], &endptr, 10);

    if (*endptr != '\0') {
        printf("Error: Invalid shift value\n");
        free(text);
        return 1;
    }

    // Handle negative shifts by converting them to equivalent positive shifts
    shift = (shift % 26 + 26) % 26;

    // Encrypt the text using the Caesar cipher
    caesar_cipher(text, shift);

    printf("Encrypted text: %s\n", text);

    free(text);

    return 0;
}
