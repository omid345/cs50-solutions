#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

char caesar(char character, int key);

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Usage: ./vigenere key");
        return 1;
    }

    int keylength = strlen(argv[1]);
    // yell if user doesn't give valid keyword
    for (int k = 0; k < keylength; k++)
    {
        if (!isalpha(argv[1][k]))
        {
            printf("You should provide valid keyword!\n");
            return 1;
        }
    }

    string text = get_string();
    int textLength = strlen(text);
    int key[textLength];

    for (int i = 0, j = 0; i < textLength; i++) {
        if (isalpha(text[i])) {
            key[i] = tolower(argv[1][j%keylength]) - 'a';
            j++;
            printf("%c", caesar(text[i], key[i]));
        } else {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}

char caesar(char character, int key) {
    if (isupper(character)) {
        return ((character - 'A' + key) % 26) + 'A';
    } else {
        return ((character - 'a' + key) % 26) + 'a';
    }
}