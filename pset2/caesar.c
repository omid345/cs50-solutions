#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Usage: ./caesar k");
        return 1;
    }

    int key = atoi(argv[1]);

    printf("plaintext: ");
    string plainText = get_string();

    for (int i = 0, n = strlen(plainText); i < n; i++) {
        if (isalpha(plainText[i])) {
            if (isupper(plainText[i])) {
                printf("%c", ((plainText[i] - 'A' + key) % 26) + 'A');
            } else {
                printf("%c", ((plainText[i] - 'a' + key) % 26) + 'a');
            }
        } else {
            printf("%c", plainText[i]);
        }
    }

    printf("\n");
    return 0;
}