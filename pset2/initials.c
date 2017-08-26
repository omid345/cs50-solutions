#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    printf("Name: ");
    string name = get_string();
    int length = strlen(name);
    char initials[length];
    initials[0] = toupper(name[0]);

    for (int i = 1, j = 1; i < length; i++) {
        if (name[i-1] == ' ') {
            initials[j] = toupper(name[i]);
            j++;
        }
    }

    printf("%s\n", initials);
    return 0;
}