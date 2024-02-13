#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 21

unsigned short permsS, p = 1, letters = 0;
char **perms, **permsPtr;
char c;

void swap(char *c1, char *c2) {
    char tmp = *c2;
    *c2 = *c1;
    *c1 = tmp;
}

void fillPermutations(unsigned short i) {
    if (i == letters)
        return;

    printf("\nSees %s\n", &((*permsPtr)[i]));

    char *refWord = *permsPtr, *permPtr = &(refWord[i]);

    do {
        printf("%s ", refWord);
        *(++permsPtr) = malloc(sizeof(char) * letters);
        strcpy(*permsPtr, refWord);
        fillPermutations(i + 1);
        swap(++permPtr, refWord);
    } while (*(permPtr) != '\0');

    // permsPtr
    // shuffle, give pointer to new one which will be overwritten, return where to continue writing
    // each makes sure to provide each shuffle of its letter
}

void freePerms() {
    char **c = perms;
    while (c < perms + permsS && *c != NULL) {
        printf("Freed \"%s\"\n", *c);
        free(*(c++));
    }

    free(perms);
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

    permsS = p * sizeof(char *);
    perms = permsPtr = malloc(permsS);
    *permsPtr = malloc(sizeof(char) * letters);
    strcpy(*permsPtr, argc[1]);

    fillPermutations(0);

    printf("%d", p);
    for (int i = 0; i < p; i++)
        printf("%d: %s\n", i, perms[i]);

    freePerms();
}