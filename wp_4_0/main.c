#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 11

// calc refPtr using letters - i

unsigned int p = 1, letters = 0;
char **perms, **permsPtr;

void swap(char *c1, char *c2) {
    char tmp = *c2;
    *c2 = *c1;
    *c1 = tmp;
}

char *dupStr(char *src) {
    char *ptr = malloc(sizeof(char) * letters);
    strcpy(ptr, src);
    return ptr;
}

void fillPermutations(unsigned int i) {
    if (i == letters - 1)
        return;

    unsigned int i2 = i + 1;

    do {
        fillPermutations(i + 1);
        *(permsPtr + 1) = dupStr(*permsPtr);
        permsPtr++;
        swap(&((*permsPtr)[i]), &((*permsPtr)[letters - 1]));
    } while (++i2 < letters);

    fillPermutations(i + 1);
}

int main(int argv, char **argc) {
    unsigned int firstArgI = 0;

    if (argv != 2) {
        printf("Invalid input, one argument expected\n");
        return 0;
    }

    do {
        p *= ++letters;

        if (++firstArgI == MAX_INPUT) {
            printf("Invalid input, 1st argument is too long\n");
            return 0;
        }
    } while (argc[1][firstArgI] != '\0');

    perms = permsPtr = malloc(p * sizeof(char *));
    *permsPtr = malloc(sizeof(char) * letters);
    strcpy(*permsPtr, argc[1]);

    fillPermutations(0);

    for (int i = 0; i < p; i++) {
        printf("%d: %s\n", i, perms[i]);
        free(perms[i]);
    }

    free(perms);
}