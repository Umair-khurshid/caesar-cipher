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

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <text> <shift>\n", argv[0]);
        return 1;
    }

    // Get the text and shift amount from the command-line arguments
    char *text = argv[1];
    int shift = atoi(argv[2]);

    // Handle negative shifts by converting them to equivalent positive shifts
    if (shift < 0) {
        shift = (shift % 26) + 26;
    }

    // Encrypt the text using the Caesar cipher
    caesar_cipher(text, shift);

    // Output the encrypted text
    printf("Encrypted text: %s\n", text);

    return 0;
}
